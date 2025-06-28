/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_keybind.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:06:34 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 22:46:25 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_KEYBIND_H
# define RT_KEYBIND_H

# define CAMERA	1
# define LIGHT	2
# define OBJECT	3

# include <X11/keysym.h>
# include "rt_struct.h"

bool	rt_rotate_keycodes(int keycode);
bool	rt_moving_keycodes(int keycode);
bool	rt_size_control_keycodes(int keycode);
bool	rt_select_keycodes(int keycode);

#endif
