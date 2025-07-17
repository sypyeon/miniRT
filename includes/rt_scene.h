/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:42 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/17 19:59:17 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_H
# define RT_SCENE_H

# include "libft.h"
# include "rt_struct.h"
# include "rt_utils_vector.h"
# include "rt_utils_color.h"

t_axis		rt_init_axis(t_vec direction);
t_canvas	rt_init_canvas(int  width, int height);
void		rt_init_camera(t_canvas *canvas, t_point orig, double fov, t_camera *cam);
t_scene		*scene_init(t_light *light);

#endif
