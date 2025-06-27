/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:48:44 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/27 22:10:38 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_trace.h"

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

    at = rt_vec_plus_vec(ray->origin, rt_vec_multiply(ray->direction, t));
    return (at);
}

t_ray	rt_ray_primary(t_camera *cam, double u, double v)
{
    t_ray   ray;

    ray.origin = cam->origin;
    ray.direction = rt_vec_unit(rt_vec_minus_vec(rt_vec_plus_vec(rt_vec_plus_vec(cam->left_bottom,
						rt_vec_multiply(cam->horizontal, u)),
						rt_vec_multiply(cam->vertical, v)), cam->origin));
    return (ray);
}

t_color	rt_ray_color(t_ray *ray)
{
    double  t;

    t = 0.5 * (ray->direction.y + 1.0);
    // (1-t) * 흰색 + t * 하늘색
    return (rt_vec_plus_vec(rt_vec_multiply(rt_init_color(1, 1, 1), 1.0 - t), rt_vec_multiply(rt_init_color(0.5, 0.7, 1.0), t)));
}
