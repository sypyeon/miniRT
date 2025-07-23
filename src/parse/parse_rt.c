/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:04:47 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/23 12:55:29 by jaehylee         ###   ########.fr       */
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

_Bool	parse_amb(char **toks, t_obj *amb)
{
	char	*pos;

	if (split_len((const char **)toks) != 3 || ft_strcmp(toks[0], "A"))
		return (0);
	pos = NULL;
	amb->type = AMBIENT;
	amb->data.amb_ratio = ft_strtod(toks[1], &pos);
	if (toks[1] + ft_strlen(toks[1]) != pos || amb->data.amb_ratio < 0
		|| amb->data.amb_ratio > 1)
		return (0);
	amb->color = parse_vec(toks[2]);
	if (is_nanv(&amb->color) || !is_color(&amb->color))
		return (0);
	return (1);
}

static _Bool	parse_obj(char **toks, t_objs *objs)
{
	t_obj	*obj;

	if (!split_len(toks) == 0)
		return (0);
	obj = obj_to_push(objs);
	if (!obj)
		return (0);
	if (!ft_strcmp(toks[0], "A"))
		return (parse_amb(toks, obj));
	if (!ft_strcmp(toks[0], "C"))
		return (parse_cam(toks, obj));
	if (!ft_strcmp(toks[0], "L"))
		return (parse_light(toks, obj));
	if (!ft_strcmp(toks[0], "sp"))
		return (parse_sphere(toks, obj));
	if (!ft_strcmp(toks[0], "pl"))
		return (parse_plane(toks, obj));
	if (!ft_strcmp(toks[0], "cy"))
		return (parse_cylinder(toks, obj));
	return (0);
}

static void	set_index(t_scene *scene)
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
}

_Bool	parse_rt(t_scene *s, char *file)
{
	int		fd;
	char	*line;
	char	*ln_trim;
	char	**toks;

	if (!s || !valid_file_fmt(file))
		return (0);
	ft_bzero(&s->objs, sizeof(t_objs));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror(MINI_RT), 0);
	line = get_next_line(fd);
	while (line)
	{
		ln_trim = ft_strtrim(line, "\n");
		toks = ft_split(ln_trim, ' ');
		if (!toks)
			return (free(ln_trim), free(line), 0);
		if (!parse_obj(toks, &s->objs))
			return (free_split(toks), free(ln_trim), free(line), 0);
		(free_split(toks), free(ln_trim), free(line));
		line = get_next_line(fd);
	}
	return (set_index(s), 1);
}
