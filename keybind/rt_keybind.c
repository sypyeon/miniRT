/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keybind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:02:07 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 22:44:29 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_keybind.h"

void	rt_cam_rotate(t_camera *cam, int keycode)
{
	if (keycode == XK_e)
		cam->direction.x += 0.1;
	if (keycode == XK_r)
		cam->direction.x -= 0.1;
	if (keycode == XK_d)
		cam->direction.y += 0.1;
	if (keycode == XK_f)
		cam->direction.y -= 0.1;
	if (keycode == XK_c)
		cam->direction.z += 0.1;
	if (keycode == XK_v)
		cam->direction.z -= 0.1;
}

void	rt_rotate(t_rt_info info, int keycode)

void	rt_select_control(t_rt_info *info, int keycode)
{
	if ()
}

void	rt_move_coordinate()
{
	
}

void	rt_control_size()

int	rt_keybind(int keycode, t_mrt *mrt)
{
	if (keycode == XK_Escape)
		close_mrt(mrt);
	else if (rt_rotate_keycodes(keycode))
		rt_cam_rotate(mrt);
	else if (rt_moving_keycodes(keycode))
		rt_cam_rotate(mrt);
	else if (rt_size_control_keycodes(keycode))
		rt_cam_rotate(mrt);
	else if (rt_select_keycodes(keycode))
		rt_cam_rotate(mrt);
	return (0);
}
