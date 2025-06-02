/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/03 07:06:03 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"
#include "rt_utils.h"
#include "libft.h"
#include <fcntl.h>

t_point	rt_set_coodinate(char *value)
{
	char 	**split;
	t_point	coordinate;

	split = ft_split(value, ',');
	if (!split)
		exit(rt_print_err_msg("split failure."));
	if (!split[0])
		exit(rt_print_err_msg("invalid x coordinate."));
	if (!split[1])
		exit(rt_print_err_msg("invalid y coordinate."));
	if (!split[2])
		exit(rt_print_err_msg("invalid z coordinate."));
	if (split[3])
		exit(rt_print_err_msg("too much coordinate."));
	coordinate.x = rt_strtod(split[0]);
	coordinate.y = rt_strtod(split[1]);
	coordinate.z = rt_strtod(split[2]);
	rt_free_split(split);
	return (coordinate);
}

t_vec	rt_set_vector(char *value)
{
	char 	**split;
	t_vec	vector;

	split = ft_split(value, ',');
	if (!split)
		exit(rt_print_err_msg("split failure."));
	if (!split[0])
		exit(rt_print_err_msg("invalid x vector."));
	if (!split[1])
		exit(rt_print_err_msg("invalid y vector."));
	if (!split[2])
		exit(rt_print_err_msg("invalid z vector."));
	if (split[3])
		exit(rt_print_err_msg("too much vector."));
	vector.x = rt_strtod(split[0]);
	vector.y = rt_strtod(split[1]);
	vector.z = rt_strtod(split[2]);
	rt_free_split(split);
	return (vector);
}

t_color	rt_set_color(char *value)
{
	char 	**split;
	t_color	color;

	split = ft_split(value, ',');
	if (!split)
		exit(rt_print_err_msg("split failure."));
	if (!split[0])
		exit(rt_print_err_msg("invalid red color."));
	if (!split[1])
		exit(rt_print_err_msg("invalid green color."));
	if (!split[2])
		exit(rt_print_err_msg("invalid blue color."));
	if (split[3])
		exit(rt_print_err_msg("too much color."));
	color.r = rt_strtod(split[0]);
	color.g = rt_strtod(split[1]);
	color.b = rt_strtod(split[2]);
	rt_free_split(split);
	return (color);
}

void	rt_set_sphere_data(t_obj *obj, char **value, int split_len)
{
	obj->diameter = rt_strtod(value[2]);
	obj->color = rt_set_color(value[3]);
}

void	rt_set_plane_data(t_obj *obj, char **value, int split_len)
{
	if (split_len != 3)
		rt_print_err_msg()
	obj->vector = rt_set_vector(value[2]);
	obj->color = rt_set_color(value[3]);
}

void	rt_set_cylinder_data(t_obj *obj, char **value, int split_len)
{
	obj->vector = rt_set_vector(value[2]);
	obj->diameter = rt_strtod(value[3]);
	obj->height = rt_strtod(value[4]);
	obj->color = rt_set_color(value[5]);
}

void	rt_init_object(t_rt_info *info, int identifier, char **value)
{
	int		split_len;
	t_obj	*obj;

	split_len = 0;
	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!obj)
		exit(rt_print_err_msg("error: failed allocation."));
	while (value[split_len])
		split_len++;
	obj->identifier = identifier;
	obj->center = rt_set_coodinate(value[1]);
	if (identifier == SPHERE)
		rt_set_sphere_data(obj, value, split_len);
	else if (identifier == PLANE)
		rt_set_plane_data(obj, value, split_len);
	else if (identifier == CYLINDER)
		rt_set_cylinder_data(obj, value, split_len);
}

void	rt_split_and_identify_line(char *line, t_rt_info *info)
{
	char	**split;

	rt_tab_to_space(line);
	split = ft_split(line, ' ');
	if (rt_strcmp(split[0], "A"))
		rt_set_ambient();
	else if (rt_strcmp(split[0], "C"))
		rt_set_camera();
	else if (rt_strcmp(split[0], "L"))
		rt_set_light();
	else if (rt_strcmp(split[0], "sp"))
		rt_init_object(info, SPHERE, split);
	else if (rt_strcmp(split[0], "pl"))
		rt_init_object(info, PLANE, split);
	else if (rt_strcmp(split[0], "cy"))
		rt_init_object(info, CYLINDER, split);
	exit(rt_print_err_msg("Unknown identifier."))
}

void	rt_file_validate_and_save_data(char *file, t_rt_info *info)
{
	int		fd;
	char	*line;

	if (!rt_valid_file_format(file))
		exit (rt_print_err_msg("Wrong file format."));
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		rt_split_and_identify_line(line, info);
	}
}
