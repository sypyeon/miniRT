/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keybind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:02:07 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/07 19:49:32 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_keybind.h"
#include "rt_utils_vector.h"

void	rt_cam_rotate(t_camera *cam, int keycode)
{
	if (keycode == XK_e)
	{
		t_vec axis = rt_init_vec(1, 0, 0);
		double angle = 0.01;

		t_vec v = cam->direction;
		t_vec k = rt_vec_unit(axis);

		t_vec term1 = rt_vec_mult(v, cos(angle));
		t_vec term2 = rt_vec_mult(rt_vec_outer(k, v), sin(angle));
		t_vec term3 = rt_vec_mult(k, rt_vec_inner(k, v) * (1 - cos(angle)));

		cam->direction = rt_vec_unit(rt_vec_plus_vec(rt_vec_plus_vec(term1, term2), term3));
	}
	// if (keycode == XK_e)
	// {
	// 	printf("%lf %lf %lf\n", cam->direction.x, cam->direction.y, cam->direction.z);
	// 	cam->direction = rt_vec_plus_vec(rt_vec_plus_vec(rt_vec_mult(cam->direction, cos(0.1)), rt_vec_mult(rt_vec_outer(rt_init_vec(1, 0, 0), cam->direction), sin(0.1))), rt_vec_mult(rt_vec_mult(rt_init_vec(1, 0, 0), rt_vec_inner(rt_init_vec(1, 0, 0), cam->direction)), (1 - cos(0.1))));
	// 	printf("%lf %lf %lf\n", cam->direction.x, cam->direction.y, cam->direction.z);
	// 	printf("rotating\n");
	// }
		
	// if (keycode == XK_r)
	// 	cam->direction.x -= 0.1;
	// if (keycode == XK_d)
	// 	cam->direction.y += 0.1;
	// if (keycode == XK_f)
	// 	cam->direction.y -= 0.1;
	// if (keycode == XK_c)
	// 	cam->direction.z += 0.1;
	// if (keycode == XK_v)
	// 	cam->direction.z -= 0.1;
}

// void	rt_rotate(t_rt_info info, int keycode)
// {
	
// }

// void	rt_select_control(t_rt_info *info, int keycode)
// {
// 	if ()
// }

// void	rt_move_coordinate()
// {
	
// }

// void	rt_control_size()
// {
	
// }

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
	else if (keycode == XK_space && mrt->info.current == OBJECT && mrt->info.obj.size > 0)
	{
		if (mrt->info.current_obj->next == NULL)
			mrt->info.current_obj = mrt->info.obj.head;
		else
			mrt->info.current_obj = mrt->info.current_obj->next;
	}
}

int	rt_keybind(int keycode, t_mrt *mrt)
{
	rt_current_control(mrt, keycode);
	if (keycode == XK_Escape)
		close_mrt(mrt);
	else if (rt_rotate_keycodes(keycode))
		rt_cam_rotate(&mrt->info.cam, keycode);
	else if (rt_moving_keycodes(keycode))
	{
		if (keycode == XK_q)
			mrt->info.cam.origin = rt_vec_plus_vec(mrt->info.cam.origin, mrt->info.cam.axis.z);
		else if (keycode == XK_w)
			mrt->info.cam.origin = rt_vec_minus_vec(mrt->info.cam.origin, mrt->info.cam.axis.z);
		else if (keycode == XK_a)
			mrt->info.cam.origin = rt_vec_minus_vec(mrt->info.cam.origin, mrt->info.cam.axis.x);
		else if (keycode == XK_s)
			mrt->info.cam.origin = rt_vec_plus_vec(mrt->info.cam.origin, mrt->info.cam.axis.x);
		else if (keycode == XK_z)
			mrt->info.cam.origin = rt_vec_plus_vec(mrt->info.cam.origin, mrt->info.cam.axis.y);
		else if (keycode == XK_x)
			mrt->info.cam.origin = rt_vec_minus_vec(mrt->info.cam.origin, mrt->info.cam.axis.y);
	}
	// else if (rt_moving_keycodes(keycode))
	// 	rt_cam_rotate(mrt);
	// else if (rt_size_control_keycodes(keycode))
	// 	rt_cam_rotate(mrt);
	// else if (rt_select_keycodes(keycode))
	// 	rt_cam_rotate(mrt);
	return (0);
}
