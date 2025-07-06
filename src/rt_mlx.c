/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 06:34:44 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/07 07:14:46 by jaehylee         ###   ########.fr       */
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

void	put_pixel(t_img *_Nonnull img, int x, int y, int color)
{
	*((unsigned int *)(img->addr
				+ (y * img->line_len + x * img->bits_per_pixel / 8))) = color;
}
