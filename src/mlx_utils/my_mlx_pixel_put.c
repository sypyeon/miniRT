/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:58:20 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 22:03:47 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mlx_utils.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g,
	unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned int	rt_convert_color(t_color color)
{
	unsigned int	converted;

	converted = create_trgb(0, (int)(255.999 * color.x),
			(int)(255.999 * color.y),
			(int)(255.999 * color.z));
	return (converted);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, t_color color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = rt_convert_color(color);
}
