/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:39:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 02:14:49 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

_Bool	hit(t_obj *world, t_ray *ray, t_hit_record *rec)
{
	_Bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = 0;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = 1;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

_Bool	hit_obj(t_obj *world, t_ray *ray, t_hit_record *rec)
{
	_Bool	hit_result;

	hit_result = 0;
	if (world->type == SPHERE)
		hit_result = hit_sphere(world, ray, rec);
	return (hit_result);
}
