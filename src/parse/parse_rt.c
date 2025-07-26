/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:04:47 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/26 23:26:35 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include <stdint.h>

static _Bool	valid_file_fmt(char *file)
{
	size_t	i;
	char	**pieces;
	_Bool	res;

	i = 0;
	if (!file || file[0] == '.' || !ft_strchr(file, '.')
		|| file[ft_strlen(file) - 1] == '.')
		return (0);
	pieces = ft_split(file, '.');
	if (!pieces)
		return (0);
	while (pieces[i])
		i++;
	if (i == 0)
		return (free_split(pieces), 0);
	res = ft_strcmp(pieces[i - 1], "rt") == 0;
	return (free_split(pieces), res);
}

static char	**get_trim_lines(int fd)
{
	char	*str;
	char	*whole;
	char	**res;

	whole = ft_strdup("");
	str = get_next_line(fd);
	if (!str)
		return (free(whole), NULL);
	while (str)
	{
		if (!ft_strcmp(str, "\n"))
			free(str);
		else
			whole = ft_strjoin_(whole, str);
		str = get_next_line(fd);
	}
	res = ft_split(whole, '\n');
	return (free(whole), res);
}

static _Bool	set_index(t_scene *scene)
{
	size_t	i;

	scene->amb = SIZE_MAX;
	scene->cam = SIZE_MAX;
	scene->light = SIZE_MAX;
	i = 0;
	while (i < scene->objs.size)
	{
		if (scene->objs.ptr[i].type == AMBIENT && scene->amb == SIZE_MAX)
			scene->amb = i;
		else if (scene->objs.ptr[i].type == CAMERA && scene->cam == SIZE_MAX)
			scene->cam = i;
		else if (scene->objs.ptr[i].type == LIGHT && scene->light == SIZE_MAX)
			scene->light = i;
		i++;
	}
	return (count_obj(&scene->objs, AMBIENT) <= 1
		&& count_obj(&scene->objs, CAMERA) == 1);
}

_Bool	parse_rt(t_scene *s, char *file)
{
	int		fd;
	char	**lines;

	if (!s || !valid_file_fmt(file))
		return (0);
	ft_bzero(&s->objs, sizeof(t_objs));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror(MINI_RT), 0);
	lines = get_trim_lines(fd);
	if (!lines)
		return (close(fd), 0);
	if (!parse_each_line(s, lines))
		return (free_split(lines), 0);
	free_split(lines);
	return (set_index(s));
}
