/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:11:34 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/21 01:46:28 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/parse.h"
#include <fcntl.h>

_Bool	set_amb(t_scene *info, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 3)
		return (print_err_ln("invalid ambient data"), 0);
	info->amb.ratio = ft_strtod(param[1]);
	info->amb.color = parse_color(param[2]);
	return (1);
}

_Bool	set_cam(t_scene *info, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 4)
		return (print_err_ln("invalid camera data"), 0);
	info->cam.orig = parse_coord(param[1]);
	info->cam.dir = parse_vec(param[2]);
	info->cam.fov = ft_atoi(param[3]);
	return (1);
}

_Bool	set_light(t_scene *info, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 3 && param_count != 4)
		return (print_err_ln("invalid light data"), 0);
	info->light->data.light.orig = parse_coord(param[1]);
	info->light->data.light.bright_ratio = ft_strtod(param[2]);
	info->light->color = parse_color(param[3]);
	return (1);
}

_Bool	split_identify_line(char *line, t_scene *info)
{
	_Bool	invalid;
	char	**split;

	ft_tab_to_space(line);
	split = ft_split(line, ' ');
	invalid = 1;
	if (!split)
		return (print_err_ln("Split failure."), free_split(split), 0);
	else if (!ft_strcmp(split[0], "A"))
		invalid = set_amb(info, split);
	else if (!ft_strcmp(split[0], "C"))
		invalid = set_cam(info, split);
	else if (!ft_strcmp(split[0], "L"))
		invalid = set_light(info, split);
	else if (!ft_strcmp(split[0], "sp"))
		invalid = init_obj(info, SPHERE, split);
	else if (!ft_strcmp(split[0], "pl"))
		invalid = init_obj(info, PLANE, split);
	else if (!ft_strcmp(split[0], "cy"))
		invalid = init_obj(info, CYLINDER, split);
	else
		return (print_err_ln("Unknown type."), free_split(split), 0);
	free_split(split);
	return (invalid);
}

char	*ft_strjoin_(char *s1, char *s2)
{
	size_t	total_len;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * total_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, total_len + 1);
	ft_strlcat(new_str, s2, total_len + 1);
	free(s1);
	free(s2);
	return (new_str);
}
