/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:40:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 19:57:45 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_minirt.h"
#include "mlx.h"

void	check_parse_data(t_rt_info *info);

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned int	rt_convert_color(t_color color)
{
	unsigned int	converted;

	converted = create_trgb(0, (int)(255.999 * color.r),\
							(int)(255.999 * color.g),	\
							(int)(255.999 * color.b));
	return (converted);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, t_color color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = rt_convert_color(color);
}

void	rt_mrt_drawing(t_mrt *mrt)
{
	int     	i;
    int     	j;
    double  	u;
    double  	v;
	t_color		pixel_color;
	t_canvas	canvas;
	t_ray		ray;
	t_obj		*obj = mrt->info.obj.head;

	canvas = rt_init_canvas(WIN_WIDTH, WIN_HEIGHT);
	mrt->info.cam = rt_init_camera(&canvas, mrt->info.cam.origin, mrt->info.cam.fov);
	mrt->img.ptr = mlx_new_image(mrt->mlx, canvas.width, canvas.height);
	mrt->img.addr = mlx_get_data_addr(mrt->img.ptr, &mrt->img.bits_per_pixel,
								&mrt->img.line_length, &mrt->img.endian);
    j = canvas.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < canvas.width)
        {
            u = (double)i / (canvas.width - 1);
            v = (double)j / (canvas.height - 1);
			ray = rt_ray_primary(&mrt->info.cam, u, v);
			pixel_color = rt_ray_color(&ray, obj);
			my_mlx_pixel_put(&mrt->img, i, j, pixel_color);
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
	if (keycode == XK_Escape)
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
	mrt.win = mlx_new_window(mrt.mlx, 1920, 1080, "miniRT");
	rt_mrt_drawing(&mrt);
	mlx_put_image_to_window(mrt.mlx, mrt.win, mrt.img.ptr, 0, 0);
	mlx_hook(mrt.win, KEY_PRESS, 1, rt_keybind, &mrt);
	mlx_hook(mrt.win, ON_DESTROY, 0, close_mrt, &mrt);
	mlx_loop(mrt.mlx);
	return (0);
}
