/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:41:27 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/08 03:09:51 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(void)
{
	size_t		i;
	size_t		j;
	t_list		*dyn;
	t_rt		*rt;

	dyn = NULL;
	rt = rt_new(&dyn, 0.0, 0.0, 0.0);
	j = 0;
	while (++j <= rt->canv->height)
	{
		i = 0;
		while (++i <= rt->canv->width)
		{
			ft_fprintf(STDOUT_FILENO, "i: %u, j: %u", i, j);
			put_pixel(rt->img, i - 1, j - 1, ray_color(&dyn, ray_primary(&dyn,
						rt->cam,
						(double)(i - 1) / (rt->canv->width - 1),
						(double)(rt->canv->height - j + 1)
						/ (rt->canv->height - 1))));
		}
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img, 0, 0);
	mlx_key_hook(rt->win, on_key, rt);
	mlx_hook(rt->win, 0x21, 0, cleanup, rt);
	mlx_loop(rt->mlx);
	return (0);
}

int	on_key(int keycode, t_rt *_Nonnull rt)
{
	(void)rt;
	ft_fprintf(STDOUT_FILENO, "keycode: %d\n", keycode);
	return (0);
}

int	cleanup(t_rt *_Nonnull rt)
{
	mlx_destroy_image(rt->mlx, rt->img);
	mlx_destroy_window(rt->mlx, rt->win);
	mlx_destroy_display(rt->mlx);
	free(rt->mlx);
	gc_free_all(*rt->dyn);
	exit(0);
	return (0);
}
