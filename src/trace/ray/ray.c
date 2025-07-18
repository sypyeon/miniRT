/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:50:34 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 22:43:59 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
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

	at = vplus(ray->orig, vmult(ray->dir, t));
	return (at);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = vunit(vminus(vplus(vplus(cam->left_bottom,
						vmult(cam->horizontal, u)), vmult(cam->vertical, v)),
				cam->orig));
	return (ray);
}

t_color	ray_color(t_scene *scene)
{
	double	t;

	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	else
	{
		t = 0.5 * (scene->ray.dir.y + 1.0);
		return (vplus(vmult(color3(1, 1, 1), 1.0 - t),
				vmult(color3(0.5, 0.7, 1.0), t)));
	}
}
