/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:00:11 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/29 23:46:46 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_scene.h"
#include <math.h>

t_canvas rt_init_canvas(int width, int height)
{
	t_canvas canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

void rt_init_camera(t_canvas *canvas, t_point orig, double fov, t_camera *cam)
{
	t_vec right;
	double focal_len;
	double fov_rad;
	t_vec world_up = rt_init_vec(0, 0, 1);

	focal_len = 1.0;
	cam->origin = orig;
	fov_rad = fov * 3.141592 / 180.0;
	cam->viewport_h = 2.0 * tan(fov_rad / 2.0) * focal_len;
	cam->viewport_w = cam->viewport_h * canvas->aspect_ratio;
	cam->focal_len = focal_len;
	if (fabs(rt_vec_inner(world_up, cam->direction)) > 0.999) // 거의 평행
	{ 
		printf("worldupppppppppppppppppppppppppppppppppppppppppp\n");
		world_up = rt_init_vec(1, 0, 0); // 다른 업 벡터 시도
	}
	right = rt_vec_unit(rt_vec_outer(world_up, cam->direction));
	cam->horizontal = rt_vec_mult(right, cam->viewport_w);
	cam->vertical = rt_vec_mult(rt_vec_unit(
									rt_vec_outer(cam->direction, right)),
								cam->viewport_h);
	cam->left_bottom = rt_vec_minus_vec(rt_vec_minus_vec(
											rt_vec_minus_vec(cam->origin,
															 rt_vec_div(cam->horizontal, 2)),
											rt_vec_div(cam->vertical, 2)),
										cam->direction);
}
