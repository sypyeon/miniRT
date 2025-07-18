/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:17:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 21:07:46 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define SPHERE		1
# define PLANE		2
# define CYLINDER	3

# include "utils.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

t_point	rt_parse_coordinate(char *param);
t_vec	rt_parse_vector(char *param);
t_color	rt_parse_color(char *value);

double	ft_strtod(char *str);

int		rt_valid_file_format(char *file);
void	rt_file_validate_and_save_data(char *file, t_rt_info *info);

int		rt_init_object(t_rt_info *info, int type, char **param, t_color albedo);

#endif
