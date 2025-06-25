/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_set_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:04:19 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/25 20:52:51 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"
#include "rt_utils.h"

t_point	rt_set_coordinate(char *param)
{
	char 	**split;
	int		split_len;
	t_point	coordinate;

	split = ft_split(param, ',');
	if (!split)
		exit(rt_print_err_msg("split failure."));
	split_len = 0;
	while (split[split_len])
		split_len++;
	if (split_len != 3)
		exit(rt_print_err_msg("invalid coordinate."));
	coordinate.x = rt_strtod(split[0]);
	coordinate.y = rt_strtod(split[1]);
	coordinate.z = rt_strtod(split[2]);
	rt_free_split(split);
	return (coordinate);
}

t_vec	rt_set_vector(char *param)
{
	char 	**split;
	int		split_len;
	t_vec	vector;

	split = ft_split(param, ',');
	if (!split)
		exit(rt_print_err_msg("split failure."));
	split_len = 0;
	while (split[split_len])
		split_len++;
	if (split_len != 3)
		exit(rt_print_err_msg("invalid vector."));
	vector.x = rt_strtod(split[0]);
	vector.y = rt_strtod(split[1]);
	vector.z = rt_strtod(split[2]);
	rt_free_split(split);
	return (vector);
}

t_color	rt_set_color(char *value)
{
	char 	**split;
	int		split_len;
	t_color	color;

	split = ft_split(value, ',');
	if (!split)
		exit(rt_print_err_msg("split failure."));
	split_len = 0;
	while (split[split_len])
		split_len++;
	if (split_len != 3)
		exit(rt_print_err_msg("invalid color."));
	color.r = rt_strtod(split[0]);
	color.g = rt_strtod(split[1]);
	color.b = rt_strtod(split[2]);
	rt_free_split(split);
	return (color);
}
