/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_minirt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 03:58:29 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/05 18:47:49 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MINIRT_H
# define RT_MINIRT_H

# define KEY_PRESS	2
# define ON_DESTROY	17

# define WIN_WIDTH	900
# define WIN_HEIGHT	600

# define WHITE	0xFFFFFF
# define BLACK	0x000000

# include <X11/keysym.h>
# include "rt_struct.h"
# include "rt_parse.h"
# include "rt_scene.h"
# include "rt_trace.h"
# include "rt_keybind.h"
# include "rt_utils.h"
# include "rt_utils_vector.h"
# include "rt_utils_color.h"

#endif
