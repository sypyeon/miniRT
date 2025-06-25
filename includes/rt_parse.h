/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:42 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/20 15:05:19 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSE_H
# define RT_PARSE_H

# define SPHERE		1
# define PLANE		2
# define CYLINDER	3

# include "libft.h"
# include "rt_struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_point	rt_set_coordinate(char *param);
t_vec	rt_set_vector(char *param);
t_color	rt_set_color(char *value);

double	rt_strtod(char *str);

int		rt_valid_file_format(char *file);
void	rt_file_validate_and_save_data(char *file, t_rt_info *info);

#endif
