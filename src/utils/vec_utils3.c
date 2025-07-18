/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 00:59:27 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/19 01:29:09 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

t_vec	vmult(t_vec vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vec	vmult_(t_vec vec, t_vec vec2)
{
	vec.x *= vec2.x;
	vec.y *= vec2.y;
	vec.z *= vec2.z;
	return (vec);
}

t_vec	vdivide(t_vec vec, double t)
{
	vec.x *= 1 / t;
	vec.y *= 1 / t;
	vec.z *= 1 / t;
	return (vec);
}

double	vdot(t_vec vec, t_vec vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

t_vec	vcross(t_vec vec, t_vec vec2)
{
	t_vec	new;

	new.x = vec.y * vec2.z - vec.z * vec2.y;
	new.y = vec.z * vec2.x - vec.x * vec2.z;
	new.z = vec.x * vec2.y - vec.y * vec2.x;
	return (new);
}
