/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:48:13 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/24 16:18:41 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdio.h>
# include <float.h>
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
t_vec		vdiv(t_vec v, double d);

int			ft_strcmp(const char *str, const char *cmp);
char		*ft_strjoin_(char *s1, char *s2);
void		free_split(char **split);
size_t		split_len(const char **split);

double		ft_strtod(const char *str, char **str_end);
char		*ft_dtostr(double d); // TODO

void		print_err_ln(const char *msg);

t_obj		*obj_to_push(t_objs *objs);

#endif
