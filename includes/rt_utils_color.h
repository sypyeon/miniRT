/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_color                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:29:44 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 16:04:19 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RT_UTILS_COLOR_H
# define RT_UTILS_COLOR_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "rt_struct.h"

t_color	rt_init_color(double r, double g, double b);
void	rt_set_color(t_color *color, double x, double y, double z);
double	rt_color_len_sq(t_color color);
double	rt_color_len(t_color color);
t_color	rt_color_plus_color(t_color color, t_color color2);
t_color	rt_color_add(t_color color, double x, double y, double z);
t_color	rt_color_minus_color(t_color color, t_color color2);
t_color	rt_color_subtract(t_color color, double x, double y, double z);
t_color	rt_color_mult(t_color color, double t);
t_color	rt_color_x_color(t_color color, t_color color2);
t_color	rt_color_div(t_color color, double t);
double	rt_color_inner(t_color color, t_color color2);
t_color	rt_color_outer(t_color color, t_color color2);
t_color	rt_color_unit(t_color color);
t_color	rt_color_min(t_color color1, t_color color2);

#endif