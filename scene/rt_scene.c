/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:00:11 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/16 22:35:31 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_scene.h"
#include "rt_parse.h"
#include <math.h>

t_canvas rt_init_canvas(int width, int height)
{
	t_canvas canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_axis rt_init_axis(t_vec direction)
{
	t_axis axis;

	axis.z = rt_init_vec(direction.x, direction.y, direction.z);
	axis.x = rt_vec_unit(rt_vec_outer(axis.z, rt_init_vec(0, 1, 0)));
	axis.y = rt_vec_unit(rt_vec_outer(axis.x, axis.z));
	return (axis);
}

void rt_init_camera(t_canvas *canvas, t_point orig, double fov, t_camera *cam)
{
	t_vec right;
	double focal_len;
	double fov_rad;
	t_vec world_up = cam->axis.y;

	focal_len = 1.0;
	cam->origin = orig;
	fov_rad = fov * 3.141592 / 180.0;
	cam->viewport_h = 2.0 * tan(fov_rad / 2.0) * focal_len;
	cam->viewport_w = cam->viewport_h * canvas->aspect_ratio;
	cam->focal_len = focal_len;
	right = rt_vec_unit(rt_vec_outer(cam->direction, world_up));
	cam->horizontal = rt_vec_mult(right, cam->viewport_w);
	cam->vertical = rt_vec_mult(rt_vec_unit(
						rt_vec_outer(right, cam->direction)),
					cam->viewport_h);
	cam->left_bottom = rt_vec_minus_vec(rt_vec_minus_vec(
											rt_vec_minus_vec(cam->origin,
															 rt_vec_div(cam->horizontal, 2)),
											rt_vec_div(cam->vertical, 2)),
										cam->direction);
	printf("cam->left_bottom: %f, %f, %f\n", cam->left_bottom.x, cam->left_bottom.y, cam->left_bottom.z);
	cam->axis = rt_init_axis(cam->direction);
}

t_scene *scene_init(t_object *light)
{
    t_scene		*scene;
    double		ka; // 8.4 에서 설명

    // malloc 할당 실패 시, 실습에서는 return NULL로 해두었지만, 적절한 에러 처리가 필요하다.
    if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
        return (NULL);
    scene->canvas = rt_init_canvas(400, 300);
    rt_init_camera(&scene->canvas, rt_init_point(0, 0, 0), 90, &scene->camera);
    scene->light = light;
    ka = 0.1; // 8.4 에서 설명
    scene->ambient = rt_color_mult(rt_init_color(1,1,1), ka); // 8.4 에서 설명
    return (scene);
}
