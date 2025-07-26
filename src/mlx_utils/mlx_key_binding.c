/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_binding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:02:07 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/25 07:52:28 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_utils.h"
#include "../../includes/utils.h"

int	is_near_world_up(t_vec dir)
{
	t_vec	world_up;
	double	dot_product;
	double	threshold;

	world_up = vec(0, 1, 0);
	dot_product = vdot(vunit(dir), world_up);
	threshold = 0.99;
	return (fabs(dot_product) > threshold);
}

void	increase_angle(t_vec *dir, t_vec axis, int type)
{
	t_vec	v;
	t_vec	k;
	t_vec	term1;
	t_vec	term2;
	t_vec	term3;

	v = *dir;
	k = vunit(axis);
	term1 = vscale(v, cos(ROTATE_ANGLE));
	term2 = vscale(vcross(k, v), sin(ROTATE_ANGLE));
	term3 = vscale(k, vdot(k, v) * (1 - cos(ROTATE_ANGLE)));
	if (is_near_world_up(vunit(vplus(vplus(term1, term2), term3))))
	{
		if (type == CAMERA)
			return ;
		k.z *= -1;
		k.y -= 0.02;
	}
	*dir = vunit(vplus(vplus(term1, term2), term3));
}

void	decrease_angle(t_vec *dir, t_vec axis, int type)
{
	t_vec	v;
	t_vec	k;
	t_vec	term1;
	t_vec	term2;
	t_vec	term3;

	v = *dir;
	k = vunit(axis);
	term1 = vscale(v, cos(-ROTATE_ANGLE));
	term2 = vscale(vcross(k, v), sin(-ROTATE_ANGLE));
	term3 = vscale(k, vdot(k, v) * (1 - cos(-ROTATE_ANGLE)));
	if (is_near_world_up(vunit(vplus(vplus(term1, term2), term3))))
	{
		if (type == CAMERA)
			return ;
		k.z *= -1;
		k.y += 0.02;
	}
	*dir = vunit(vplus(vplus(term1, term2), term3));
}

void	rotate_cam(t_camera *cam, int keycode)
{
	if (keycode == XK_i)
		increase_angle(&cam->dir, cam->axis.x, CAMERA);
	else if (keycode == XK_k)
		decrease_angle(&cam->dir, cam->axis.x, CAMERA);
	else if (keycode == XK_j)
		increase_angle(&cam->dir, cam->axis.y, CAMERA);
	else if (keycode == XK_l)
		decrease_angle(&cam->dir, cam->axis.y, CAMERA);
	else if (keycode == XK_u)
		increase_angle(&cam->dir, cam->axis.z, CAMERA);
	else if (keycode == XK_o)
		decrease_angle(&cam->dir, cam->axis.z, CAMERA);
}

void	rotate_plane(t_obj *obj, int keycode)
{
	if (keycode == XK_i)
		increase_angle(&obj->data.pl.norm, vec(1, 0, 0), PLANE);
	else if (keycode == XK_k)
		decrease_angle(&obj->data.pl.norm, vec(1, 0, 0), PLANE);
	else if (keycode == XK_j)
		increase_angle(&obj->data.pl.norm, vec(0, 1, 0), PLANE);
	else if (keycode == XK_l)
		decrease_angle(&obj->data.pl.norm, vec(0, 1, 0), PLANE);
	else if (keycode == XK_u)
		increase_angle(&obj->data.pl.norm, vec(0, 0, 1), PLANE);
	else if (keycode == XK_o)
		decrease_angle(&obj->data.pl.norm, vec(0, 0, 1), PLANE);
}
