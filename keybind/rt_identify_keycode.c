/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_identify_keycode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:58:54 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/30 18:17:48 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_keybind.h"

bool	rt_rotate_keycodes(int keycode)
{
	return (keycode == XK_e || keycode == XK_r || keycode == XK_d	\
			|| keycode == XK_f || keycode == XK_c || keycode == XK_v);
}

bool	rt_moving_keycodes(int keycode)
{
	return (keycode == XK_q || keycode == XK_w || keycode == XK_a	\
			|| keycode == XK_s || keycode == XK_z || keycode == XK_x);
}

bool	rt_size_control_keycodes(int keycode)
{
	return (keycode == XK_plus || keycode == XK_minus);
}

bool	rt_select_keycodes(int keycode)
{
	return (keycode == XK_1 || keycode == XK_2 || keycode == XK_3);
}
