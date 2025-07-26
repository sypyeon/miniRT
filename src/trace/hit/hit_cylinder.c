/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:27:40 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/26 22:26:33 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

double	get_discriminant_value(t_vec ray_perp, t_vec oc_perp, t_obj *cy)
{
	double	a;
	double	b;
	double	c;

	a = vdot(ray_perp, ray_perp);
	b = 2.0 * vdot(ray_perp, oc_perp);
	c = vdot(oc_perp, oc_perp) - cy->data.cy.radius * cy->data.cy.radius;
	return (b * b - 4 * a * c);
}

static double	calculate_discriminant(t_obj *cy, t_ray *ray)
{
	t_vec	axis;
	t_vec	oc;
	t_vec	ray_perp;
	t_vec	oc_perp;

	axis = vunit(cy->data.cy.norm);
	oc = vminus(ray->orig, cy->origin);
	ray_perp = vminus(ray->dir, vscale(axis, vdot(ray->dir, axis)));
	oc_perp = vminus(oc, vscale(axis, vdot(oc, axis)));
	return (get_discriminant_value(ray_perp, oc_perp, cy));
}

static _Bool	solve_cylinder_equation(t_obj *cy, t_ray *ray,
	t_hit_record *rec)
{
	double	discriminant;

	discriminant = calculate_discriminant(cy, ray);
	if (discriminant < 0)
		return (0);
	return (calculate_roots(cy, ray, rec));
}

static _Bool	hit_cylinder_side(t_obj *cy, t_ray *ray, t_hit_record *rec)
{
	t_vec	axis;
	t_vec	oc;
	t_vec	ray_perp;
	t_vec	oc_perp;
	double	a;

	axis = vunit(cy->data.cy.norm);
	oc = vminus(ray->orig, cy->origin);
	ray_perp = vminus(ray->dir, vscale(axis, vdot(ray->dir, axis)));
	oc_perp = vminus(oc, vscale(axis, vdot(oc, axis)));
	a = vdot(ray_perp, ray_perp);
	if (a < FLT_EPSILON)
		return (0);
	return (solve_cylinder_equation(cy, ray, rec));
}

_Bool	hit_cylinder(t_obj *cy, t_ray *ray, t_hit_record *rec)
{
	t_hit_record	side_rec;
	t_hit_record	caps_rec;
	_Bool			hit_side;
	_Bool			hit_caps;

	side_rec = *rec;
	caps_rec = *rec;
	hit_side = hit_cylinder_side(cy, ray, &side_rec);
	hit_caps = hit_cylinder_caps(cy, ray, &caps_rec);
	if (hit_side && hit_caps)
	{
		if (side_rec.t < caps_rec.t)
			*rec = side_rec;
		else
			*rec = caps_rec;
		return (1);
	}
	if (hit_side)
		*rec = side_rec;
	else if (hit_caps)
		*rec = caps_rec;
	return (hit_side || hit_caps);
}
