/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:51:51 by sipyeon           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/21 18:56:40 by sipyeon          ###   ########.fr       */
=======
/*   Updated: 2025/07/21 18:40:36 by jaehylee         ###   ########.fr       */
>>>>>>> a5cf3c1431869d13ef49e5b5ead75029f67c81d8
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/scene.h"

t_camera	camera(double aspect_ratio, t_point orig)
{
	t_camera	cam;

	cam.orig = orig;
	cam.focal_len = 1;
	cam.horizontal = vec(2 * aspect_ratio, 0, 0);
	cam.vertical = vec(0, 2, 0);
	cam.left_bottom = vminus(vminus(vminus(cam.orig,
					vscale(cam.horizontal, 0.5)),
				vscale(cam.vertical, 0.5)), vec(0, 0, cam.focal_len));
	return (cam);
}
