/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keybind.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:06:34 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/29 19:23:09 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_KEYBIND_H
# define RT_KEYBIND_H

# define CAMERA	1
# define LIGHT	2
# define OBJECT	3

# include <X11/keysym.h>
# include "mlx.h"
# include "rt_utils.h"
# include "rt_struct.h"

int		close_mrt(t_mrt *mrt);
int		rt_keybind(int keycode, t_mrt *mrt);

bool	rt_rotate_keycodes(int keycode);
bool	rt_moving_keycodes(int keycode);
bool	rt_size_control_keycodes(int keycode);
bool	rt_select_keycodes(int keycode);

#endif
