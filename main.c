/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:08:03 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/17 20:15:28 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_minirt.h"
#include "mlx.h"

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

char	*rt_dtostr(double num)
{
    char	*str;
    int		int_part;
    int		frac_part;
    int		neg;
    int		i;

    neg = (num < 0);
    if (neg)
        num = -num;
    int_part = (int)num;
    frac_part = (int)((num - int_part) * 100 + 0.5); // 소수점 둘째자리 반올림

    str = malloc(neg + 10); // 부호 + 최대 자리수(정수부 7자리 + '.' + 소수부 2자리 + '\0')
    if (!str)
        return (NULL);

    i = 0;
    if (neg)
        str[i++] = '-';

    // 정수부를 문자열로 변환 (뒤집어서 저장)
    int tmp = int_part;
    int len = 0;
    char buf[12];
    if (tmp == 0)
        buf[len++] = '0';
    else
    {
        while (tmp > 0)
        {
            buf[len++] = (tmp % 10) + '0';
            tmp /= 10;
        }
    }
    // 뒤집어서 str에 저장
    for (int j = len - 1; j >= 0; --j)
        str[i++] = buf[j];

    str[i++] = '.';

    // 소수부 두 자리 변환
    str[i++] = (frac_part / 10) + '0';
    str[i++] = (frac_part % 10) + '0';
    str[i] = '\0';

    return (str);
}

void	rt_display_double(t_mrt *mrt, int x, int y, double value, int color)
{
	char	*str;

	str = rt_dtostr(value);
	if (str && mrt->mlx && mrt->win)
		mlx_string_put(mrt->mlx, mrt->win, x, y, color, str);
	free(str);
}

void	rt_display_camera(t_mrt *mrt, void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 15, WHITE, "Camera");
	mlx_string_put(mlx, win, 10, 30, WHITE, "Coordinates");
	mlx_string_put(mlx, win, 10, 45, WHITE, "x:");
	mlx_string_put(mlx, win, 65, 45, WHITE, "y:");
	mlx_string_put(mlx, win, 120, 45, WHITE, "z:");
	rt_display_double(mrt, 25, 45, mrt->info.cam.origin.x, WHITE);
	rt_display_double(mrt, 80, 45, mrt->info.cam.origin.y, WHITE);
	rt_display_double(mrt, 135, 45, mrt->info.cam.origin.z, WHITE);
	mlx_string_put(mlx, win, 10, 60, WHITE, "Direction");
	mlx_string_put(mlx, win, 10, 75, WHITE, "x:");
	mlx_string_put(mlx, win, 65, 75, WHITE, "y:");
	mlx_string_put(mlx, win, 120, 75, WHITE, "z:");
	rt_display_double(mrt, 25, 75, mrt->info.cam.direction.x, WHITE);
	rt_display_double(mrt, 80, 75, mrt->info.cam.direction.y, WHITE);
	rt_display_double(mrt, 135, 75, mrt->info.cam.direction.z, WHITE);
}

void	rt_display_info(t_mrt *mrt, void *mlx, void *win, int current)
{
	if (current == CAMERA)
		rt_display_camera(mrt, mlx, win);
	else if (current == AMBIENT)
	{
		mlx_string_put(mlx, win, 10, 10, WHITE, "Ambient: ");
		rt_display_double(mrt, 150, 10, mrt->info.amb.amb_ratio, WHITE);
	}
	else if (current == LIGHT)
	{
		mlx_string_put(mlx, win, 10, 10, WHITE, "Light: ");
		mlx_string_put(mlx, win, 150, 10, WHITE, rt_dtostr(mrt->info.light.origin.x));
		mlx_string_put(mlx, win, 150, 30, WHITE, rt_dtostr(mrt->info.light.origin.y));
		mlx_string_put(mlx, win, 150, 50, WHITE, rt_dtostr(mrt->info.light.origin.z));
	}
	else if (current == OBJECT)
	{
		mlx_string_put(mlx, win, 10, 10, WHITE, "Object: ");
		mlx_string_put(mlx, win, 150, 10, WHITE, rt_dtostr(mrt->info.obj_lst.head->center.x));
		mlx_string_put(mlx, win, 150, 30, WHITE, rt_dtostr(mrt->info.obj_lst.head->center.y));
		mlx_string_put(mlx, win, 150, 50, WHITE, rt_dtostr(mrt->info.obj_lst.head->center.z));
	}
}

int	rt_mrt_drawing(t_mrt *mrt)
{
	int     	i;
    int     	j;
    double  	u;
    double  	v;
	t_canvas	canvas;
	// t_object	*obj = mrt->info.obj_lst.head;

	mrt->info.cam.axis = rt_init_axis(mrt->info.cam.direction);
	canvas = rt_init_canvas(WIN_WIDTH, WIN_HEIGHT);
	rt_init_camera(&canvas, mrt->info.cam.origin, mrt->info.cam.fov, &mrt->info.cam);
	// mrt->info.scene = scene_init(&mrt->info.light);
	rt_display_info(mrt, mrt->mlx, mrt->win, mrt->info.current);
	if (mrt->img.ptr != NULL)
		mlx_destroy_image(mrt->mlx, mrt->img.ptr);
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
			mrt->info.ray = rt_ray_primary(&mrt->info.cam, u, v);
			my_mlx_pixel_put(&mrt->img, i, j, rt_ray_color(&mrt->info));
		++i;
		}
	--j;
	}
	mlx_put_image_to_window(mrt->mlx, mrt->win, mrt->img.ptr, 0, 0);
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
	mrt.mlx = mlx_init();
	mrt.win = mlx_new_window(mrt.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	mlx_hook(mrt.win, KEY_PRESS, 1, rt_keybind, &mrt);
	mlx_hook(mrt.win, ON_DESTROY, 0, close_mrt, &mrt);
	mlx_loop_hook(mrt.mlx, rt_mrt_drawing, &mrt);
	mlx_loop(mrt.mlx);
	return (0);
}
