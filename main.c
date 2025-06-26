/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:40:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/26 23:55:40 by sipyeon          ###   ########.fr       */
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

void	rt_mrt_drawing(t_mrt *mrt)
{
	int     i;
    int     j;
    double  r;
    double  g;
    double  b;
	int		color;
    int     canvas_width;
    int     canvas_height;

    canvas_width = 1920;
    canvas_height = 1080;

	mrt->img.ptr = mlx_new_image(mrt->mlx, canvas_width, canvas_height);
	mrt->img.addr = mlx_get_data_addr(mrt->img.ptr, &mrt->img.bits_per_pixel,
								&mrt->img.line_length, &mrt->img.endian);
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
			my_mlx_pixel_put(&mrt->img, i, j, color);
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
	if (keycode == KEY_ESC)
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
	mrt.win = mlx_new_window(mrt.mlx, 1920, 1080, "miniRT");
	rt_mrt_drawing(&mrt);
	mlx_put_image_to_window(mrt.mlx, mrt.win, mrt.img.ptr, 0, 0);
	mlx_hook(mrt.win, KEY_PRESS, 1, rt_keybind, &mrt);
	mlx_hook(mrt.win, ON_DESTROY, 0, close_mrt, &mrt);
	mlx_loop(mrt.mlx);
	return (0);
}
