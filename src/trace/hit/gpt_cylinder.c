/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpt_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:36:39 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/26 19:51:33 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

static _Bool	hit_cylinder_side(t_obj *cy, t_ray *ray, t_hit_record *rec);
static _Bool	hit_cylinder_caps(t_obj *cy, t_ray *ray, t_hit_record *rec);
static _Bool	solve_cylinder_equation(t_obj *cy, t_ray *ray,
					t_hit_record *rec);
static _Bool	check_cylinder_height(t_obj *cy, t_ray *ray, double t);
static _Bool	calculate_roots(t_obj *cy, t_ray *ray, t_hit_record *rec);
static double	calculate_discriminant(t_obj *cy, t_ray *ray);
static double	calculate_first_root(t_obj *cy, t_ray *ray);
static double	calculate_second_root(t_obj *cy, t_ray *ray);
static _Bool	test_single_root(t_obj *cy, t_ray *ray, t_hit_record *rec,
					double t);
static _Bool	record_cylinder_hit(t_obj *cy, t_ray *ray, t_hit_record *rec,
					double t);
static _Bool	hit_top_cap(t_obj *cy, t_ray *ray, t_hit_record *rec);
static _Bool	hit_bottom_cap(t_obj *cy, t_ray *ray, t_hit_record *rec);
static double	get_discriminant_value(t_vec ray_perp, t_vec oc_perp,
					t_obj *cy);
static double	get_first_root_value(t_vec ray_perp, t_vec oc_perp,
					double disc);
static double	get_second_root_value(t_vec ray_perp, t_vec oc_perp,
					double disc);

_Bool	hit_cylinder_gpt(t_obj *cy, t_ray *ray, t_hit_record *rec)
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

static _Bool	solve_cylinder_equation(t_obj *cy, t_ray *ray,
	t_hit_record *rec)
{
	double	discriminant;

	discriminant = calculate_discriminant(cy, ray);
	if (discriminant < 0)
		return (0);
	return (calculate_roots(cy, ray, rec));
}

static _Bool	calculate_roots(t_obj *cy, t_ray *ray, t_hit_record *rec)
{
	double	t;

	t = calculate_first_root(cy, ray);
	if (test_single_root(cy, ray, rec, t))
		return (1);
	t = calculate_second_root(cy, ray);
	return (test_single_root(cy, ray, rec, t));
}

static double	calculate_discriminant(t_obj *cy, t_ray *ray)
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
	return (get_discriminant_value(ray_perp, oc_perp, cy));
}

static double	get_discriminant_value(t_vec ray_perp, t_vec oc_perp, t_obj *cy)
{
	double	a;
	double	b;
	double	c;

	a = vdot(ray_perp, ray_perp);
	b = 2.0 * vdot(ray_perp, oc_perp);
	c = vdot(oc_perp, oc_perp) - cy->data.cy.radius * cy->data.cy.radius;
	return (b * b - 4 * a * c);
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

static double	get_first_root_value(t_vec ray_perp, t_vec oc_perp, double disc)
{
	double	a;
	double	b;

	a = vdot(ray_perp, ray_perp);
	b = 2.0 * vdot(ray_perp, oc_perp);
	return ((-b - sqrt(disc)) / (2.0 * a));
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

static double	get_second_root_value(t_vec ray_perp, t_vec oc_perp,
	double disc)
{
	double	a;
	double	b;

	a = vdot(ray_perp, ray_perp);
	b = 2.0 * vdot(ray_perp, oc_perp);
	return ((-b + sqrt(disc)) / (2.0 * a));
}

static _Bool	test_single_root(t_obj *cy, t_ray *ray, t_hit_record *rec,
	double t)
{
	if (t < rec->tmin || t > rec->tmax)
		return (0);
	if (!check_cylinder_height(cy, ray, t))
		return (0);
	return (record_cylinder_hit(cy, ray, rec, t));
}

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

static _Bool	hit_cylinder_caps(t_obj *cy, t_ray *ray, t_hit_record *rec)
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
