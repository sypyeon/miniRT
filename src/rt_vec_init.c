/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:31:14 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 16:21:37 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_vector.h"

t_vec	rt_init_vec(double x, double y, double z)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point	rt_init_point(double x, double y, double z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
