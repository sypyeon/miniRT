/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/22 07:55:24 by sipyeon          ###   ########.fr       */
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

void	my_mlx_pixel_put(t_image *data, int x, int y, t_color color);
int		rt_keybind(int keycode, t_rt *rt);
int		close_rt(t_rt *rt);
// int		rt_drawing(t_rt *rt);

#endif
