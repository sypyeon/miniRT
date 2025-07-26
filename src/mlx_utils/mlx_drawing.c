/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:45:55 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/26 14:15:27 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_utils.h"
#include "../../includes/trace.h"

t_axis	init_axis(t_vec direction)
{
	t_axis	axis;

	axis.z = vec(direction.x, direction.y, direction.z);
	axis.x = vunit(vcross(axis.z, vec(0, 1, 0)));
	axis.y = vunit(vcross(axis.x, axis.z));
	return (axis);
}

void	init_cam(double aspect_ratio, t_point origin, double fov, t_camera *cam)
{
	double	view_h;
	double	view_w;
	t_vec	right;
	double	fov_rad;
	t_vec	vp_center;

	fov_rad = fov * 3.141592 / 180.0;
	cam->focal_len = 1.0;
	view_h = 2.0 * tan(fov_rad / 2.0) * cam->focal_len;
	view_w = view_h * aspect_ratio;
	right = vunit(vcross(cam->dir, cam->axis.y));
	cam->horizontal = vscale(right, view_w);
	cam->vertical = vscale(vunit(vcross(right, cam->dir)), view_h);
	vp_center = vplus(origin, vscale(cam->dir, cam->focal_len));
	cam->left_bottom = vminus(vminus(vp_center,
				vscale(cam->horizontal, 0.5)), vscale(cam->vertical, 0.5));
	cam->axis = init_axis(cam->dir);
}

void	prepare_to_draw(t_rt *rt, t_camera *cam)
{
	double	w;
	double	h;

	w = WIN_WIDTH;
	h = WIN_HEIGHT;
	cam->axis = init_axis(cam->dir);
	init_cam(w / h, rt->scene.objs.ptr[rt->scene.cam].origin, cam->fov, cam);
	if (rt->img.ptr != NULL)
		mlx_destroy_image(rt->mlx, rt->img.ptr);
	rt->img.ptr = mlx_new_image(rt->mlx, WIN_WIDTH, WIN_HEIGHT);
	rt->img.addr = mlx_get_data_addr(rt->img.ptr, &rt->img.bits_per_pixel,
			&rt->img.line_len, &rt->img.endian);
}

int	rt_drawing(t_rt *rt)
{
	int		i;
	int		j;
	double	u;
	double	v;
	t_scene	*scene;

	scene = &rt->scene;
	prepare_to_draw(rt, &scene->objs.ptr[scene->cam].data.cam);
	j = 0;
	while (j < WIN_HEIGHT)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			u = (double)i / (WIN_WIDTH - 1);
			v = 1.0 - (double)j / (WIN_HEIGHT - 1);
			scene->ray = ray_primary(&scene->objs.ptr[scene->cam], u, v);
			my_mlx_pixel_put(&rt->img, i, j, ray_color(scene));
			++i;
		}
		++j;
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);
	mlx_display_info(rt, rt->mlx, rt->win, rt->scene.curr);
	return (0);
}
