/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_binding2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 07:52:13 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/25 07:55:24 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_utils.h"
#include "../../includes/utils.h"

void	rotate_cylinder(t_obj *obj, int keycode)
{
	if (keycode == XK_i)
		increase_angle(&obj->data.cy.norm, vec(1, 0, 0), CYLINDER);
	else if (keycode == XK_k)
		decrease_angle(&obj->data.cy.norm, vec(1, 0, 0), CYLINDER);
	else if (keycode == XK_j)
		increase_angle(&obj->data.cy.norm, vec(0, 1, 0), CYLINDER);
	else if (keycode == XK_l)
		decrease_angle(&obj->data.cy.norm, vec(0, 1, 0), CYLINDER);
	else if (keycode == XK_u)
		increase_angle(&obj->data.cy.norm, vec(0, 0, 1), CYLINDER);
	else if (keycode == XK_o)
		decrease_angle(&obj->data.cy.norm, vec(0, 0, 1), CYLINDER);
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
