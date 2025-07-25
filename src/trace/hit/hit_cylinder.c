/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:27:40 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/25 22:15:57 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

_Bool	hit_cylinder(t_obj *cy_obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_vec		oc, axis;
	double		a, b, c, discriminant;
	double		t1, t2, t_side = -1;
	double		projection;
	t_point		hit_point;
	_Bool		hit_found = 0;
	double		closest_t = rec->tmax;

	cy = &cy_obj->data.cy;
	axis = vunit(cy->norm);
	oc = vminus(ray->orig, cy_obj->origin);

	// 1. 측면 교차 계산
	t_vec ray_perp = vminus(ray->dir, vscale(axis, vdot(ray->dir, axis)));
	t_vec oc_perp = vminus(oc, vscale(axis, vdot(oc, axis)));

	a = vdot(ray_perp, ray_perp);
	b = 2.0 * vdot(ray_perp, oc_perp);
	c = vdot(oc_perp, oc_perp) - cy->radius * cy->radius;

	discriminant = b * b - 4 * a * c;
	if (discriminant >= 0)
	{
		t1 = (-b - sqrt(discriminant)) / (2.0 * a);
		t2 = (-b + sqrt(discriminant)) / (2.0 * a);

		// t1 체크 (가까운 교점)
		if (t1 >= rec->tmin && t1 <= rec->tmax)
		{
			hit_point = ray_at(ray, t1);
			projection = vdot(vminus(hit_point, cy_obj->origin), axis);
			if (projection >= -cy->height/2.0 && projection <= cy->height/2.0)
			{
				t_side = t1;
				if (t1 < closest_t)
				{
					closest_t = t1;
					hit_found = 1;
				}
			}
		}

		// t2 체크 (먼 교점)
		if (t2 >= rec->tmin && t2 <= rec->tmax && t_side < 0)
		{
			hit_point = ray_at(ray, t2);
			projection = vdot(vminus(hit_point, cy_obj->origin), axis);
			if (projection >= -cy->height/2.0 && projection <= cy->height/2.0)
			{
				t_side = t2;
				if (t2 < closest_t)
				{
					closest_t = t2;
					hit_found = 1;
				}
			}
		}
	}

	// 2. 끝면(캡) 교차 계산
	double denom = vdot(ray->dir, axis);
	if (fabs(denom) > FLT_EPSILON)
	{
		// 상단 캡
		t_point top_center = vplus(cy_obj->origin, vscale(axis, cy->height/2.0));
		double t_top = vdot(vminus(top_center, ray->orig), axis) / denom;

		if (t_top >= rec->tmin && t_top <= rec->tmax)
		{
			hit_point = ray_at(ray, t_top);
			if (vlength2(vminus(hit_point, top_center)) <= cy->radius * cy->radius)
			{
				if (t_top < closest_t)
				{
					closest_t = t_top;
					hit_found = 1;
					rec->t = t_top;
					rec->p = hit_point;
					rec->norm = axis;
					set_face_normal(ray, rec);
					rec->albedo = cy_obj->color;
				}
			}
		}

		// 하단 캡
		t_point bottom_center = vminus(cy_obj->origin, vscale(axis, cy->height/2.0));
		double t_bottom = vdot(vminus(bottom_center, ray->orig), vscale(axis, -1)) / (-denom);

		if (t_bottom >= rec->tmin && t_bottom <= rec->tmax)
		{
			hit_point = ray_at(ray, t_bottom);
			if (vlength2(vminus(hit_point, bottom_center)) <= cy->radius * cy->radius)
			{
				if (t_bottom < closest_t)
				{
					closest_t = t_bottom;
					hit_found = 1;
					rec->t = t_bottom;
					rec->p = hit_point;
					rec->norm = vscale(axis, -1);
					set_face_normal(ray, rec);
					rec->albedo = cy_obj->color;
				}
			}
		}
	}

	// 3. 측면이 가장 가까운 경우
	if (t_side >= 0 && t_side == closest_t)
	{
		rec->t = t_side;
		rec->p = ray_at(ray, t_side);
		projection = vdot(vminus(rec->p, cy_obj->origin), axis);
		t_point axis_point = vplus(cy_obj->origin, vscale(axis, projection));
		rec->norm = vunit(vminus(rec->p, axis_point));
		set_face_normal(ray, rec);
		rec->albedo = cy_obj->color;
	}

	return (hit_found);
}
