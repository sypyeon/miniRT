/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:44:48 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/15 15:36:37 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TRACE_H
# define RT_TRACE_H

# define SPHERE		1
# define PLANE		2
# define CYLINDER	3

# include "libft.h"
# include "rt_struct.h"
# include "rt_utils_color.h"
# include "rt_utils_vector.h"

t_ray	rt_init_ray(t_point orig, t_vec dir);
t_point	rt_ray_at(t_ray *ray, double t);
t_ray	rt_ray_primary(t_camera *cam, double u, double v);
t_color	rt_ray_color(t_ray *ray, t_obj *obj);

bool	rt_hit(t_obj *obj, t_ray *ray, t_hit_record *rec);
bool	rt_hit_obj(t_obj *obj, t_ray *ray, t_hit_record *rec);
bool	rt_hit_sphere(t_obj *sp, t_ray *ray, t_hit_record *rec);

#endif
