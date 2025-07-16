/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_add_sum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:32:34 by sipgeon           #+#    #+#             */
/*   Updated: 2025/06/28 16:22:46 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_color.h"

t_color	rt_color_plus_color(t_color color_1, t_color color_2)
{
	color_1.r += color_2.r;
	color_1.g += color_2.g;
	color_1.b += color_2.b;
	return (color_1);
}

t_color	rt_color_add(t_color color, double r, double g, double b)
{
	color.r += r;
	color.g += g;
	color.b += b;
	return (color);
}

t_color	rt_color_minus_color(t_color color_1, t_color color_2)
{
	color_1.r -= color_2.r;
	color_1.g -= color_2.g;
	color_1.b -= color_2.b;
	return (color_1);
}

t_color	rt_color_subtract(t_color color, double r, double g, double b)
{
	color.r -= r;
	color.g -= g;
	color.b -= b;
	return (color);
}
