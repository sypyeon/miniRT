/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keybind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:02:07 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/29 23:45:59 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_keybind.h"
#include "rt_utils_vector.h"

void	rt_cam_rotate(t_camera *cam, int keycode)
{
	if (keycode == XK_e)
	{
		t_vec axis = rt_init_vec(0, 0, 1);
		double angle = 0.1;

		t_vec v = cam->direction;
		t_vec k = rt_vec_unit(axis);

		t_vec term1 = rt_vec_mult(v, cos(angle));
		t_vec term2 = rt_vec_mult(rt_vec_outer(k, v), sin(angle));
		t_vec term3 = rt_vec_mult(k, rt_vec_inner(k, v) * (1 - cos(angle)));

		cam->direction = rt_vec_unit(rt_vec_plus_vec(rt_vec_plus_vec(term1, term2), term3));

		printf("%lf %lf %lf\n", cam->direction.x, cam->direction.y, cam->direction.z);
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

int	rt_keybind(int keycode, t_mrt *mrt)
{
	if (keycode == XK_Escape)
		close_mrt(mrt);
	else if (rt_rotate_keycodes(keycode))
		rt_cam_rotate(&mrt->info.cam, keycode);
	// else if (rt_moving_keycodes(keycode))
	// 	rt_cam_rotate(mrt);
	// else if (rt_size_control_keycodes(keycode))
	// 	rt_cam_rotate(mrt);
	// else if (rt_select_keycodes(keycode))
	// 	rt_cam_rotate(mrt);
	return (0);
}
