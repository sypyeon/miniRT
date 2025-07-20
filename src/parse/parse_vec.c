/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:04:19 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 06:14:11 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

t_vec	parse_vec(char *param)
{
	char	**split;
	int		split_len;
	t_vec	vector;

	vector = nan_vec();
	split = ft_split(param, ',');
	if (!split)
		return (print_err_ln("split failure."), vector);
	split_len = 0;
	while (split[split_len])
		split_len++;
	if (split_len != 3)
		return (print_err_ln("invalid vector."), free_split(split), vector);
	vector.x = ft_strtod(split[0]);
	vector.y = ft_strtod(split[1]);
	vector.z = ft_strtod(split[2]);
	free_split(split);
	return (vector);
}

t_vec	nan_vec(void)
{
	return ((t_vec){.x = NAN, .y = NAN, .z = NAN});
}
