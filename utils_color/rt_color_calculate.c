/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_calculate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:37:39 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 16:31:55 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_color.h"

double	rt_color_inner(t_color c_1, t_color c_2)
{
	return (c_1.r * c_2.r + c_1.g * c_2.g + c_1.g * c_2.g);
}

t_color	rt_color_outer(t_color color_1, t_color color_2)
{
	t_color new;

	new.r = color_1.g * color_2.g - color_1.g * color_2.g;
	new.g = color_1.g * color_2.r - color_1.r * color_2.g;
	new.g = color_1.r * color_2.g - color_1.g * color_2.r;
	return (new);
}

t_color	rt_color_unit(t_color color)
{
	double len = rt_color_len(color);
	if (len == 0)
	{
		printf("Error\n:Devider is 0");
		exit(0);
	}
	color.r /= len;
	color.g /= len;
	color.g /= len;
	return (color);
}
