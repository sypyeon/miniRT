/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:17:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 01:58:03 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "utils.h"

t_point	parse_coord(char *param);
t_vec	parse_vec(char *param);
t_color	parse_color(char *value);

t_point	nan_point(void);
t_vec	nan_vec(void);
t_color	nan_color(void);

int		valid_file_fmt(char *file);
void	fvalidate_save(char *file, t_scene *info);
_Bool	split_identify_line(char *line, t_scene *info);

_Bool	init_obj(t_scene *scene, t_obj_type type, char **param);

#endif
