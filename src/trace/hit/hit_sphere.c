/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:09:35 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 00:31:56 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

_Bool	hit_sphere(t_obj *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_vec		oc;
	double		discriminant;
	double		root;

	sp = &sp_obj->data.sp;
	oc = vminus(ray->orig, sp->center);
	discriminant = vdot(oc, ray->dir) * vdot(oc, ray->dir) - vlength2(ray->dir)
		* (vlength2(oc) - pow(sp->radius, 2));
	if (discriminant < 0)
		return (0);
	root = (-vdot(oc, ray->dir) - sqrt(discriminant)) / vlength2(ray->dir);
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-vdot(oc, ray->dir) + sqrt(discriminant)) / vlength2(ray->dir);
		if (root < rec->tmin || rec->tmax < root)
			return (0);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->norm = vscale(vminus(rec->p, sp->center), 1 / sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = sp_obj->albedo;
	return (1);
}
