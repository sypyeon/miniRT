/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:17:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 18:20:45 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "utils.h"

t_vec	parse_vec(char *param);
t_vec	nan_vec(void);

_Bool	valid_file_fmt(char *file);

t_obj	*parse_cam(t_scene *s, char **toks);
t_obj	*parse_light(char **toks);
t_obj	*parse_sphere(char **toks);
t_obj	*parse_plane(char **toks);
t_obj	*parse_cylinder(char **toks);
t_obj	*parse_amb(char **toks);

_Bool	parse_objs(t_objs *objs, t_scene *s, char **lines);
_Bool	parse_rt(t_scene *s, char *file);

#endif
