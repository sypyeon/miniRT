/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_multiply_divide.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:34:34 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/03 04:34:52 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_vec_utils.h"

t_vec	rt_vec_multiply(t_vec vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vec	rt_vec_times_vec(t_vec vec_1, t_vec vec_2)
{
	vec_1.x *= vec_2.x;
	vec_1.y *= vec_2.y;
	vec_1.z *= vec_2.z;
	return (vec_1);
}

t_vec	rt_vec_divide(t_vec vec, double t)
{
	vec.x *= 1 / t;
	vec.y *= 1 / t;
	vec.z *= 1 / t;

	return vec;
}
