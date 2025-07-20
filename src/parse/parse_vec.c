/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:04:19 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 02:02:16 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

t_point	parse_coord(char *param)
{
	char	**split;
	int		split_len;
	t_point	coordinate;

	split = ft_split(param, ',');
	if (!split)
		return (print_err_ln("split failure."), nan_point());
	split_len = 0;
	while (split[split_len])
		split_len++;
	if (split_len != 3)
		return (print_err_ln("invalid coordinate."), nan_point());
	coordinate.x = ft_strtod(split[0]);
	coordinate.y = ft_strtod(split[1]);
	coordinate.z = ft_strtod(split[2]);
	free_split(split);
	return (coordinate);
}

t_vec	parse_vec(char *param)
{
	char	**split;
	int		split_len;
	t_vec	vector;

	split = ft_split(param, ',');
	if (!split)
		return (print_err_ln("split failure."), nan_vec());
	split_len = 0;
	while (split[split_len])
		split_len++;
	if (split_len != 3)
		return (print_err_ln("invalid vector."), nan_vec());
	vector.x = ft_strtod(split[0]);
	vector.y = ft_strtod(split[1]);
	vector.z = ft_strtod(split[2]);
	free_split(split);
	return (vector);
}

t_color	parse_color(char *value)
{
	char	**split;
	int		split_len;
	t_color	color;

	split = ft_split(value, ',');
	if (!split)
		return (print_err_ln("split failure."), nan_color());
	split_len = 0;
	while (split[split_len])
		split_len++;
	if (split_len != 3)
		return (print_err_ln("invalid color."), nan_color());
	color.x = ft_strtod(split[0]);
	color.y = ft_strtod(split[1]);
	color.z = ft_strtod(split[2]);
	free_split(split);
	return (color);
}

t_point	nan_point(void)
{
	return ((t_point){.x = NAN, .y = NAN, .z = NAN});
}

t_vec	nan_vec(void)
{
	return ((t_vec){.x = NAN, .y = NAN, .z = NAN});
}
