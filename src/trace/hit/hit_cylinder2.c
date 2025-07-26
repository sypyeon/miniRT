/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 01:55:41 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/26 19:16:05 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

_Bool	hit_cylinder6(t_obj *cy_obj, t_ray *ray, t_hit_record *rec,
	double *t_side)
{
	const t_vec	axis = vunit(cy_obj->data.cy.norm);
	const t_vec	ray_perp = vminus(ray->dir, vscale(axis, vdot(ray->dir, axis)));
	const t_vec	oc_perp = vminus(vminus(ray->orig, cy_obj->origin), vscale(axis,
				vdot(vminus(ray->orig, cy_obj->origin), axis)));
	const t_vec	abc = (t_vec){.x = vdot(ray_perp, ray_perp),
		.y = 2.0 * vdot(ray_perp, oc_perp),
		.z = vlength2(oc_perp) - cy_obj->data.cy.radius2};
	double		t2;

	t2 = (-abc.y - sqrt(abc.y * abc.y - 4 * abc.x * abc.z)) / (2.0 * abc.x);
	if (t2 >= rec->tmin && t2 <= rec->tmax && *t_side < 0
		&& fabs(vdot(vminus(ray_at(ray, t2), cy_obj->origin),
				axis)) <= cy_obj->data.cy.height / 2.0)
	{
		*t_side = t2;
		if (t2 < rec->tmax)
		{
			rec->tmax = t2;
			return (1);
		}
	}
	return (0);
}

_Bool	hit_cylinder7(t_obj *cy, t_ray *ray, t_hit_record *rec,
	double *t_side)
{
	return (hit_cylinder5(cy, ray, rec, t_side)
		|| hit_cylinder6(cy, ray, rec, t_side));
}
