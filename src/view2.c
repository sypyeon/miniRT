/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 02:54:36 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/07 06:34:21 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_camera	*_Nullable	camera(t_list *_Nullable *_Nonnull dyn,
						t_canvas *_Nonnull canvas, t_dmatrix *_Nonnull orig)
{
	t_camera	*cam;
	t_dmatrix	*half_horiz;
	t_dmatrix	*half_vert;

	cam = (t_camera *)gc_calloc(dyn, 1, sizeof(t_camera));
	if (cam == NULL)
		return (NULL);
	cam->orig = *orig;
	cam->viewport_h = 2.0;
	cam->viewport_w = cam->viewport_h * canvas->aspect_ratio;
	cam->focal_len = 1.0;
	cam->horizontal = *__3d_point_col(dyn, cam->viewport_w, 0.0, 0.0);
	cam->vertical = *__3d_point_col(dyn, 0.0, cam->viewport_h, 0.0);
	half_horiz = _matcpy(dyn, &cam->horizontal);
	matscale(0.5, half_horiz);
	half_vert = _matcpy(dyn, &cam->vertical);
	matscale(0.5, half_vert);
	cam->left_bottom = *_matsub(dyn, _matsub(dyn, _matsub(dyn, &cam->orig,
					half_horiz), half_vert),
			__3d_point_col(dyn, 0.0, 0.0, cam->focal_len));
	return (cam);
}

t_ray	*_Nullable	ray_primary(t_list *_Nullable *_Nonnull dyn,
						t_camera *_Nonnull cam, double u, double v)
{
	t_dmatrix	*u_horiz;
	t_dmatrix	*v_vert;

	u_horiz = _matcpy(dyn, &cam->horizontal);
	matscale(u, u_horiz);
	v_vert = _matcpy(dyn, &cam->vertical);
	matscale(v, v_vert);
	return (ray(dyn, &cam->orig, _matsub(dyn, _matadd(dyn,
					_matadd(dyn, &cam->left_bottom, u_horiz), v_vert),
				&cam->orig)));
}

t_dmatrix	*_Nullable	ray_color(t_list *_Nullable *_Nonnull dyn,
						t_ray *_Nonnull r)
{
	double		t;
	t_dmatrix	*white;
	t_dmatrix	*blue;

	t = 0.5 * (*r->dir.ptr[1].ptr + 1.0);
	white = __3d_point_col(dyn, 1.0, 1.0, 1.0);
	matscale(1.0 - t, white);
	blue = __3d_point_col(dyn, 0.5, 0.7, 1.0);
	matscale(t, blue);
	return (_matadd(dyn, white, blue));
}
