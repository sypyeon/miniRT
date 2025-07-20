/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/20 19:24:32 by jaehylee         ###   ########.fr       */
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

# define CAMERA	1
# define LIGHT	2
# define OBJECT	3

# define WHITE	0xFFFFFF
# define BLACK	0x000000



void	my_mlx_pixel_put(t_data *data, int x, int y, t_color color);
int	rt_keybind(int keycode, t_mrt *mrt);
int	close_mrt(t_mrt *mrt);

#endif
