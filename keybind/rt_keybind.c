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

#include "rt_keybind.h"
#include "rt_utils_vector.h"

int	rt_mrt_drawing(t_mrt *mrt);

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
		k = rt_vec_unit(axis);

		term1 = rt_vec_mult(v, cos(angle));
		term2 = rt_vec_mult(rt_vec_outer(k, v), sin(angle));
		term3 = rt_vec_mult(k, rt_vec_inner(k, v) * (1 - cos(angle)));

		cam->direction = rt_vec_unit(rt_vec_plus_vec(rt_vec_plus_vec(term1, term2), term3));
	}
	if (keycode == XK_k)
	{
		axis = cam->axis.x;
		double angle = 0.05;

		v = cam->direction;
		k = rt_vec_unit(axis);

		term1 = rt_vec_mult(v, cos(angle));
		term2 = rt_vec_mult(rt_vec_outer(k, v), sin(angle));
		term3 = rt_vec_mult(k, rt_vec_inner(k, v) * (1 - cos(angle)));

		cam->direction = rt_vec_unit(rt_vec_minus_vec(rt_vec_minus_vec(term1, term2), term3));
	}
	if (keycode == XK_j)
	{
		axis = cam->axis.y;
		double angle = 0.05;

		v = cam->direction;
		k = rt_vec_unit(axis);

		term1 = rt_vec_mult(v, cos(angle));
		term2 = rt_vec_mult(rt_vec_outer(k, v), sin(angle));
		term3 = rt_vec_mult(k, rt_vec_inner(k, v) * (1 - cos(angle)));

		cam->direction = rt_vec_unit(rt_vec_plus_vec(rt_vec_plus_vec(term1, term2), term3));
	}
	if (keycode == XK_l)
	{
		axis = cam->axis.y;
		double angle = 0.05;

		v = cam->direction;
		k = rt_vec_unit(axis);

		term1 = rt_vec_mult(v, cos(angle));
		term2 = rt_vec_mult(rt_vec_outer(k, v), sin(angle));
		term3 = rt_vec_mult(k, rt_vec_inner(k, v) * (1 - cos(angle)));

		cam->direction = rt_vec_unit(rt_vec_minus_vec(rt_vec_minus_vec(term1, term2), term3));
	}
	if (keycode == XK_u)
	{
		axis = cam->axis.z;
		double angle = 0.05;

		v = cam->direction;
		k = rt_vec_unit(axis);

		term1 = rt_vec_mult(v, cos(angle));
		term2 = rt_vec_mult(rt_vec_outer(k, v), sin(angle));
		term3 = rt_vec_mult(k, rt_vec_inner(k, v) * (1 - cos(angle)));

		cam->direction = rt_vec_unit(rt_vec_plus_vec(rt_vec_plus_vec(term1, term2), term3));
	}
	if (keycode == XK_o)
	{
		axis = cam->axis.z;
		double angle = 0.05;
		v = cam->direction;
		k = rt_vec_unit(axis);
		term1 = rt_vec_mult(v, cos(angle));
		term2 = rt_vec_mult(rt_vec_outer(k, v), sin(angle));
		term3 = rt_vec_mult(k, rt_vec_inner(k, v) * (1 - cos(angle)));
		cam->direction = rt_vec_unit(rt_vec_minus_vec(rt_vec_minus_vec(term1, term2), term3));
	}
}

int	close_mrt(t_mrt *mrt)
{
	mlx_destroy_image(mrt->mlx, mrt->img.ptr);
	mlx_destroy_window(mrt->mlx, mrt->win);
	mlx_destroy_display(mrt->mlx);
	rt_free_obj(&(mrt->info));
	free(mrt->mlx);
	exit (0);
	return (0);
}

void	rt_current_control(t_mrt *mrt, int keycode)
{
	if (keycode == XK_1)
		mrt->info.current = CAMERA;
	else if (keycode == XK_2)
		mrt->info.current = AMBIENT;
	else if (keycode == XK_3)
		mrt->info.current = LIGHT;
	else if (keycode == XK_4)
		mrt->info.current = OBJECT;
	else if (keycode == XK_space && mrt->info.current == OBJECT && mrt->info.obj_lst.size > 0)
	{
		if (mrt->info.current_obj->next == NULL)
			mrt->info.current_obj = mrt->info.obj_lst.head;
		else
			mrt->info.current_obj = mrt->info.current_obj->next;
	}
}

void rt_move_coordinate(t_point *origin, t_axis axis, int keycode)
{
	if (keycode == XK_w)
		*origin = rt_vec_plus_vec(*origin, axis.z);
	else if (keycode == XK_s)
		*origin = rt_vec_minus_vec(*origin, axis.z);
	else if (keycode == XK_d)
		*origin = rt_vec_minus_vec(*origin, axis.x);
	else if (keycode == XK_a)
		*origin = rt_vec_plus_vec(*origin, axis.x);
	else if (keycode == XK_q)
		*origin = rt_vec_plus_vec(*origin, axis.y);
	else if (keycode == XK_e)
		*origin = rt_vec_minus_vec(*origin, axis.y);
}

int	rt_keybind(int keycode, t_mrt *mrt)
{
	rt_current_control(mrt, keycode);
	if (keycode == XK_Escape)
		close_mrt(mrt);
	rt_cam_rotate(&mrt->info.cam, keycode);
	rt_move_coordinate(&mrt->info.cam.origin, mrt->info.cam.axis, keycode);
	// if (keycode == XK_w)
	// 	mrt->info.cam.origin = rt_vec_plus_vec(mrt->info.cam.origin, mrt->info.cam.axis.z);
	// else if (keycode == XK_s)
	// 	mrt->info.cam.origin = rt_vec_minus_vec(mrt->info.cam.origin, mrt->info.cam.axis.z);
	// else if (keycode == XK_d)
	// 	mrt->info.cam.origin = rt_vec_minus_vec(mrt->info.cam.origin, mrt->info.cam.axis.x);
	// else if (keycode == XK_a)
	// 	mrt->info.cam.origin = rt_vec_plus_vec(mrt->info.cam.origin, mrt->info.cam.axis.x);
	// else if (keycode == XK_q)
	// 	mrt->info.cam.origin = rt_vec_plus_vec(mrt->info.cam.origin, mrt->info.cam.axis.y);
	// else if (keycode == XK_e)
	// 	mrt->info.cam.origin = rt_vec_minus_vec(mrt->info.cam.origin, mrt->info.cam.axis.y);
	return (0);
}
