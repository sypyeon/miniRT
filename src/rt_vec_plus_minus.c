/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_plus_minus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:32:34 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/03 04:33:11 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_vec_utils.h"


t_vec	rt_vec_plus_vec(t_vec vec_1, t_vec vec_2)
{
	vec_1.x += vec_2.x;
	vec_1.y += vec_2.y;
	vec_1.z += vec_2.z;
	return (vec_1);
}

t_vec	rt_vec_add(t_vec vec, double x, double y, double z)
{
	vec.x += x;
	vec.y += y;
	vec.z += z;
	return (vec);
}

t_vec	rt_vec_minus_vec(t_vec vec_1, t_vec vec_2)
{
	vec_1.x -= vec_2.x;
	vec_1.y -= vec_2.y;
	vec_1.z -= vec_2.z;
	return (vec_1);
}

t_vec	rt_vec_subtract(t_vec vec, double x, double y, double z)
{
	vec.x -= x;
	vec.y -= y;
	vec.z -= z;
	return (vec);
}
