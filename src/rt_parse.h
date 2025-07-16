/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:42 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 15:45:45 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSE_H
# define RT_PARSE_H

# define SPHERE		1
# define PLANE		2
# define CYLINDER	3

# include "../libft/libft.h"
#include "rt_struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_point	rt_parse_coordinate(char *param);
t_vec	rt_parse_vector(char *param);
t_color	rt_parse_color(char *value);

double	rt_strtod(char *str);

int		rt_valid_file_format(char *file);
void	rt_file_validate_and_save_data(char *file, t_rt_info *info);

#endif
