/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:57:08 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/03 01:21:30 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"

t_vec	init_vec(double x, double y, double z)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point	init_point(double x, double y, double z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_color	init_color(double r, double g, double b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

void	set_vec(t_vec *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

double	vec_length_sq(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vec_length(t_vec vec)
{
	return (sqrt(vec_length_sq(vec)));
}

t_vec	vec_plus_vec(t_vec vec_1, t_vec vec_2)
{
	vec_1.x += vec_2.x;
	vec_1.y += vec_2.y;
	vec_1.z += vec_2.z;
	return (vec_1);
}

t_vec	vec_add(t_vec vec, double x, double y, double z)
{
	vec.x += x;
	vec.y += y;
	vec.z += z;
	return (vec);
}

t_vec	vec_minus_vec(t_vec vec_1, t_vec vec_2)
{
	vec_1.x -= vec_2.x;
	vec_1.y -= vec_2.y;
	vec_1.z -= vec_2.z;
	return (vec_1);
}

t_vec	vec_subtract(t_vec vec, double x, double y, double z)
{
	vec.x -= x;
	vec.y -= y;
	vec.z -= z;
	return (vec);
}

t_vec	vec_multiply(t_vec vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vec	vec_times_vec(t_vec vec_1, t_vec vec_2)
{
	vec_1.x *= vec_2.x;
	vec_1.y *= vec_2.y;
	vec_1.z *= vec_2.z;
	return (vec_1);
}

t_vec	vec_divide(t_vec vec, double t)
{
	vec.x *= 1 / t;
	vec.y *= 1 / t;
	vec.z *= 1 / t;

	return vec;
}

double	vec_inner_product(t_vec vec_1, t_vec vec_2)
{
	return (vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z);
}

t_vec	vec_outer_product(t_vec vec_1, t_vec vec_2)
{
	t_vec new;

	new.x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
	new.y = vec_1.z * vec_2.x - vec_1.x * vec_2.z;
	new.z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;
	return (new);
}

t_vec	vec_unit(t_vec vec)
{
	double len = vec_length(vec);
	if (len == 0)
	{
		printf("Error\n:Devider is 0");// 나중에 수정해야됨.
		exit(0);
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}

t_vec	vec_min(t_vec vec_1, t_vec vec_2)
{
	if (vec_1.x > vec_2.x)
		vec_1.x = vec_2.x;
	if (vec_1.y > vec_2.y)
		vec_1.y = vec_2.y;
	if (vec_1.z > vec_2.z)
		vec_1.z = vec_2.z;
	return (vec_1);
}
