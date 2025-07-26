/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_obj_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 01:27:21 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/25 22:10:58 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_utils.h"
#include "../../includes/utils.h"

void	mlx_display_camera_info(t_rt *rt, t_obj cam, void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 15, WHITE, "Camera");
	mlx_string_put(mlx, win, 10, 30, WHITE, "Coordinates");
	mlx_string_put(mlx, win, 10, 45, WHITE, "x:");
	mlx_string_put(mlx, win, 65, 45, WHITE, "y:");
	mlx_string_put(mlx, win, 120, 45, WHITE, "z:");
	mlx_display_d(rt, vec(25, 45, cam.origin.x), WHITE);
	mlx_display_d(rt, vec(80, 45, cam.origin.y), WHITE);
	mlx_display_d(rt, vec(135, 45, cam.origin.z), WHITE);
	mlx_string_put(mlx, win, 10, 60, WHITE, "Direction");
	mlx_string_put(mlx, win, 10, 75, WHITE, "x:");
	mlx_string_put(mlx, win, 65, 75, WHITE, "y:");
	mlx_string_put(mlx, win, 120, 75, WHITE, "z:");
	mlx_display_d(rt, vec(25, 75, cam.data.cam.dir.x), WHITE);
	mlx_display_d(rt, vec(80, 75, cam.data.cam.dir.y), WHITE);
	mlx_display_d(rt, vec(135, 75, cam.data.cam.dir.z), WHITE);
}

void	mlx_display_light_info(t_rt *rt, t_obj light, void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 15, WHITE, "Light");
	mlx_string_put(mlx, win, 10, 30, WHITE, "Coordinates");
	mlx_string_put(mlx, win, 10, 45, WHITE, "x:");
	mlx_string_put(mlx, win, 65, 45, WHITE, "y:");
	mlx_string_put(mlx, win, 120, 45, WHITE, "z:");
	mlx_display_d(rt, vec(25, 45, light.origin.x), WHITE);
	mlx_display_d(rt, vec(80, 45, light.origin.y), WHITE);
	mlx_display_d(rt, vec(135, 45, light.origin.z), WHITE);
	mlx_string_put(mlx, win, 10, 60, WHITE, "Brightness");
	mlx_display_d(rt, vec(10, 75, light.data.light.bright_ratio), WHITE);
}

void	mlx_display_sphere_info(t_rt *rt, t_obj sp, void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 15, WHITE, "Sphere");
	mlx_string_put(mlx, win, 10, 30, WHITE, "Coordinates");
	mlx_string_put(mlx, win, 10, 45, WHITE, "x:");
	mlx_string_put(mlx, win, 65, 45, WHITE, "y:");
	mlx_string_put(mlx, win, 120, 45, WHITE, "z:");
	mlx_display_d(rt, vec(25, 45, sp.origin.x), WHITE);
	mlx_display_d(rt, vec(80, 45, sp.origin.y), WHITE);
	mlx_display_d(rt, vec(135, 45, sp.origin.z), WHITE);
	mlx_string_put(mlx, win, 10, 60, WHITE, "Radius");
	mlx_display_d(rt, vec(25, 75, sp.data.sp.radius), WHITE);
}

void	mlx_display_plane_info(t_rt *rt, t_obj pl, void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 15, WHITE, "Plane");
	mlx_string_put(mlx, win, 10, 30, WHITE, "Coordinates");
	mlx_string_put(mlx, win, 10, 45, WHITE, "x:");
	mlx_string_put(mlx, win, 65, 45, WHITE, "y:");
	mlx_string_put(mlx, win, 120, 45, WHITE, "z:");
	mlx_display_d(rt, vec(25, 45, pl.origin.x), WHITE);
	mlx_display_d(rt, vec(80, 45, pl.origin.y), WHITE);
	mlx_display_d(rt, vec(135, 45, pl.origin.z), WHITE);
	mlx_string_put(mlx, win, 10, 60, WHITE, "Direction");
	mlx_string_put(mlx, win, 10, 75, WHITE, "x:");
	mlx_string_put(mlx, win, 65, 75, WHITE, "y:");
	mlx_string_put(mlx, win, 120, 75, WHITE, "z:");
	mlx_display_d(rt, vec(25, 75, pl.data.pl.norm.x), WHITE);
	mlx_display_d(rt, vec(80, 75, pl.data.pl.norm.y), WHITE);
	mlx_display_d(rt, vec(135, 75, pl.data.pl.norm.z), WHITE);
}

void	mlx_display_cylinder_info(t_rt *rt, t_obj cy, void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 15, WHITE, "Cylinder");
	mlx_string_put(mlx, win, 10, 30, WHITE, "Coordinates");
	mlx_string_put(mlx, win, 10, 45, WHITE, "x:");
	mlx_string_put(mlx, win, 65, 45, WHITE, "y:");
	mlx_string_put(mlx, win, 120, 45, WHITE, "z:");
	mlx_display_d(rt, vec(25, 45, cy.origin.x), WHITE);
	mlx_display_d(rt, vec(80, 45, cy.origin.y), WHITE);
	mlx_display_d(rt, vec(135, 45, cy.origin.z), WHITE);
	mlx_string_put(mlx, win, 10, 60, WHITE, "Direction");
	mlx_string_put(mlx, win, 10, 75, WHITE, "x:");
	mlx_string_put(mlx, win, 65, 75, WHITE, "y:");
	mlx_string_put(mlx, win, 120, 75, WHITE, "z:");
	mlx_display_d(rt, vec(25, 75, cy.data.cy.norm.x), WHITE);
	mlx_display_d(rt, vec(80, 75, cy.data.cy.norm.y), WHITE);
	mlx_display_d(rt, vec(135, 75, cy.data.cy.norm.z), WHITE);
}
