/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:48:44 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/16 22:37:10 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_trace.h"

#define EPSILON 1e-6

t_ray	rt_init_ray(t_point origin, t_vec direction)
{
	t_ray ray;

    ray.origin = origin;
    ray.direction = rt_vec_unit(direction);
    return (ray);
}

t_point	rt_ray_at(t_ray *ray, double t)
{
	
    t_point at;

    at = rt_vec_plus_vec(ray->origin, rt_vec_mult(ray->direction, t));
    return (at);
}

t_ray	rt_ray_primary(t_camera *cam, double u, double v)
{
    t_ray   ray;

    ray.origin = cam->origin;
    ray.direction = rt_vec_unit(rt_vec_minus_vec(rt_vec_plus_vec(rt_vec_plus_vec(cam->left_bottom,\
						rt_vec_mult(cam->horizontal, u)),\
						rt_vec_mult(cam->vertical, v)), cam->origin));
    return (ray);
}

t_hit_record	rt_hit_record_init(void)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = INFINITY;
	return (rec);
}

t_color	rt_ray_color(t_rt_info *info)
{
    double	t;
    // t_vec	n;

    info->rec.tmin = 0;
    info->rec.tmax = INFINITY;
    t = 0.5 * (info->ray.direction.y + 1.0);
    if (rt_hit(info->obj_lst.head, &info->ray, &info->rec))
        return (rt_color_mult(rt_color_plus_color(rt_vtoc(info->rec.normal), rt_init_color(1, 1, 1)), 0.5));
    else
        return (rt_init_color(0, 0, 0));
    return (rt_color_plus_color(rt_color_mult(rt_init_color(1, 1, 1), 1.0 - t),\
							rt_color_mult(rt_init_color(0.5, 0.7, 1.0), t)));
}
