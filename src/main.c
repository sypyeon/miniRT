#include <stdio.h>
#include "../includes/structures.h"
#include "../includes/utils.h"
#include "../includes/print.h"
#include "../includes/scene.h"
#include "../includes/trace.h"
#include "../libft/libft.h"
#include "../includes/mlx_utils.h"
#include "../includes/parse.h"

t_scene *scene_init(void)
{
    t_scene     *scene;
    t_object    *world;
    t_object    *lights;
    double      ka; // 8.4 에서 설명

    // malloc 할당 실패 시, 실습에서는 return NULL로 해두었지만, 적절한 에러 처리가 필요하다.
    if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
        return (NULL);
    scene->canvas = canvas(400, 300);
    scene->camera = camera(&scene->canvas, point3(0, 0, 0));
    world = object(SP, sphere(point3(-2, 0, -5), 2), color3(0.5, 0, 0)); // world 에 구1 추가
    obj_add(&world, object(SP, sphere(point3(0, -1000, 0), 995), color3(1, 1, 1))); // world 에 구3 추가
    obj_add(&world, object(SP, sphere(point3(2, 0, -5), 2), color3(0, 0.5, 0))); // world 에 구2 추가
    obj_add(&world, object(SP, sphere(point3(0, -2000, 0), 999), color3(1, 1, 1))); // world 에 구3 추가
    scene->object = world;
    lights = object(LIGHT_POINT, light_point(point3(0, 20, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0)); // 더미 albedo
    lights = object(LIGHT_POINT, light_point(point3(0, 5, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0)); // 더미 albedo
    scene->light = lights;
    ka = 0.1; // 8.4 에서 설명
	scene->amb.ratio = ka;
    scene->amb.color = vmult(color3(1,1,1), ka); // 8.4 에서 설명
    return (scene);
}

t_axis init_axis(t_vec direction)
{
	t_axis axis;

	axis.z = vec3(direction.x, direction.y, direction.z);
	axis.x = vunit(vcross(axis.z, vec3(0, 1, 0)));
	axis.y = vunit(vcross(axis.x, axis.z));
	return (axis);
}

void rt_init_camera(t_canvas *canvas, t_point orig, double fov, t_camera *cam)
{
	t_vec right;
	double focal_len;
	double fov_rad;
	t_vec world_up = cam->axis.y;

	focal_len = 1.0;
	cam->orig = orig;
	fov_rad = fov * 3.141592 / 180.0;
	cam->viewport_h = 2.0 * tan(fov_rad / 2.0) * focal_len;
	cam->viewport_w = cam->viewport_h * canvas->aspect_ratio;
	cam->focal_len = focal_len;
	right = vunit(vcross(cam->direction, world_up));
	cam->horizontal = vmult(right, cam->viewport_w);
	cam->vertical = vmult(vunit(
						vcross(right, cam->direction)),
					cam->viewport_h);
	cam->left_bottom = vminus(vminus(vminus(cam->orig, vdivide(cam->horizontal, 2)),
											vdivide(cam->vertical, 2)),
										cam->direction);
	printf("cam->left_bottom: %f, %f, %f\n", cam->left_bottom.x, cam->left_bottom.y, cam->left_bottom.z);
	cam->axis = init_axis(cam->direction);
}


t_canvas init_canvas(int width, int height)
{
	t_canvas canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

int	mrt_drawing(t_mrt *mrt)
{
	int     	i;
    int     	j;
    double  	u;
    double  	v;
	t_canvas	canvas;

	mrt->scene.camera.axis = init_axis(mrt->scene.camera.direction);
	canvas = init_canvas(WIN_WIDTH, WIN_HEIGHT);
	rt_init_camera(&canvas, mrt->scene.camera.orig, mrt->scene.camera.fov, &mrt->scene.camera);
	// rt_display_info(mrt, mrt->mlx, mrt->win, mrt->scene.current);
	if (mrt->img.ptr != NULL)
		mlx_destroy_image(mrt->mlx, mrt->img.ptr);
	mrt->img.ptr = mlx_new_image(mrt->mlx, canvas.width, canvas.height);
	mrt->img.addr = mlx_get_data_addr(mrt->img.ptr, &mrt->img.bits_per_pixel,
								&mrt->img.line_length, &mrt->img.endian);
	j = mrt->scene.canvas.height - 1;
	while (j >= 0)
	{
        i = 0;
        while (i < mrt->scene.canvas.width)
		{
			u = (double)i / (mrt->scene.canvas.width - 1);
			v = (double)j / (mrt->scene.canvas.height - 1);
			//ray from camera origin to pixel
			mrt->scene.ray = ray_primary(&mrt->scene.camera, u, v);
			my_mlx_pixel_put(&mrt->img, i, j, ray_color(&mrt->scene));
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

	if (ac != 2)
		return (print_err_msg("Input argument error."));
	ft_bzero(&mrt, sizeof(t_mrt));
	file_validate_and_save_data(av[1], &mrt.scene);
	mrt.mlx = mlx_init();
	mrt.win = mlx_new_window(mrt.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	mlx_hook(mrt.win, KEY_PRESS, 1, rt_keybind, &mrt);
	mlx_hook(mrt.win, ON_DESTROY, 0, close_mrt, &mrt);
	mlx_loop_hook(mrt.mlx, mrt_drawing, &mrt);
	mlx_loop(mrt.mlx);
	// 랜더링
	// P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
	return (0);
}
