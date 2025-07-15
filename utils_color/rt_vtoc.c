/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vtoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:59:55 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/15 16:03:54 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_color.h"

t_color	rt_vtoc(t_vec vec)
{
	t_color color;

	color.r = vec.x;
	color.g = vec.y;
	color.b = vec.z;
	return (color);
}
