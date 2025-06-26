/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:40:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/26 18:03:31 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_minirt.h"
#include "mlx.h"

void	check_parse_data(t_rt_info *info);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	rt_mrt_drawing(t_mrt *mlx)
{
	int     i;
    int     j;
    double  r;
    double  g;
    double  b;
	int		color;
    int     canvas_width;
    int     canvas_height;

    canvas_width = 400;
    canvas_height = 300;

	mlx->img.ptr = mlx_new_image(mlx->mlx, canvas_width, canvas_height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bits_per_pixel,
								&mlx->img.line_length, &mlx->img.endian);
    j = canvas_height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < canvas_width)
        {
            r = (double)i / (canvas_width - 1);
            g = (double)j / (canvas_height - 1);
            b = 0.25;
			color = create_trgb(0, (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 * b));
			my_mlx_pixel_put(&mlx->img, i, j, color);
        ++i;
        }
    --j;
    }
}

int	close_mrt(t_mrt *mrt)
{
	mlx_destroy_image(mrt->mlx, mrt->img.ptr);
	mlx_destroy_window(mrt->mlx, mrt->win);
	mlx_destroy_display(mrt->mlx);
	rt_free_obj(&(mrt->info));
	free(mrt->mlx);
	exit (0);
	return (0);
}

int	rt_keybind(int keycode, t_mrt *mrt)
{
	if (keycode == 65307)
		close_mrt(mrt);
	return (0);
}

int	main(int ac, char **av)
{
	t_mrt	mrt;

	(void)av;
	if (ac != 2)
		return (rt_print_err_msg("Input argument error."));
	ft_bzero(&mrt, sizeof(t_mrt));
	rt_file_validate_and_save_data(av[1], &mrt.info);
	// check_parse_data(&mrt.info);
	mrt.mlx = mlx_init();
	if (!(mrt.mlx))
		return (printf("fuck"));
	mrt.win = mlx_new_window(mrt.mlx, 400, 300, "miniRT");
	rt_mrt_drawing(&mrt);
	mlx_put_image_to_window(mrt.mlx, mrt.win, mrt.img.ptr, 0, 0);
	mlx_hook(mrt.win, 2, 1, rt_keybind, &mrt);
	mlx_hook(mrt.win, 17, 0, close_mrt, &mrt);
	mlx_loop(mrt.mlx);
	return (0);
}
