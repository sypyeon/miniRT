/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/22 08:08:16 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scene.h"
#include "../includes/trace.h"
#include "../includes/mlx_utils.h"
#include "../includes/parse.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	double		ka;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	ka = 0.1;
	scene->objs.ptr[scene->amb].data.amb_ratio = ka;
	scene->objs.ptr[scene->amb].color = vscale(color(1, 1, 1), ka);
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

void	init_cam(double aspect_ratio, t_point origin, double fov, t_camera *cam)
{
	double	view_h;
	double	view_w;
	t_vec	right;
	double	fov_rad;

	fov_rad = fov * 3.141592 / 180.0;
	cam->focal_len = 1.0;
	view_h = 2.0 * tan(fov_rad / 2.0) * cam->focal_len;
	view_w = view_h * aspect_ratio;
	right = vunit(vcross(cam->dir, cam->axis.y));
	cam->horizontal = vscale(right, view_w);
	cam->vertical = vscale(vunit(vcross(right, cam->dir)), view_h);
	cam->left_bottom = vminus(vminus(vminus(origin, \
		vscale(cam->horizontal, 0.5)), vscale(cam->vertical, 0.5)), \
		cam->dir);
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

// int	rt_drawing(t_rt *rt)
// {
// 	int		i;
// 	int		j;
// 	double	u;
// 	double	v;
// 	t_scene	*scene;

// 	scene = &rt->scene;
// 	prepare_to_draw(rt, &scene->objs.ptr[scene->cam].data.cam);
// 	j = WIN_HEIGHT - 1;
// 	while (j >= 0)
// 	{
// 		i = 0;
// 		while (i < WIN_WIDTH)
// 		{
// 			u = (double)i / (WIN_WIDTH - 1);
// 			v = (double)j / (WIN_HEIGHT - 1);
// 			scene->ray = ray_primary(&scene->objs.ptr[scene->cam], \
// 					(double)i / (WIN_WIDTH - 1), (double)j / (WIN_HEIGHT - 1));
// 			my_mlx_pixel_put(&rt->img, i, j, ray_color(scene));
// 			++i;
// 		}
// 		--j;
// 	}
// 	mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);
// 	rt->scene = *scene;
// 	return (0);
// }

int	rt_drawing(t_rt *rt)
{
    int		i;
    int		j;
    double	u;
    double	v;
	t_scene	*scene;

	scene = &rt->scene;
    prepare_to_draw(rt, &scene->objs.ptr[scene->cam].data.cam);
    j = WIN_HEIGHT - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < WIN_WIDTH)
        {
            u = (double)i / (WIN_WIDTH - 1);
            v = (double)j / (WIN_HEIGHT - 1);
            scene->ray = ray_primary(&scene->objs.ptr[scene->cam], u, v);
            my_mlx_pixel_put(&rt->img, i, j, ray_color(scene));
            ++i;
        }
        --j;
    }
    mlx_put_image_to_window(rt->mlx, rt->win, rt->img.ptr, 0, 0);
	return (0);
}

void	init_world(t_rt *rt)
{
	rt->scene.amb = 0;
	rt->scene.cam = 1;
	rt->scene.curr = 0;
	rt->scene.light = 2;
	rt->scene.objs.size = 5;
	rt->scene.objs.ptr = (t_obj*)calloc(sizeof(t_obj), 5);
	rt->scene.objs.ptr[0].type = AMBIENT;
	rt->scene.objs.ptr[0].color = vec(1, 1, 1);
	rt->scene.objs.ptr[0].origin = vec(0,0,0);
	rt->scene.objs.ptr[0].data.amb_ratio = 0.2;
	rt->scene.objs.ptr[1].type = CAMERA;
	rt->scene.objs.ptr[1].color = vec(0,0,0);
	rt->scene.objs.ptr[1].origin = vec(0,0,0);
	rt->scene.objs.ptr[1].data.cam.dir = vec(0,0,1);
	rt->scene.objs.ptr[1].data.cam.axis = init_axis(rt->scene.objs.ptr[1].data.cam.dir);
	rt->scene.objs.ptr[1].data.cam.focal_len = 1;
	rt->scene.objs.ptr[1].data.cam.fov = 70;
	rt->scene.objs.ptr[2].type = LIGHT;
	rt->scene.objs.ptr[2].color = vec(1,1,1);
	rt->scene.objs.ptr[2].origin = vec(-40, 50, 0);
	rt->scene.objs.ptr[2].data.light.bright_ratio = 0.6;
	rt->scene.objs.ptr[3].type = SPHERE;
	rt->scene.objs.ptr[3].color = vec(0,1,0);
	rt->scene.objs.ptr[3].origin = vec(0, 0, 10);
	rt->scene.objs.ptr[3].data.sp.radius = 6;
	rt->scene.objs.ptr[3].data.sp.radius2 = 6 * 6;
	rt->scene.objs.ptr[4].type = SPHERE;
	rt->scene.objs.ptr[4].color = vec(0,1,0);
	rt->scene.objs.ptr[4].origin = vec(0, -100, 0);
	rt->scene.objs.ptr[4].data.sp.radius = 10;
	rt->scene.objs.ptr[4].data.sp.radius2 = 10 * 10;
}

int	main(int ac, char **av)
{
	t_rt	rt;

	(void)av;
	(void)ac;
	// if (ac != 2)
	// 	return (print_err_ln("Input argument error."), 1);
	ft_bzero(&rt, sizeof(t_rt));
	init_world(&rt);
	// fvalidate_save(av[1], &rt.scene);
	rt.mlx = mlx_init();
	rt.win = mlx_new_window(rt.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	// rt_drawing(&rt, &rt.scene);
	mlx_hook(rt.win, KEY_PRESS, 1, rt_keybind, &rt);
	mlx_hook(rt.win, ON_DESTROY, 0, close_rt, &rt);
	mlx_loop_hook(rt.mlx, rt_drawing, &rt);
	mlx_loop(rt.mlx);
	return (0);
}
