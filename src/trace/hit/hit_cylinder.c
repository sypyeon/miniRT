/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:27:40 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/26 06:01:51 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

static _Bool	hit_cylinder3(t_obj *cy_obj, t_ray *ray, t_hit_record *rec,
	t_vec axis)
{
	t_point	bottom_center;
	double	t_bottom;
	t_point	hit_point;

	bottom_center = vminus(cy_obj->origin,
			vscale(axis, cy_obj->data.cy.height / 2.0));
	t_bottom = vdot(vminus(bottom_center, ray->orig),
			vscale(axis, -1)) / (-vdot(ray->dir, axis));
	if (t_bottom >= rec->tmin && t_bottom <= rec->tmax)
	{
		hit_point = ray_at(ray, t_bottom);
		if (vlength2(vminus(hit_point, bottom_center))
			<= pow(cy_obj->data.cy.radius, 2))
		{
			if (t_bottom < rec->tmax)
			{
				*rec = (t_hit_record){.tmax = t_bottom, .tmin = rec->tmin,
					.t = t_bottom, .p = hit_point, .norm = vscale(axis, -1),
					.albedo = cy_obj->color};
				set_face_normal(ray, rec);
				return (1);
			}
		}
	}
	return (0);
}

static _Bool	hit_cylinder4(t_obj *cy_obj, t_ray *ray, t_hit_record *rec,
	t_vec axis)
{
	t_point	top_center;
	double	t_top;
	t_point	hit_point;

	top_center = vplus(cy_obj->origin, vscale(axis,
				cy_obj->data.cy.height / 2.0));
	t_top = vdot(vminus(top_center, ray->orig), axis) / vdot(ray->dir, axis);
	if (t_top >= rec->tmin && t_top <= rec->tmax)
	{
		hit_point = ray_at(ray, t_top);
		if (vlength2(vminus(hit_point, top_center))
			<= pow(cy_obj->data.cy.radius, 2))
		{
			if (t_top < rec->tmax)
			{
				*rec = (t_hit_record){.tmax = t_top, .tmin = rec->tmin,
					.t = t_top, .p = hit_point, .norm = axis,
					.albedo = cy_obj->color};
				set_face_normal(ray, rec);
				return (1);
			}
		}
	}
	return (0);
}

static _Bool	hit_cylinder2(t_obj *cy_obj, t_ray *ray, t_hit_record *rec,
	t_vec axis)
{
	if (fabs(vdot(ray->dir, axis)) > FLT_EPSILON)
	{
		return (hit_cylinder4(cy_obj, ray, rec, axis)
			|| hit_cylinder3(cy_obj, ray, rec, axis));
	}
	return (0);
}

static _Bool	hit_cylinder5(t_obj *cy_obj, t_ray *ray, t_hit_record *rec,
	double *t_side)
{
	const t_vec	axis = vunit(cy_obj->data.cy.norm);
	const t_vec	ray_perp = vminus(ray->dir, vscale(axis, vdot(ray->dir, axis)));
	const t_vec	oc_perp = vminus(vminus(ray->orig, cy_obj->origin), vscale(axis,
				vdot(vminus(ray->orig, cy_obj->origin), axis)));
	const t_vec	abc = (t_vec){.x = vdot(ray_perp, ray_perp),
		.y = 2.0 * vdot(ray_perp, oc_perp),
		.z = vlength2(oc_perp) - cy_obj->data.cy.radius2};
	double		t1;

	t1 = (-abc.y - sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2.0 * abc.x);
	if (t1 >= rec->tmin && t1 <= rec->tmax)
	{
		if (fabs(vdot(vminus(ray_at(ray, t1), cy_obj->origin), vunit(cy_obj
						->data.cy.norm))) <= (cy_obj->data.cy.height / 2.0))
		{
			*t_side = t1;
			if (t1 < rec->tmax)
			{
				rec->tmax = t1;
				return (1);
			}
		}
	}
	return (0);
}

_Bool	hit_cylinder(t_obj *cy, t_ray *ray, t_hit_record *rec)
{
	t_vec	axis;
	double	t_side;
	_Bool	hit_found;
	t_vec	ray_perp;
	t_vec	oc_perp;

	t_side = -1;
	axis = vunit(cy->data.cy.norm);
	ray_perp = vminus(ray->dir, vscale(axis, vdot(ray->dir, axis)));
	oc_perp = vminus(vminus(ray->orig, cy->origin), vscale(axis,
				vdot(vminus(ray->orig, cy->origin), axis)));
	hit_found = hit_cylinder2(cy, ray, rec, axis);
	if ((pow(2.0 * vdot(ray_perp, oc_perp), 2) - 4 * vlength2(ray_perp)
			* (vlength2(oc_perp) - cy->data.cy.radius2)) >= 0)
		hit_found |= (hit_cylinder5(cy, ray, rec, &t_side)
				|| hit_cylinder6(cy, ray, rec, &t_side));
	if (t_side >= 0 && t_side == rec->tmax)
	{
		*rec = (t_hit_record){.t = t_side, .p = ray_at(ray, t_side),
			.norm = vunit(vminus(rec->p, vplus(cy->origin,
						vscale(axis, vdot(vminus(rec->p, cy->origin), axis))))),
			.albedo = cy->color};
		set_face_normal(ray, rec);
	}
	return (hit_found);
}
