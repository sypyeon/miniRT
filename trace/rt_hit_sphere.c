/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:39:56 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/07 18:55:23 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_trace.h"
#include "rt_utils_vector.h"

bool	rt_hit_sphere(t_obj *sp, t_ray *ray)
{
	t_vec	oc; //방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double	a;
	double	b;
	double	c;
	double	discriminant; //판별식

	oc = rt_vec_minus_vec(ray->origin, sp->center);
	a = rt_vec_inner(ray->direction, ray->direction);
	b = 2.0 * rt_vec_inner(oc, ray->direction);
	c = rt_vec_inner(oc, oc) - sp->radius2;
	// discriminant 는 판별식
	discriminant = b * b - 4 * a * c;

	// 판별식이 0보다 크다면 광선이 구를 hit한 것!
	return (discriminant > 0);
}