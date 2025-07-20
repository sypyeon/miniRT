/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_binding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:02:07 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 02:13:57 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_utils.h"
#include "../../includes/utils.h"

void	rotate_cam(t_camera *cam, int keycode)
{
	t_vec	axis;
	t_vec	v;
	t_vec	k;
	t_vec	term1;
	t_vec	term2;
	t_vec	term3;

	if (keycode == XK_i)
	{
		axis = cam->axis.x;
		double angle = 0.05;

		v = cam->dir;
		k = vunit(axis);
		term1 = vscale(v, cos(angle));
		term2 = vscale(vcross(k, v), sin(angle));
		term3 = vscale(k, vdot(k, v) * (1 - cos(angle)));
		cam->dir = vunit(vplus(vplus(term1, term2), term3));
	}
	if (keycode == XK_k)
	{
		axis = cam->axis.x;
		double angle = 0.05;
		v = cam->dir;
		k = vunit(axis);
		term1 = vscale(v, cos(angle));
		term2 = vscale(vcross(k, v), sin(angle));
		term3 = vscale(k, vdot(k, v) * (1 - cos(angle)));
		cam->dir = vunit(vminus(vminus(term1, term2), term3));
	}
	if (keycode == XK_j)
	{
		axis = cam->axis.y;
		double angle = 0.05;
		v = cam->dir;
		k = vunit(axis);
		term1 = vscale(v, cos(angle));
		term2 = vscale(vcross(k, v), sin(angle));
		term3 = vscale(k, vdot(k, v) * (1 - cos(angle)));
		cam->dir = vunit(vplus(vplus(term1, term2), term3));
	}
	if (keycode == XK_l)
	{
		axis = cam->axis.y;
		double angle = 0.05;
		v = cam->dir;
		k = vunit(axis);
		term1 = vscale(v, cos(angle));
		term2 = vscale(vcross(k, v), sin(angle));
		term3 = vscale(k, vdot(k, v) * (1 - cos(angle)));
		cam->dir = vunit(vminus(vminus(term1, term2), term3));
	}
	if (keycode == XK_u)
	{
		axis = cam->axis.z;
		double angle = 0.05;
		v = cam->dir;
		k = vunit(axis);
		term1 = vscale(v, cos(angle));
		term2 = vscale(vcross(k, v), sin(angle));
		term3 = vscale(k, vdot(k, v) * (1 - cos(angle)));
		cam->dir = vunit(vplus(vplus(term1, term2), term3));
	}
	if (keycode == XK_o)
	{
		axis = cam->axis.z;
		double angle = 0.05;
		v = cam->dir;
		k = vunit(axis);
		term1 = vscale(v, cos(angle));
		term2 = vscale(vcross(k, v), sin(angle));
		term3 = vscale(k, vdot(k, v) * (1 - cos(angle)));
		cam->dir = vunit(vminus(vminus(term1, term2), term3));
	}
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

// t_obj	find_next_object(t_scene *scene, int type)
// {
// 	t_object	obj;
// 	int			size;

// 	obj = scene->obj
// 	while ()
// }

void	current_control(t_rt *rt, int keycode)
{
	if (keycode == XK_1)
		rt->scene.curr->type = CAMERA;
	else if (keycode == XK_2)
		rt->scene.curr->type = LIGHT;
	else if (keycode == XK_3)
		rt->scene.curr->type = OBJECT;
	else if (keycode == XK_space && rt->scene.curr->type == OBJECT && rt->scene.obj_lst.size > 0)
	{
		if (rt->scene.curr->next == NULL)
			rt->scene.curr = rt->scene.obj_lst.head;
		else
			rt->scene.curr = rt->scene.curr->next;
	}
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
	current_control(rt, keycode);
	if (keycode == XK_Escape)
		close_rt(rt);
	rotate_cam(&rt->scene.cam, keycode);
	move_coord(&rt->scene.cam.orig, rt->scene.cam.axis, keycode);
	// if (keycode == XK_w)
	// 	rt->scene.cam.orig = vplus(rt->scene.cam.orig, rt->scene.cam.axis.z);
	// else if (keycode == XK_s)
	// 	rt->scene.cam.orig = vminus(rt->scene.cam.orig, rt->scene.cam.axis.z);
	// else if (keycode == XK_d)
	// 	rt->scene.cam.orig = vminus(rt->scene.cam.orig, rt->scene.cam.axis.x);
	// else if (keycode == XK_a)
	// 	rt->scene.cam.orig = vplus(rt->scene.cam.orig, rt->scene.cam.axis.x);
	// else if (keycode == XK_q)
	// 	rt->scene.cam.orig = vplus(rt->scene.cam.orig, rt->scene.cam.axis.y);
	// else if (keycode == XK_e)
	// 	rt->scene.cam.orig = vminus(rt->scene.cam.orig, rt->scene.cam.axis.y);
	return (0);
}
