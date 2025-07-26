/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:06:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/25 07:48:34 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

_Bool	hit_plane(t_obj *pl_obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	t_vec	oc;
	double	denom;
	double	t;
	double	numer;

	pl = &pl_obj->data.pl;
	denom = vdot(ray->dir, pl->norm);
	if (fabs(denom) < FLT_EPSILON)
		return (0);
	oc = vminus(pl_obj->origin, ray->orig);
	numer = vdot(oc, pl->norm);
	t = numer / denom;
	if (t < rec->tmin || t > rec->tmax)
		return (0);
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->norm = pl->norm;
	set_face_normal(ray, rec);
	rec->albedo = pl_obj->color;
	return (1);
}
