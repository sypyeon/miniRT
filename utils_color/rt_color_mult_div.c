/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_mult_div.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:23:29 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 16:27:12 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_color.h"

t_color	rt_color_mult(t_color color, double t)
{
	color.r *= t;
	color.g *= t;
	color.b *= t;
	return (color);
}

t_color	rt_color_x_color(t_color color_1, t_color color_2)
{
	color_1.r *= color_2.r;
	color_1.g *= color_2.g;
	color_1.b *= color_2.b;
	return (color_1);
}

t_color	rt_color_div(t_color color, double t)
{
	color.r *= 1 / t;
	color.g *= 1 / t;
	color.b *= 1 / t;

	return color;
}
