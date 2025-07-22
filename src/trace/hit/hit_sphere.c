/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:09:35 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/23 05:32:35 by sipyeon          ###   ########.fr       */
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
	oc = vminus(ray->orig, sp_obj->origin);
	discriminant = vdot(oc, ray->dir) * vdot(oc, ray->dir) - \
			vlength2(ray->dir) * (vlength2(oc) - pow(sp->radius, 2));
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
	rec->norm = vscale(vminus(rec->p, sp_obj->origin), 1 / sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = sp_obj->color;
	return (1);
}

// _Bool	hit_sphere(t_obj *sp_obj, t_ray *ray, t_hit_record *rec)
// {
//     t_sphere	*sp;
//     t_vec		oc;
//     double		a;
//     double		half_b;
//     double		c;
//     double		discriminant;
//     double		root;

//     sp = &sp_obj->data.sp;
//     oc = vminus(ray->orig, sp_obj->origin);

//     a = vlength2(ray->dir);
//     half_b = vdot(oc, ray->dir);  // b/2
//     c = vlength2(oc) - sp->radius * sp->radius;

//     discriminant = half_b * half_b - a * c;
//     if (discriminant < 0)
//         return (0);

//     root = (-half_b - sqrt(discriminant)) / a;
//     if (root < rec->tmin || root > rec->tmax)
//     {
//         root = (-half_b + sqrt(discriminant)) / a;
//         if (root < rec->tmin || root > rec->tmax)
//             return (0);
//     }

//     rec->t = root;
//     rec->p = ray_at(ray, root);
//     rec->norm = vunit(vminus(rec->p, sp_obj->origin));
//     set_face_normal(ray, rec);
//     rec->albedo = sp_obj->color;
//     return (1);
// }
