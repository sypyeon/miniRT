/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:17:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/20 17:12:30 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define SPHERE		1
# define PLANE		2
# define CYLINDER	3

# include "../includes/utils.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

t_point	parse_coordinate(char *param);
t_vec	parse_vector(char *param);
t_color	parse_color(char *value);

double	ft_strtod(char *str);

int		valid_file_format(char *file);
void	file_validate_and_save_data(char *file, t_scene *scene);

int		rt_init_object(t_scene *scene, int type, char **param);

#endif
