/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:49:13 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/19 00:56:46 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

t_vec	vec3(double x, double y, double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point	point3(double x, double y, double z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_point	color3(double r, double g, double b)
{
	t_color	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

void	vset(t_vec *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

double	vlength2(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
