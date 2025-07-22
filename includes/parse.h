/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:17:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/22 17:53:55 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "utils.h"

t_vec	parse_vec(char *str);
t_vec	nan_vec(void);
_Bool	is_nanv(t_vec *v);

_Bool	parse_amb(char **toks, t_obj *amb);
_Bool	parse_cam(double aspect_ratio, char **toks, t_obj *cam);
_Bool	parse_light(char **toks, t_obj *light);
t_obj	parse_sphere(char **toks);
t_obj	parse_plane(char **toks);
t_obj	parse_cylinder(char **toks);

_Bool	parse_objs(t_objs *objs, t_scene *s, char **lines);
_Bool	parse_rt(t_scene *s, char *file);

#endif
