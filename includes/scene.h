/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../includes/scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:51:16 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 20:42:21 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "../includes/structures.h"
# include "../includes/utils.h"

t_canvas	canvas(int  width, int height);
t_camera	camera(t_canvas *canvas, t_point origin);
t_object	*object(t_object_type type, void *element, t_color albedo);
t_sphere	*sphere(t_point center, double radius);
t_light		*light_point(t_point light_origin, t_color light_color, double bright_ratio);

#endif
