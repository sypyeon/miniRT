/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:24:29 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/26 22:27:07 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

static double	get_first_root_value(t_vec ray_perp, t_vec oc_perp, double disc)
{
	double	a;
	double	b;

	a = vdot(ray_perp, ray_perp);
	b = 2.0 * vdot(ray_perp, oc_perp);
	return ((-b - sqrt(disc)) / (2.0 * a));
}

static double	calculate_first_root(t_obj *cy, t_ray *ray)
{
	t_vec	axis;
	t_vec	oc;
	t_vec	ray_perp;
	t_vec	oc_perp;
	double	discriminant;

	axis = vunit(cy->data.cy.norm);
	oc = vminus(ray->orig, cy->origin);
	ray_perp = vminus(ray->dir, vscale(axis, vdot(ray->dir, axis)));
	oc_perp = vminus(oc, vscale(axis, vdot(oc, axis)));
	discriminant = get_discriminant_value(ray_perp, oc_perp, cy);
	return (get_first_root_value(ray_perp, oc_perp, discriminant));
}

static double	get_second_root_value(t_vec ray_perp, t_vec oc_perp,
	double disc)
{
	double	a;
	double	b;

	a = vdot(ray_perp, ray_perp);
	b = 2.0 * vdot(ray_perp, oc_perp);
	return ((-b + sqrt(disc)) / (2.0 * a));
}

static double	calculate_second_root(t_obj *cy, t_ray *ray)
{
	t_vec	axis;
	t_vec	oc;
	t_vec	ray_perp;
	t_vec	oc_perp;
	double	discriminant;

	axis = vunit(cy->data.cy.norm);
	oc = vminus(ray->orig, cy->origin);
	ray_perp = vminus(ray->dir, vscale(axis, vdot(ray->dir, axis)));
	oc_perp = vminus(oc, vscale(axis, vdot(oc, axis)));
	discriminant = get_discriminant_value(ray_perp, oc_perp, cy);
	return (get_second_root_value(ray_perp, oc_perp, discriminant));
}

_Bool	calculate_roots(t_obj *cy, t_ray *ray, t_hit_record *rec)
{
	double	t;

	t = calculate_first_root(cy, ray);
	if (test_single_root(cy, ray, rec, t))
		return (1);
	t = calculate_second_root(cy, ray);
	return (test_single_root(cy, ray, rec, t));
}
