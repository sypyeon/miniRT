/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:00:11 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 15:49:24 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_scene.h"

t_canvas    rt_init_canvas(int  width, int height)
{
    t_canvas canvas;

    canvas.width = width;
    canvas.height = height;
    canvas.aspect_ratio = (double)width / (double)height;
    return (canvas);
}

t_camera    rt_init_camera(t_canvas *canvas, t_point origin)
{
	t_camera    cam;
    double      focal_len;
    double      viewport_height;

    viewport_height = 2.0;
    focal_len = 1.0;
    cam.origin = origin;
    cam.viewport_h = viewport_height;
    cam.viewport_w = viewport_height * canvas->aspect_ratio;
    cam.focal_len = focal_len;
    cam.horizontal = rt_init_vec(cam.viewport_w, 0, 0);
    cam.vertical = rt_init_vec(0, cam.viewport_h, 0);
    cam.left_bottom = rt_vec_minus_vec(rt_vec_minus_vec(rt_vec_minus_vec(cam.origin, rt_vec_div(cam.horizontal, 2)),
                        rt_vec_div(cam.vertical, 2)), rt_init_vec(0, 0, focal_len));
    return (cam);
}
