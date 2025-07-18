/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:09:35 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 22:34:02 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

t_bool	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_vec		oc;
	double		discriminant;
	double		root;

	sp = sp_obj->element;
	oc = vminus(ray->orig, sp->center);
	discriminant = vdot(oc, ray->dir) * vdot(oc, ray->dir) - vlength2(ray->dir)
		* (vlength2(oc) - sp->radius2);
	if (discriminant < 0)
		return (FALSE);
	root = (-vdot(oc, ray->dir) - sqrt(discriminant)) / vlength2(ray->dir);
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-vdot(oc, ray->dir) + sqrt(discriminant)) / vlength2(ray->dir);
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = sp_obj->albedo;
	return (TRUE);
}
