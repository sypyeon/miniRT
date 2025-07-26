/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 01:55:41 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/26 22:15:58 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

static _Bool	check_cylinder_height(t_obj *cy, t_ray *ray, double t)
{
	t_vec	axis;
	t_point	hit_point;
	double	projection;

	axis = vunit(cy->data.cy.norm);
	hit_point = ray_at(ray, t);
	projection = vdot(vminus(hit_point, cy->origin), axis);
	if (projection < -cy->data.cy.height / 2.0)
		return (0);
	if (projection > cy->data.cy.height / 2.0)
		return (0);
	return (1);
}

static _Bool	record_cylinder_hit(t_obj *cy, t_ray *ray, t_hit_record *rec,
	double t)
{
	t_vec	axis;
	t_point	hit_point;
	double	projection;
	t_point	axis_point;

	axis = vunit(cy->data.cy.norm);
	hit_point = ray_at(ray, t);
	projection = vdot(vminus(hit_point, cy->origin), axis);
	axis_point = vplus(cy->origin, vscale(axis, projection));
	rec->t = t;
	rec->p = hit_point;
	rec->norm = vunit(vminus(hit_point, axis_point));
	rec->albedo = cy->color;
	set_face_normal(ray, rec);
	return (1);
}

_Bool	test_single_root(t_obj *cy, t_ray *ray, t_hit_record *rec,
	double t)
{
	if (t < rec->tmin || t > rec->tmax)
		return (0);
	if (!check_cylinder_height(cy, ray, t))
		return (0);
	return (record_cylinder_hit(cy, ray, rec, t));
}
