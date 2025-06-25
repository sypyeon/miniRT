/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:29:44 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/20 15:40:32 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RT_VEC_UTILS_H
# define RT_VEC_UTILS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
#include "rt_struct.h"

t_vec	rt_init_vec(double x, double y, double z);
t_point	rt_init_point(double x, double y, double z);
t_color	rt_init_color(double r, double g, double b);
void	rt_set_vec(t_vec *vec, double x, double y, double z);
double	rt_vec_length_sq(t_vec vec);
double	rt_vec_length(t_vec vec);
t_vec	rt_vec_plus_vec(t_vec vec, t_vec vec2);
t_vec	rt_vec_add(t_vec vec, double x, double y, double z);
t_vec	rt_vec_minus_vec(t_vec vec, t_vec vec2);
t_vec	rt_vec_subtract(t_vec vec, double x, double y, double z);
t_vec	rt_vec_multiply(t_vec vec, double t);
t_vec	rt_vec_times_vec(t_vec vec, t_vec vec2);
t_vec	rt_vec_divide(t_vec vec, double t);
double	rt_vec_inner(t_vec vec, t_vec vec2);
t_vec	rt_vec_outer(t_vec vec, t_vec vec2);
t_vec	rt_vec_unit(t_vec vec);
t_vec	rt_vec_min(t_vec vec1, t_vec vec2);

#endif