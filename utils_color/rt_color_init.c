/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:22:53 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 16:32:05 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_color.h"

t_color	rt_init_color(double r, double g, double b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
