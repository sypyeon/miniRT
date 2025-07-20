/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:17:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/19 09:01:02 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "utils.h"

t_point3	rt_parse_coordinate(char *param);
t_vec3		rt_parse_vector(char *param);
t_color		rt_parse_color(char *value);

double		ft_strtod(char *str);

int			rt_valid_file_format(char *file);
void		rt_file_validate_and_save_data(char *file, t_rt *info);

int			rt_init_object(t_rt *info, int type, char **param, t_color albedo);

#endif
