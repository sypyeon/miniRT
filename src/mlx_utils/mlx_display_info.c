/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 21:30:28 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/25 01:54:25 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_utils.h"
#include "../../includes/utils.h"

void	mlx_display_d(t_rt *rt, int x, int y, double value, int color)
{
	char	*str;

	str = ft_dtostr(value);
	if (str && rt->mlx && rt->win)
		mlx_string_put(rt->mlx, rt->win, x, y, color, str);
	free(str);
}

void	mlx_display_amb_info(t_rt *rt, t_obj amb, void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 15, WHITE, "Ambient");
	mlx_string_put(mlx, win, 10, 30, WHITE, "Ratio: ");
	mlx_display_d(rt, 150, 30, amb.data.amb_ratio, WHITE);
	mlx_string_put(mlx, win, 10, 45, WHITE, "Color: ");
	mlx_string_put(mlx, win, 10, 45, WHITE, "r:");
	mlx_string_put(mlx, win, 65, 45, WHITE, "g:");
	mlx_string_put(mlx, win, 120, 45, WHITE, "b:");
	mlx_display_d(rt, 25, 45, amb.color.x, WHITE);
	mlx_display_d(rt, 80, 45, amb.color.y, WHITE);
	mlx_display_d(rt, 135, 45, amb.color.z, WHITE);
}

void	mlx_display_info(t_rt *rt, void *mlx, void *win, int curr)
{
	t_obj	*obj;

	obj = rt->scene.objs.ptr;
	if (obj[curr].type == CAMERA)
		mlx_display_camera_info(rt, rt->scene.objs.ptr[curr], mlx, win);
	else if (obj[curr].type == AMBIENT)
		mlx_display_amb_info(rt, rt->scene.objs.ptr[curr], mlx, win);
	else if (obj[curr].type == LIGHT)
		mlx_display_light_info(rt, rt->scene.objs.ptr[curr], mlx, win);
	else if (obj[curr].type == SPHERE)
		mlx_display_sphere_info(rt, rt->scene.objs.ptr[curr], mlx, win);
	else if (obj[curr].type == PLANE)
		mlx_display_plane_info(rt, rt->scene.objs.ptr[curr], mlx, win);
	else if (obj[curr].type == CYLINDER)
		mlx_display_cylinder_info(rt, rt->scene.objs.ptr[curr], mlx, win);
}
