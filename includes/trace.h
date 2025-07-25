/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:50:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/26 05:53:42 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "utils.h"
# include <float.h>

t_ray	ray(t_point orig, t_vec dir);
t_point	ray_at(t_ray *ray, double t);
t_ray	ray_primary(t_obj *cam, double u, double v);
void	set_face_normal(t_ray *r, t_hit_record *rec);
t_color	ray_color(t_scene *scene);

// trace/hit/
_Bool	hit(t_objs *objs, t_ray *ray, t_hit_record *rec);
_Bool	hit_obj(t_obj *obj, t_ray *ray, t_hit_record *rec);
_Bool	hit_sphere(t_obj *world, t_ray *ray, t_hit_record *rec);
_Bool	hit_plane(t_obj *pl_obj, t_ray *ray, t_hit_record *rec);
_Bool	hit_cylinder(t_obj *cy, t_ray *ray, t_hit_record *rec);
_Bool	hit_cylinder6(t_obj *cy_obj, t_ray *ray, t_hit_record *rec,
			double *t_side);

t_color	phong_lighting(t_scene *scene);
_Bool	in_shadow(t_scene *scene, t_vec light_dir);
t_color	point_light_get(t_scene *scene, t_obj *light);

#endif
