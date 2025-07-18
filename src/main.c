/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/19 01:24:12 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/structures.h"
#include "../includes/utils.h"
#include "../includes/print.h"
#include "../includes/scene.h"
#include "../includes/trace.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->canvas = canvas(400, 300);
	scene->camera = camera(&scene->canvas, point3(0, 0, 0));
	world = object(SP, sphere(point3(-2, 0, -5), 2), color3(0.5, 0, 0));
	obj_add(&world, object(SP, sphere(point3(0, -1000, 0), 995),
			color3(1, 1, 1)));
	obj_add(&world, object(SP, sphere(point3(2, 0, -5), 2), color3(0, 0.5, 0)));
	obj_add(&world, object(SP, sphere(point3(0, -2000, 0), 999),
			color3(1, 1, 1)));
	scene->world = world;
	lights = object(LIGHT_POINT, light_point(point3(0, 20, 0),
				color3(1, 1, 1), 0.5), color3(0, 0, 0));
	lights = object(LIGHT_POINT, light_point(point3(0, 5, 0),
				color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	ka = 0.1;
	scene->ambient = vmult(color3(1, 1, 1), ka);
	return (scene);
}

int	main(void)
{
	int		i;
	int		j;
	t_color	pixel_color;
	t_scene	*scene;

	scene = scene_init();
	printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
	j = scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			scene->ray = ray_primary(&scene->camera,
					(double)i / (scene->canvas.width - 1),
					(double)j / (scene->canvas.height - 1));
			pixel_color = ray_color(scene);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
	return (0);
}
