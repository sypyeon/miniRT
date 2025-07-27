/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:50:34 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/26 23:52:42 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = FLT_EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_ray	ray(t_point orig, t_vec dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

t_point	ray_at(t_ray *ray, double t)
{
	t_point	at;

	at = vplus(ray->orig, vscale(ray->dir, t));
	return (at);
}

t_ray	ray_primary(t_obj *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->origin;
	ray.dir = vunit(vminus(vplus(vplus(cam->data.cam.left_bottom,
						vscale(cam->data.cam.horizontal, u)),
					vscale(cam->data.cam.vertical, v)), cam->origin));
	return (ray);
}

t_color	ray_color(t_scene *scene)
{
	scene->rec = record_init();
	if (hit(&scene->objs, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	else
	{
		return (color(0.5, 0.7, 1.0));
	}
}
