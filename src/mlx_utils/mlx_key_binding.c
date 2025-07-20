/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_binding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:31:32 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/20 18:12:33 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keybind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:02:07 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/16 22:35:51 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_utils.h"
#include "../../includes/utils.h"

void	rt_cam_rotate(t_camera *cam, int keycode)
{
	t_vec axis;
	t_vec v;
	t_vec k;
	t_vec term1;
	t_vec term2;
	t_vec term3;

	if (keycode == XK_i)
	{
		axis = cam->axis.x;
		double angle = 0.05;

		v = cam->direction;
		k = vunit(axis);

		term1 = vmult(v, cos(angle));
		term2 = vmult(vcross(k, v), sin(angle));
		term3 = vmult(k, vdot(k, v) * (1 - cos(angle)));

		cam->direction = vunit(vplus(vplus(term1, term2), term3));
	}
	if (keycode == XK_k)
	{
		axis = cam->axis.x;
		double angle = 0.05;

		v = cam->direction;
		k = vunit(axis);

		term1 = vmult(v, cos(angle));
		term2 = vmult(vcross(k, v), sin(angle));
		term3 = vmult(k, vdot(k, v) * (1 - cos(angle)));

		cam->direction = vunit(vminus(vminus(term1, term2), term3));
	}
	if (keycode == XK_j)
	{
		axis = cam->axis.y;
		double angle = 0.05;

		v = cam->direction;
		k = vunit(axis);

		term1 = vmult(v, cos(angle));
		term2 = vmult(vcross(k, v), sin(angle));
		term3 = vmult(k, vdot(k, v) * (1 - cos(angle)));

		cam->direction = vunit(vplus(vplus(term1, term2), term3));
	}
	if (keycode == XK_l)
	{
		axis = cam->axis.y;
		double angle = 0.05;

		v = cam->direction;
		k = vunit(axis);

		term1 = vmult(v, cos(angle));
		term2 = vmult(vcross(k, v), sin(angle));
		term3 = vmult(k, vdot(k, v) * (1 - cos(angle)));

		cam->direction = vunit(vminus(vminus(term1, term2), term3));
	}
	if (keycode == XK_u)
	{
		axis = cam->axis.z;
		double angle = 0.05;

		v = cam->direction;
		k = vunit(axis);

		term1 = vmult(v, cos(angle));
		term2 = vmult(vcross(k, v), sin(angle));
		term3 = vmult(k, vdot(k, v) * (1 - cos(angle)));

		cam->direction = vunit(vplus(vplus(term1, term2), term3));
	}
	if (keycode == XK_o)
	{
		axis = cam->axis.z;
		double angle = 0.05;
		v = cam->direction;
		k = vunit(axis);
		term1 = vmult(v, cos(angle));
		term2 = vmult(vcross(k, v), sin(angle));
		term3 = vmult(k, vdot(k, v) * (1 - cos(angle)));
		cam->direction = vunit(vminus(vminus(term1, term2), term3));
	}
}

int	close_mrt(t_mrt *mrt)
{
	mlx_destroy_image(mrt->mlx, mrt->img.ptr);
	mlx_destroy_window(mrt->mlx, mrt->win);
	mlx_destroy_display(mrt->mlx);
	rt_free_obj(&(mrt->scene));
	free(mrt->mlx);
	exit (0);
	return (0);
}

t_object	find_next_object(t_scene *scene, int type)
{
	t_object	obj;
	int			size;

	obj = scene->obj
	while ()
}

void	rt_current_control(t_mrt *mrt, int keycode)
{
	if (keycode == XK_1)
		mrt->scene.current->type = CAMERA;
	else if (keycode == XK_2)
		mrt->scene.current->type = LIGHT;
	else if (keycode == XK_3)
		mrt->scene.current->type = OBJECT;
	else if (keycode == XK_space && mrt->scene.current.tpye == OBJECT && mrt->scene.obj_lst.size > 0)
	{
		if (mrt->scene.current_obj->next == NULL)
			mrt->scene.current_obj = mrt->scene.obj_lst.head;
		else
			mrt->scene.current_obj = mrt->scene.current_obj->next;
	}
}

void rt_move_coordinate(t_point *origin, t_axis axis, int keycode)
{
	if (keycode == XK_w)
		*origin = vplus(*origin, axis.z);
	else if (keycode == XK_s)
		*origin = vminus(*origin, axis.z);
	else if (keycode == XK_d)
		*origin = vminus(*origin, axis.x);
	else if (keycode == XK_a)
		*origin = vplus(*origin, axis.x);
	else if (keycode == XK_q)
		*origin = vplus(*origin, axis.y);
	else if (keycode == XK_e)
		*origin = vminus(*origin, axis.y);
}

int	rt_keybind(int keycode, t_mrt *mrt)
{
	rt_current_control(mrt, keycode);
	if (keycode == XK_Escape)
		close_mrt(mrt);
	rt_cam_rotate(&mrt->scene.camera, keycode);
	rt_move_coordinate(&mrt->scene.camera.orig, mrt->scene.camera.axis, keycode);
	// if (keycode == XK_w)
	// 	mrt->scene.cam.origin = vplus(mrt->scene.cam.origin, mrt->scene.cam.axis.z);
	// else if (keycode == XK_s)
	// 	mrt->scene.cam.origin = vminus(mrt->scene.cam.origin, mrt->scene.cam.axis.z);
	// else if (keycode == XK_d)
	// 	mrt->scene.cam.origin = vminus(mrt->scene.cam.origin, mrt->scene.cam.axis.x);
	// else if (keycode == XK_a)
	// 	mrt->scene.cam.origin = vplus(mrt->scene.cam.origin, mrt->scene.cam.axis.x);
	// else if (keycode == XK_q)
	// 	mrt->scene.cam.origin = vplus(mrt->scene.cam.origin, mrt->scene.cam.axis.y);
	// else if (keycode == XK_e)
	// 	mrt->scene.cam.origin = vminus(mrt->scene.cam.origin, mrt->scene.cam.axis.y);
	return (0);
}
