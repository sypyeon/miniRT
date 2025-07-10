/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:39:56 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/10 21:49:29 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_trace.h"
#include "rt_utils_vector.h"

double	rt_hit_sphere(t_obj *sp, t_ray *ray)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = rt_vec_minus_vec(ray->origin, sp->center);
	a = rt_vec_inner(ray->direction, ray->direction);
	b = 2.0 * rt_vec_inner(oc, ray->direction);
	c = rt_vec_inner(oc, oc) - sp->radius2;
	discriminant = b * b - 4 * a * c;
	if (discriminant <= 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}