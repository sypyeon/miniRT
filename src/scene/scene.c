/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:51:51 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 06:58:47 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"

t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_camera	camera(t_canvas *canvas, t_point orig)
{
	t_camera	cam;

	cam.orig = orig;
	cam.focal_len = 1;
	cam.horizontal = vec(2 * canvas->aspect_ratio, 0, 0);
	cam.vertical = vec(0, 2, 0);
	cam.left_bottom = vminus(vminus(vminus(cam.orig,
					vscale(cam.horizontal, 0.5)),
				vscale(cam.vertical, 0.5)), vec(0, 0, cam.focal_len));
	return (cam);
}
