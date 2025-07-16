/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:57:08 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 16:33:18 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_color.h"

t_color	rt_color_min(t_color color_1, t_color color_2)
{
	if (color_1.r > color_2.r)
		color_1.r = color_2.r;
	if (color_1.g > color_2.g)
		color_1.g = color_2.g;
	if (color_1.b > color_2.b)
		color_1.b = color_2.b;
	return (color_1);
}
