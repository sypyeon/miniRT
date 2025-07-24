/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_binding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:02:07 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/25 03:07:53 by sipyeon          ###   ########.fr       */
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

void	increase_angle(t_vec *dir, t_vec axis)
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
		k.z *= -1;
		k.y -= 0.02;
	}
	*dir = vunit(vplus(vplus(term1, term2), term3));
}

void	decrease_angle(t_vec *dir, t_vec axis)
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
		k.z *= -1;
		k.y -= 0.02;
	}
	*dir = vunit(vplus(vplus(term1, term2), term3));
}

void	rotate_cam(t_camera *cam, int keycode)
{
	if (keycode == XK_i)
		increase_angle(&cam->dir, cam->axis.x);
	else if (keycode == XK_k)
		decrease_angle(&cam->dir, cam->axis.x);
	else if (keycode == XK_j)
		increase_angle(&cam->dir, cam->axis.y);
	else if (keycode == XK_l)
		decrease_angle(&cam->dir, cam->axis.y);
	else if (keycode == XK_u)
		increase_angle(&cam->dir, cam->axis.z);
	else if (keycode == XK_o)
		decrease_angle(&cam->dir, cam->axis.z);
}

void	rotate_plane(t_obj *obj, int keycode)
{
	if (keycode == XK_i)
		increase_angle(&obj->data.pl.norm, vec(1, 0, 0));
	else if (keycode == XK_k)
		decrease_angle(&obj->data.pl.norm, vec(1, 0, 0));
	else if (keycode == XK_j)
		increase_angle(&obj->data.pl.norm, vec(0, 1, 0));
	else if (keycode == XK_l)
		decrease_angle(&obj->data.pl.norm, vec(0, 1, 0));
	else if (keycode == XK_u)
		increase_angle(&obj->data.pl.norm, vec(0, 0, 1));
	else if (keycode == XK_o)
		decrease_angle(&obj->data.pl.norm, vec(0, 0, 1));
}

void	rotate_cylinder(t_obj *obj, int keycode)
{
	if (keycode == XK_i)
		increase_angle(&obj->data.cy.norm, vec(1, 0, 0));
	else if (keycode == XK_k)
		decrease_angle(&obj->data.cy.norm, vec(1, 0, 0));
	else if (keycode == XK_j)
		increase_angle(&obj->data.cy.norm, vec(0, 1, 0));
	else if (keycode == XK_l)
		decrease_angle(&obj->data.cy.norm, vec(0, 1, 0));
	else if (keycode == XK_u)
		increase_angle(&obj->data.cy.norm, vec(0, 0, 1));
	else if (keycode == XK_o)
		decrease_angle(&obj->data.cy.norm, vec(0, 0, 1));
}

void	rotate_obj(t_obj *obj, int keycode)
{
	if (obj->type == CAMERA)
		rotate_cam(&obj->data.cam, keycode);
	else if (obj->type == PLANE)
		rotate_plane(obj, keycode);
	else if (obj->type == CYLINDER)
		rotate_cylinder(obj, keycode);
}

int	close_rt(t_rt *rt)
{
	if (rt->img.ptr)
		mlx_destroy_image(rt->mlx, rt->img.ptr);
	mlx_destroy_window(rt->mlx, rt->win);
	mlx_destroy_display(rt->mlx);
	free(rt->scene.objs.ptr);
	free(rt->mlx);
	exit(0);
	return (0);
}

void	find_next(t_obj_type type, t_scene *scene, size_t curr, size_t size)
{
	size_t	i;
	t_obj	*obj;

	obj = scene->objs.ptr;
	while (curr < size)
	{
		if (obj[curr].type == type)
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
		find_next(CAMERA, scene, scene->curr + 1, scene->objs.size);
	else if (keycode == XK_2)
		find_next(LIGHT, scene, scene->curr + 1, scene->objs.size);
	else if (keycode == XK_3)
		find_next(SPHERE, scene, scene->curr + 1, scene->objs.size);
	else if (keycode == XK_4)
		find_next(PLANE, scene, scene->curr + 1, scene->objs.size);
	else if (keycode == XK_5)
		find_next(CYLINDER, scene, scene->curr + 1, scene->objs.size);
}

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
