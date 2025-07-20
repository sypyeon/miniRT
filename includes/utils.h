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
# include <stdlib.h>
# include <stdio.h>
# include "structures.h"

t_vec		vec3(double x, double y, double z);
t_point		point3(double x, double y, double z);
t_point		color3(double r, double g, double b);
void		vset(t_vec *vec, double x, double y, double z);
double		vlength2(t_vec vec);
double		vlength(t_vec vec);
t_vec		vplus(t_vec vec, t_vec vec2);
t_vec		vplus_(t_vec vec, double x, double y, double z);
t_vec		vminus(t_vec vec, t_vec vec2);
t_vec		vminus_(t_vec vec, double x, double y, double z);
t_vec		vmult(t_vec vec, double t);
t_vec		vmult_(t_vec vec, t_vec vec2);
t_vec		vdivide(t_vec vec, double t);
double		vdot(t_vec vec, t_vec vec2);
t_vec		vcross(t_vec vec, t_vec vec2);
t_vec		vunit(t_vec vec);
t_vec		vmin(t_vec vec1, t_vec vec2);

void		obj_add(t_object **list, t_object *new);
t_object	*obj_last(t_object *list);

void		ft_tab_to_space(char *str);
int			ft_strcmp(const char *str, const char *cmp);
double		ft_strtod(char *str);
void		rt_free_split(char **split);
void		rt_free_obj(t_object *obj);
int			print_err_msg(const char *msg);

#endif
