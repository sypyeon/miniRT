/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_trace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:44:48 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/27 22:06:47 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TRACE_H
# define RT_TRACE_H

# include "libft.h"
# include "rt_struct.h"
# include "rt_vec_utils.h"

t_ray	rt_init_ray(t_point orig, t_vec dir);
t_point	rt_ray_at(t_ray *ray, double t);
t_ray	rt_ray_primary(t_camera *cam, double u, double v);
t_color	rt_ray_color(t_ray *r);

#endif
