/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_phong_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:09:54 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/17 19:54:17 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_trace.h"
#define LUMEN 3

t_vec	reflect(t_vec v, t_vec n)
{
    //v - 2 * dot(v, n) * n;
    return (rt_vec_minus_vec(v, rt_vec_mult(n, rt_vec_inner(v, n) * 2)));
}

t_color	point_light_get(t_scene *scene, t_light *light)
{
    t_color	diffuse;
    t_vec	light_dir;
    double	kd;
    t_color	specular;
    t_vec	view_dir;
    t_vec	reflect_dir;
    double	spec;
    double	ksn;
    double	ks;
    /* * * * 추가 * * * */
    double      brightness;
    /* * * * 추가 끝 * * * */

    light_dir = rt_vec_unit(rt_vec_minus_vec(light->origin, scene->rec.p));
    kd = fmax(rt_vec_inner(scene->rec.normal, light_dir), 0.0);// diffuse strength;
    diffuse = rt_color_mult(light->color, kd);
    view_dir = rt_vec_unit(rt_vec_mult(scene->ray.direction, -1));
    reflect_dir = reflect(rt_vec_mult(light_dir, -1), scene->rec.normal);
    ksn = 64; // shininess value
    ks = 0.5; // specular strength;
    spec = pow(fmax(rt_vec_inner(view_dir, reflect_dir), 0.0), ksn);
    specular = rt_color_mult(rt_color_mult(light->color, ks), spec);
    /* * * * 수정 * * * */
    brightness = light->bright * LUMEN; // 기준 광속/광량을 정의한 매크로
    return (rt_color_mult(rt_color_plus_color(diffuse, specular), brightness));
    /* * * * 수정 끝 * * * */
}

t_color	phong_lighting(t_scene *scene, t_light *light)
{
    t_color		light_color;
    // t_object	*obj;

    light_color = light->color; //광원이 하나도 없다면, 빛의 양은 (0, 0, 0)일 것이다.
    // obj = scene->light;
    // while (obj) //여러 광원에서 나오는 모든 빛에 대해 각각 diffuse, specular 값을 모두 구해줘야 한다
    // {
    //     if(obj->type == LIGHT)
    //         light_color = rt_color_plus_color(light_color, point_light_get(scene, obj));
    //     obj = obj->next;
    // }
	light_color = rt_color_plus_color(light_color, point_light_get(scene, light));
    light_color = rt_color_plus_color(light_color, scene->ambient);
    return (rt_color_min(rt_color_x_color(light_color, scene->rec.albedo), rt_init_color(1, 1, 1)));
    //모든 광원에 의한 빛의 양을 구한 후, 오브젝트의 반사율과 곱해준다. 그 값이 (1, 1, 1)을 넘으면 (1, 1, 1)을 반환한다.
}
