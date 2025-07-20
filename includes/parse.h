/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:17:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/20 19:25:12 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "utils.h"

t_point3	rt_parse_coordinate(char *param);
t_vec3		rt_parse_vector(char *param);
t_color		rt_parse_color(char *value);

t_point	parse_coordinate(char *param);
t_vec	parse_vector(char *param);
t_color	parse_color(char *value);

int			rt_valid_file_format(char *file);
void		rt_file_validate_and_save_data(char *file, t_rt *info);

int		valid_file_format(char *file);
void	file_validate_and_save_data(char *file, t_scene *scene);

int		rt_init_object(t_scene *scene, int type, char **param);

#endif
