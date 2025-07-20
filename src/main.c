/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/21 01:38:59 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scene.h"
#include "../includes/trace.h"
#include "../includes/mlx_utils.h"
#include "../includes/parse.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_obj		*world;
	t_obj		*lights;
	double		ka;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->canv = canvas(400, 300);
	scene->cam = camera(&scene->canv, point(0, 0, 0));
	world = obj(SPHERE, sphere(point(-2, 0, -5), 2), color(0.5, 0, 0));
	obj_add(&world, obj(SPHERE, sphere(point(0, -1000, 0), 995), color(1, 1, 1)));
	obj_add(&world, obj(SPHERE, sphere(point(2, 0, -5), 2), color(0, 0.5, 0)));
	obj_add(&world, obj(SPHERE, sphere(point(0, -2000, 0), 999), color(1, 1, 1)));
	scene->obj = world;
	lights = obj(LIGHT_POINT, light_point(point(0, 20, 0), color(1, 1, 1), 0.5),
			color(0, 0, 0));
	lights = obj(LIGHT_POINT, light_point(point(0, 5, 0), color(1, 1, 1), 0.5),
			color(0, 0, 0));
	ka = 0.1;
	scene->amb.ratio = ka;
	scene->amb.color = vscale(color(1, 1, 1), ka);
	return (scene);
}

t_axis	init_axis(t_vec direction)
{
	t_axis	axis;

	axis.z = vec(direction.x, direction.y, direction.z);
	axis.x = vunit(vcross(axis.z, vec(0, 1, 0)));
	axis.y = vunit(vcross(axis.x, axis.z));
	return (axis);
}

void	init_cam(t_canvas *canvas, t_point orig, double fov, t_camera *cam)
{
	t_vec	right;
	double	focal_len;
	double	fov_rad;
	t_vec	world_up;

	world_up = cam->axis.y;
	focal_len = 1.0;
	cam->orig = orig;
	fov_rad = fov * 3.141592 / 180.0;
	cam->viewport_h = 2.0 * tan(fov_rad / 2.0) * focal_len;
	cam->viewport_w = cam->viewport_h * canvas->aspect_ratio;
	cam->focal_len = focal_len;
	right = vunit(vcross(cam->dir, world_up));
	cam->horizontal = vscale(right, cam->viewport_w);
	cam->vertical = vscale(vunit(vcross(right, cam->dir)), cam->viewport_h);
	cam->left_bottom = vminus(vminus(vminus(cam->orig,
					vscale(cam->horizontal, 0.5)), vscale(cam->vertical, 0.5)),
			cam->dir);
	printf("cam->left_bottom: %f, %f, %f\n", cam->left_bottom.x, cam->left_bottom.y,
		cam->left_bottom.z);
	cam->axis = init_axis(cam->dir);
}

int	rt_drawing(t_rt *rt)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_canvas	canv;

	rt->scene.cam.axis = init_axis(rt->scene.cam.dir);
	canv = canvas(WIN_WIDTH, WIN_HEIGHT);
	init_cam(&canv, rt->scene.cam.orig, rt->scene.cam.fov, &rt->scene.cam);
	if (rt->img.ptr != NULL)
		mlx_destroy_image(rt->mlx, rt->img.ptr);
	rt->img.ptr = mlx_new_image(rt->mlx, canv.width, canv.height);
	rt->img.addr = mlx_get_data_addr(rt->img.ptr, &rt->img.bits_per_pixel,
			&rt->img.line_len, &rt->img.endian);
	j = rt->scene.canv.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < rt->scene.canv.width)
		{
			u = (double)i / (rt->scene.canv.width - 1);
			v = (double)j / (rt->scene.canv.height - 1);
			rt->scene.ray = ray_primary(&rt->scene.cam, u, v);
			my_mlx_pixel_put(&rt->img, i, j, ray_color(&rt->scene));
			++i;
		}
		--j;
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_rt	rt;

	if (ac != 2)
		return (print_err_ln("Input argument error."), 1);
	ft_bzero(&rt, sizeof(t_rt));
	fvalidate_save(av[1], &rt.scene);
	rt.mlx = mlx_init();
	rt.win = mlx_new_window(rt.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	mlx_hook(rt.win, KEY_PRESS, 1, rt_keybind, &rt);
	mlx_hook(rt.win, ON_DESTROY, 0, close_rt, &rt);
	mlx_loop_hook(rt.mlx, rt_drawing, &rt);
	mlx_loop(rt.mlx);
	return (0);
}
