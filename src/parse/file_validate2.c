/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:11:34 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/18 22:15:31 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/parse.h"
#include <fcntl.h>

int	rt_set_ambient(t_rt_info *info, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 3)
		return (rt_print_err_msg("invalid ambient data"));
	info->amb.amb_ratio = rt_strtod(param[1]);
	info->amb.color = rt_parse_color(param[2]);
	return (0);
}

int	rt_set_camera(t_rt_info *info, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 4)
		return (rt_print_err_msg("invalid camera data"));
	info->cam.origin = rt_parse_coordinate(param[1]);
	info->cam.direction = rt_parse_vector(param[2]);
	info->cam.fov = ft_atoi(param[3]);
	return (0);
}

int	rt_set_light(t_rt_info *info, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 3 && param_count != 4)
		return (rt_print_err_msg("invalid light data"));
	info->light.origin = rt_parse_coordinate(param[1]);
	info->light.bright = rt_strtod(param[2]);
	info->light.color = rt_parse_color(param[3]);
	return (0);
}

t_bool	rt_split_and_identify_line(char *line, t_rt_info *info)
{
	t_bool	invalid;
	char	**split;

	rt_tab_to_space(line);
	split = ft_split(line, ' ');
	invalid = 1;
	if (!split)
		invalid = rt_print_err_msg("Split failure.");
	else if (!rt_strcmp(split[0], "A"))
		invalid = rt_set_ambient(info, split);
	else if (!rt_strcmp(split[0], "C"))
		invalid = rt_set_camera(info, split);
	else if (!rt_strcmp(split[0], "L"))
		invalid = rt_set_light(info, split);
	else if (!rt_strcmp(split[0], "sp"))
		invalid = rt_init_object(info, SPHERE, split, rt_init_color(1, 1, 1));
	else if (!rt_strcmp(split[0], "pl"))
		invalid = rt_init_object(info, PLANE, split, rt_init_color(1, 1, 1));
	else if (!rt_strcmp(split[0], "cy"))
		invalid = rt_init_object(info, CYLINDER, split, rt_init_color(1, 1, 1));
	else
		invalid = rt_print_err_msg("Unknown type.");
	rt_free_split(split);
	return (invalid);
}

char	*rt_strjoin_and_free(char *s1, char *s2)
{
	size_t	total_len;
	char	*new_string;

	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)malloc(sizeof(char) * total_len + 1);
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, total_len + 1);
	ft_strlcat(new_string, s2, total_len + 1);
	free(s1);
	free(s2);
	return (new_string);
}
