/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/25 21:29:59 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "../minilibx-linux/mlx.h"
# include "structures.h"
# include <X11/keysym.h>

# define KEY_PRESS	2
# define ON_DESTROY	17

# define WIN_WIDTH	900
# define WIN_HEIGHT	600

# define WHITE	0xFFFFFF
# define BLACK	0x000000

# define ROTATE_ANGLE	0.1

int		close_rt(t_rt *rt);
int		rt_keybind(int keycode, t_rt *rt);

void	mlx_display_d(t_rt *rt, t_vec xy_val, int color);
void	mlx_display_camera_info(t_rt *rt, t_obj cam, void *mlx, void *win);
void	mlx_display_light_info(t_rt *rt, t_obj light, void *mlx, void *win);
void	mlx_display_sphere_info(t_rt *rt, t_obj sp, void *mlx, void *win);
void	mlx_display_plane_info(t_rt *rt, t_obj pl, void *mlx, void *win);
void	mlx_display_cylinder_info(t_rt *rt, t_obj cy, void *mlx, void *win);

int		rt_drawing(t_rt *rt);
void	my_mlx_pixel_put(t_image *data, int x, int y, t_color color);
void	mlx_display_info(t_rt *rt, void *mlx, void *win, int curr);
void	increase_angle(t_vec *dir, t_vec axis, int type);
void	decrease_angle(t_vec *dir, t_vec axis, int type);
void	rotate_cam(t_camera *cam, int keycode);
void	rotate_plane(t_obj *obj, int keycode);
void	rotate_obj(t_obj *obj, int keycode);
void	current_control(t_scene *scene, int keycode);

#endif
