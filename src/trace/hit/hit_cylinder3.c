/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:18:20 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/26 22:19:28 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

static _Bool	hit_top_cap(t_obj *cy, t_ray *ray, t_hit_record *rec)
{
	t_vec	axis;
	t_point	cap_center;
	double	t_cap;
	t_point	hit_point;
	double	distance_sq;

	axis = vunit(cy->data.cy.norm);
	cap_center = vplus(cy->origin, vscale(axis, cy->data.cy.height / 2.0));
	t_cap = vdot(vminus(cap_center, ray->orig), axis) / vdot(ray->dir, axis);
	if (t_cap < rec->tmin || t_cap > rec->tmax)
		return (0);
	hit_point = ray_at(ray, t_cap);
	distance_sq = vlength2(vminus(hit_point, cap_center));
	if (distance_sq > cy->data.cy.radius * cy->data.cy.radius)
		return (0);
	rec->t = t_cap;
	rec->p = hit_point;
	rec->norm = axis;
	rec->albedo = cy->color;
	set_face_normal(ray, rec);
	return (1);
}

static _Bool	hit_bottom_cap(t_obj *cy, t_ray *ray, t_hit_record *rec)
{
	t_vec	axis;
	t_point	cap_center;
	double	t_cap;
	t_point	hit_point;
	double	distance_sq;

	axis = vunit(cy->data.cy.norm);
	cap_center = vminus(cy->origin, vscale(axis, cy->data.cy.height / 2.0));
	t_cap = vdot(vminus(cap_center, ray->orig), vscale(axis, -1))
		/ vdot(ray->dir, vscale(axis, -1));
	if (t_cap < rec->tmin || t_cap > rec->tmax)
		return (0);
	hit_point = ray_at(ray, t_cap);
	distance_sq = vlength2(vminus(hit_point, cap_center));
	if (distance_sq > cy->data.cy.radius * cy->data.cy.radius)
		return (0);
	rec->t = t_cap;
	rec->p = hit_point;
	rec->norm = vscale(axis, -1);
	rec->albedo = cy->color;
	set_face_normal(ray, rec);
	return (1);
}

_Bool	hit_cylinder_caps(t_obj *cy, t_ray *ray, t_hit_record *rec)
{
	t_vec			axis;
	double			denom;
	t_hit_record	top_rec;
	t_hit_record	bot_rec;
	_Bool			hit_any;

	axis = vunit(cy->data.cy.norm);
	denom = vdot(ray->dir, axis);
	if (fabs(denom) <= FLT_EPSILON)
		return (0);
	top_rec = *rec;
	bot_rec = *rec;
	hit_any = 0;
	if (hit_top_cap(cy, ray, &top_rec))
		hit_any = 1;
	if (hit_bottom_cap(cy, ray, &bot_rec))
	{
		if (!hit_any || bot_rec.t < top_rec.t)
			top_rec = bot_rec;
		hit_any = 1;
	}
	if (hit_any)
		*rec = top_rec;
	return (hit_any);
}
