/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_binding3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 07:55:39 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/25 07:56:39 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_utils.h"
#include "../../includes/utils.h"

void	move_coord(t_point *orig, t_axis axis, int keycode)
{
	double	move_speed;

	move_speed = 0.5;
	if (keycode == XK_w)
		*orig = vplus(*orig, vscale(axis.z, move_speed));
	else if (keycode == XK_s)
		*orig = vminus(*orig, vscale(axis.z, move_speed));
	else if (keycode == XK_d)
		*orig = vplus(*orig, vscale(axis.x, move_speed));
	else if (keycode == XK_a)
		*orig = vminus(*orig, vscale(axis.x, move_speed));
	else if (keycode == XK_q)
		*orig = vplus(*orig, vscale(axis.y, move_speed));
	else if (keycode == XK_e)
		*orig = vminus(*orig, vscale(axis.y, move_speed));
}

void	control_brightness(t_obj *obj, int keycode)
{
	if (obj->type != LIGHT)
		return ;
	else if (keycode == XK_equal)
		obj->data.light.bright_ratio += 0.01;
	else if (keycode == XK_minus)
		obj->data.light.bright_ratio -= 0.01;
}

int	rt_keybind(int keycode, t_rt *rt)
{
	t_camera	*cam;

	if (keycode == XK_Escape)
		close_rt(rt);
	cam = &rt->scene.objs.ptr[rt->scene.cam].data.cam;
	current_control(&rt->scene, keycode);
	rotate_obj(&rt->scene.objs.ptr[rt->scene.curr], keycode);
	move_coord(&rt->scene.objs.ptr[rt->scene.curr].origin, cam->axis, keycode);
	control_brightness(&rt->scene.objs.ptr[rt->scene.curr], keycode);
	return (0);
}
