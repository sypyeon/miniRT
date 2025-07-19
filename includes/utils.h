/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:48:13 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/19 09:05:19 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include "structures.h"

t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_point3	color3(double r, double g, double b);
void		vset(t_vec3 *vec, double x, double y, double z);
double		vlength2(t_vec3 vec);
double		vlength(t_vec3 vec);
t_vec		vplus(t_vec3 vec, t_vec3 vec2);
t_vec		vplus_(t_vec3 vec, double x, double y, double z);
t_vec		vminus(t_vec3 vec, t_vec3 vec2);
t_vec		vminus_(t_vec3 vec, double x, double y, double z);
t_vec		vmult(t_vec3 vec, double t);
t_vec		vmult_(t_vec3 vec, t_vec3 vec2);
t_vec		vdivide(t_vec3 vec, double t);
double		vdot(t_vec3 vec, t_vec3 vec2);
t_vec		vcross(t_vec3 vec, t_vec3 vec2);
t_vec		vunit(t_vec3 vec);
t_vec		vmin(t_vec3 vec1, t_vec3 vec2);

void		obj_add(t_obj **list, t_obj *new);
t_obj		*obj_last(t_obj *list);

#endif
