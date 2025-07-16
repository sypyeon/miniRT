/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 06:34:44 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/08 02:19:29 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

_Bool	init_img(t_list *_Nullable *_Nonnull dyn,
						void *_Nonnull mlx, t_img *_Nullable *_Nonnull img)
{
	*img = (t_img *)gc_calloc(dyn, 1, sizeof(t_img));
	if (*img == NULL)
		return (0);
	(*img)->img = mlx_new_image(mlx, PIC_WIDTH, PIC_HEIGHT);
	if ((*img)->img == NULL)
		return (0);
	(*img)->addr = mlx_get_data_addr((*img)->img, &(*img)->bits_per_pixel,
			&(*img)->line_len, &(*img)->endian);
	if ((*img)->addr == NULL)
		return (mlx_destroy_image(mlx, (*img)->img), 0);
	return (1);
}

void	put_pixel(t_img *_Nonnull img, int x, int y, t_dmatrix *_Nonnull color)
{
	int		c;

	c = (int)(255 * *color->ptr->ptr);
	c |= (int)(255 * *color->ptr[1].ptr) << 8;
	c |= (int)(255 * *color->ptr[2].ptr) << 16;
	*((unsigned int *)(img->addr
				+ (y * img->line_len + x * img->bits_per_pixel / 8))) = c;
}

t_rt	*_Nullable	rt_new(t_list *_Nullable *_Nonnull dyn,
						double cam_x, double cam_y, double cam_z)
{
	t_rt	*rt;

	rt = (t_rt *)gc_calloc(dyn, 1, sizeof(t_rt));
	if (rt == NULL)
		return (NULL);
	rt->mlx = mlx_init();
	if (rt->mlx == NULL)
		return (NULL);
	rt->win = mlx_new_window(rt->mlx, PIC_WIDTH, PIC_HEIGHT, "miniRT");
	if (rt->win == NULL)
		return (free(rt->mlx), NULL);
	if (!init_img(dyn, rt->mlx, &rt->img))
		return (mlx_destroy_window(rt->mlx, rt->win), free(rt->mlx), NULL);
	rt->canv = canvas(dyn, PIC_WIDTH, PIC_HEIGHT);
	rt->cam = camera(dyn, rt->canv, __3d_point_col(dyn, cam_x, cam_y, cam_z));
	if (rt->canv == NULL || rt->cam == NULL)
		return (mlx_destroy_image(rt->mlx, rt->img),
			mlx_destroy_window(rt->mlx, rt->win), free(rt->mlx), NULL);
	rt->dyn = dyn;
	return (rt);
}
