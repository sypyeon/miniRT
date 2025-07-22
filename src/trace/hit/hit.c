/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:39:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/23 07:17:05 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

_Bool	is_object(t_obj obj)
{
	return (obj.type == SPHERE || obj.type == CYLINDER || obj.type == PLANE);
}

_Bool	hit(t_objs *objs, t_ray *ray, t_hit_record *rec)
{
	size_t			i;
	_Bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = 0;
	i = 0;
	while (objs->size > i)
	{
		if (hit_obj(&objs->ptr[i], ray, &temp_rec))
		{
			hit_anything = 1;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		i++;
	}
	return (hit_anything);
}

_Bool	hit_obj(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	_Bool	hit_result;

	hit_result = 0;
	if (obj->type == SPHERE)
		hit_result = hit_sphere(obj, ray, rec);
	if (obj->type == PLANE)
		hit_result = hit_plane(obj, ray, rec);
	return (hit_result);
}
