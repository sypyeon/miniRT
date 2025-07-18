/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:50:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 17:55:27 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray       ray(t_point orig, t_vec dir);
t_point    ray_at(t_ray *ray, double t);
t_ray       ray_primary(t_camera *cam, double u, double v);
void        set_face_normal(t_ray *r, t_hit_record *rec);
t_color    ray_color(t_scene *scene);

// trace/hit/
t_bool      hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool      hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool      hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);

t_color	phong_lighting(t_scene *scene);
t_bool      in_shadow(t_object *objs, t_ray light_ray, double light_len);
t_color	point_light_get(t_scene *scene, t_light *light);

#endif
