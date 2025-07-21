/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_binding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:02:07 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/22 06:12:14 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_utils.h"
#include "../../includes/utils.h"

void	increase_angle(t_camera *cam, t_vec axis)
{
	t_vec	v;
	t_vec	k;
	t_vec	term1;
	t_vec	term2;
	t_vec	term3;

	v = cam->dir;
	k = vunit(axis);
	term1 = vscale(v, cos(ROTATE_ANGLE));
	term2 = vscale(vcross(k, v), sin(ROTATE_ANGLE));
	term3 = vscale(k, vdot(k, v) * (1 - cos(ROTATE_ANGLE)));
	cam->dir = vunit(vplus(vplus(term1, term2), term3));
}

void	decrease_angle(t_camera *cam, t_vec axis)
{
	t_vec	v;
	t_vec	k;
	t_vec	term1;
	t_vec	term2;
	t_vec	term3;

	v = cam->dir;
	k = vunit(axis);
	term1 = vscale(v, cos(-ROTATE_ANGLE));
	term2 = vscale(vcross(k, v), sin(-ROTATE_ANGLE));
	term3 = vscale(k, vdot(k, v) * (1 - cos(-ROTATE_ANGLE)));
	cam->dir = vunit(vplus(vplus(term1, term2), term3));
}

void	rotate_cam(t_camera *cam, int keycode)
{
	if (keycode == XK_i)
		increase_angle(cam, cam->axis.x);
	else if (keycode == XK_k)
		decrease_angle(cam, cam->axis.x);
	else if (keycode == XK_j)
		increase_angle(cam, cam->axis.y);
	else if (keycode == XK_l)
		decrease_angle(cam, cam->axis.y);
	else if (keycode == XK_u)
		increase_angle(cam, cam->axis.z);
	else if (keycode == XK_o)
		decrease_angle(cam, cam->axis.z);
}

int	close_rt(t_rt *rt)
{
	mlx_destroy_image(rt->mlx, rt->img.ptr);
	mlx_destroy_window(rt->mlx, rt->win);
	mlx_destroy_display(rt->mlx);
	free_obj(&(rt->scene));
	free(rt->mlx);
	exit(0);
	return (0);
}

void	find_next(int type, t_scene *scene, int curr, int size)
{
	int		i;
	int		max;
	t_obj	*obj;

	obj = scene->objs.ptr;
	while (curr < size)
	{
		if (obj[i].type == type)
		{
			scene->curr = curr;
			return ;
		}
		curr++;
	}
	i = 0;
	while (i < size)
	{
		if (obj[i].type == type)
		{
			scene->curr = i;
			return ;
		}
		i++;
	}
}

void	current_control(t_scene *scene, int keycode)
{
	if (keycode == XK_1)
		find_next(CAMERA, scene->objs.ptr, scene->curr + 1, scene->objs.size);
	else if (keycode == XK_2)
		find_next(LIGHT, scene->objs.ptr, scene->curr + 1, scene->objs.size);
	else if (keycode == XK_3)
		find_next(SPHERE, scene->objs.ptr, scene->curr + 1, scene->objs.size);
	else if (keycode == XK_4)
		find_next(PLANE, scene->objs.ptr, scene->curr + 1, scene->objs.size);
	else if (keycode == XK_5)
		find_next(CYLINDER, scene->objs.ptr, scene->curr + 1, scene->objs.size);
}

void	move_coord(t_point *orig, t_axis axis, int keycode)
{
	if (keycode == XK_w)
		*orig = vplus(*orig, axis.z);
	else if (keycode == XK_s)
		*orig = vminus(*orig, axis.z);
	else if (keycode == XK_d)
		*orig = vminus(*orig, axis.x);
	else if (keycode == XK_a)
		*orig = vplus(*orig, axis.x);
	else if (keycode == XK_q)
		*orig = vplus(*orig, axis.y);
	else if (keycode == XK_e)
		*orig = vminus(*orig, axis.y);
}

int	rt_keybind(int keycode, t_rt *rt)
{
	t_camera	*cam;

	if (keycode == XK_Escape)
		close_rt(rt);
	cam = &rt->scene.objs.ptr[rt->scene.cam].data.cam;
	current_control(rt, keycode);
	rotate_cam(cam, keycode);
	move_coord(&rt->scene.objs.ptr[rt->scene.curr], cam->axis, keycode);
	rt_drawing(rt, &rt->scene);
	return (0);
}
