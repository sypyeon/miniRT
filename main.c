/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:40:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/05 18:50:03 by sipyeon          ###   ########.fr       */
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

void	rt_display_camera(t_mrt *mrt, void *mlx, void *win)
{
	mlx_string_put(mlx, win, 10, 10, WHITE, "Camera: ");
	mlx_string_put(mlx, win, 150, 10, WHITE, rt_dtostr(mrt->info.cam.origin.x));
	mlx_string_put(mlx, win, 150, 30, WHITE, rt_dtostr(mrt->info.cam.origin.y));
	mlx_string_put(mlx, win, 150, 50, WHITE, rt_dtostr(mrt->info.cam.origin.z));
	mlx_string_put(mlx, win, 150, 70, WHITE, rt_dtostr(mrt->info.cam.direction.x));
	mlx_string_put(mlx, win, 150, 90, WHITE, rt_dtostr(mrt->info.cam.direction.y));
	mlx_string_put(mlx, win, 150, 110, WHITE, rt_dtostr(mrt->info.cam.direction.z));
}

void	rt_display_info(t_mrt *mrt, void *mlx, void *win, enum e_current current)
{
	if (current == CAMERA)
		rt_display_camera(mrt, mlx, win);
	else if (current == AMBIENT)
	{
		mlx_string_put(mlx, win, 10, 10, WHITE, "Ambient: ");
		mlx_string_put(mlx, win, 150, 10, WHITE, rt_dtostr(mrt->info.amb.amb_ratio));
	}
	else if (current == LIGHT)
	{
		mlx_string_put(mlx, win, 10, 10, WHITE, "Light: ");
		mlx_string_put(mlx, win, 150, 10, WHITE, rt_dtostr(mrt->info.light.orig.x));
		mlx_string_put(mlx, win, 150, 30, WHITE, rt_dtostr(mrt->info.light.orig.y));
		mlx_string_put(mlx, win, 150, 50, WHITE, rt_dtostr(mrt->info.light.orig.z));
	}
	else if (current == OBJECT)
	{
		mlx_string_put(mlx, win, 10, 10, WHITE, "Object: ");
		mlx_string_put(mlx, win, 150, 10, WHITE, rt_dtostr(mrt->info.obj.head->center.x));
		mlx_string_put(mlx, win, 150, 30, WHITE, rt_dtostr(mrt->info.obj.head->center.y));
		mlx_string_put(mlx, win, 150, 50, WHITE, rt_dtostr(mrt->info.obj.head->center.z));
	}
}

int	rt_mrt_drawing(t_mrt *mrt)
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
	rt_init_camera(&canvas, mrt->info.cam.origin, mrt->info.cam.fov, &mrt->info.cam);
	rt_display_info(mrt, mrt->mlx, mrt->win, mrt->info.current);
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
	// check_parse_data(&mrt.info);
	mrt.mlx = mlx_init();
	mrt.win = mlx_new_window(mrt.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	mlx_hook(mrt.win, KEY_PRESS, 1, rt_keybind, &mrt);
	mlx_hook(mrt.win, ON_DESTROY, 0, close_mrt, &mrt);
	mlx_loop_hook(mrt.mlx, rt_mrt_drawing, &mrt);
	mlx_loop(mrt.mlx);
	return (0);
}
