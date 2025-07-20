/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:48:13 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 06:25:17 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdio.h>
# include "structures.h"

t_vec		vec(double x, double y, double z);
t_point		point(double x, double y, double z);
t_point		color(double r, double g, double b);
double		vlength2(t_vec vec);
double		vlength(t_vec vec);
t_vec		vplus(t_vec vec, t_vec vec2);
t_vec		vminus(t_vec vec, t_vec vec2);
t_vec		vscale(t_vec vec, double t);
t_vec		vmult(t_vec vec, t_vec vec2);
double		vdot(t_vec vec, t_vec vec2);
t_vec		vcross(t_vec vec, t_vec vec2);
t_vec		vunit(t_vec vec);
t_vec		vmin(t_vec vec1, t_vec vec2);

void		obj_add(t_obj **list, t_obj *new);
t_obj		*obj_last(t_obj *list);
void		free_obj(t_obj *obj);

int			ft_strcmp(const char *str, const char *cmp);
double		ft_strtod(char *str);
void		free_split(char **split);
void		print_err_ln(const char *msg);
char		*ft_strjoin_(char *s1, char *s2);
double		ft_strtod(char *str);

#endif
