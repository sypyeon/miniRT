/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:50:46 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/22 06:36:20 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

_Bool	in_shadow(t_scene *scene, t_vec light_dir)
{
	double			light_len;
	t_ray			light_ray;
	t_hit_record	rec;

	light_len = vlength(light_dir);
	light_ray = ray(vplus(scene->rec.p, vscale(scene->rec.norm, DBL_EPSILON)),
			light_dir);
	rec.tmin = 0;
	rec.tmax = light_len;
	return (hit(scene->objs.ptr, &light_ray, &rec));
}

t_vec	reflect(t_vec v, t_vec n)
{
	return (vminus(v, vscale(n, vdot(v, n) * 2)));
}

t_color	get_specular(t_scene *scene, t_obj *light, t_vec light_dir)
{
	double	ksn;
	double	ks;
	double	spec;
	t_vec	view_dir;
	t_vec	reflect_dir;

	view_dir = vunit(vscale(scene->ray.dir, -1));
	reflect_dir = reflect(vscale(light_dir, -1), scene->rec.norm);
	ksn = 64;
	ks = 0.5;
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
	return (vscale(vscale(light->color, ks), spec));
}

t_color	point_light_get(t_scene *scene, t_obj *light)
{
	t_color	diffuse;
	t_vec	light_dir;
	t_color	specular;
	double	brightness;

	light_dir = vminus(light->origin, scene->rec.p);
	if (in_shadow(&scene->objs, light_dir))
		return (color(0, 0, 0));
	light_dir = vunit(light_dir);
	diffuse = vscale(light->color, fmax(vdot(scene->rec.norm, light_dir), 0.0));
	specular = get_specular(scene, light, light_dir);
	brightness = light->data.light.bright_ratio;
	return (vscale(vplus(diffuse, specular), brightness * LUMEN));
}

// t_color	point_light_get(t_scene *scene, t_obj *light)
// {
// 	t_color	diffuse;
// 	t_vec	light_dir;
// 	double	kd;
// 	t_color	specular;
// 	double	light_len;
// 	t_ray	light_ray;
// 	t_vec	view_dir;
// 	t_vec	reflect_dir;
// 	double	spec;
// 	double	ksn;
// 	double	ks;

// 	light_dir = vminus(light->origin, scene->rec.p);
// 	light_len = vlength(light_dir);
// 	light_ray = ray(vplus(scene->rec.p, vscale(scene->rec.norm, DBL_EPSILON)),
// 			light_dir);
// 	if (in_shadow(&scene->objs, light_ray, light_len))
// 		return (color(0, 0, 0));
// 	light_dir = vunit(light_dir);
// 	kd = fmax(vdot(scene->rec.norm, light_dir), 0.0);
// 	diffuse = vscale(light->color, kd);
// 	view_dir = vunit(vscale(scene->ray.dir, -1));
// 	reflect_dir = reflect(vscale(light_dir, -1), scene->rec.norm);
// 	ksn = 64;
// 	ks = 0.5;
// 	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
// 	specular = vscale(vscale(light->color, ks), spec);
// 	return (vscale(vplus(diffuse, specular), 
//	light->data.light.bright_ratio * LUMEN));
// }

t_color	phong_lighting(t_scene *scene)
{
	int		i;
	t_obj	*lights;
	t_color	light_color;

	light_color = color(0, 0, 0);
	lights = scene->light;
	while (scene->objs.size > i)
	{
		if (lights->type == LIGHT)
			light_color = vplus(light_color, point_light_get(scene, lights));
		i++;
	}
	light_color = vplus(light_color, scene->objs.ptr[scene->amb].color);
	return (vmin(vmult(light_color, scene->rec.albedo), color(1, 1, 1)));
}
