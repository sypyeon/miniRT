/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:17:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/26 22:17:17 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "utils.h"
# include <fcntl.h>

t_vec	parse_vec(char *str);
t_vec	nan_vec(void);
_Bool	is_nanv(t_vec *v);
_Bool	is_color(t_color *c);
size_t	count_obj(t_objs *objs, t_obj_type type);

_Bool	parse_amb(char **toks, t_obj *amb);
_Bool	parse_cam(char **toks, t_obj *cam);
_Bool	parse_light(char **toks, t_obj *light);
_Bool	parse_sphere(char **toks, t_obj *sp);
_Bool	parse_plane(char **toks, t_obj *pl);
_Bool	parse_cylinder(char **toks, t_obj *cy);
_Bool	parse_rt(t_scene *s, char *file);

#endif
