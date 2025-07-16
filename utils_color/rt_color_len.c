/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:23:20 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 16:23:24 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_color.h"


double	rt_color_len_sq(t_color color)
{
	return (color.r * color.r + color.g * color.g + color.b * color.b);
}

double	rt_color_len(t_color color)
{
	return (sqrt(rt_color_len_sq(color)));
}
