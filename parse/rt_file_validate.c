/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/07 19:40:40 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"
#include "rt_struct.h"
#include "libft.h"
#include <fcntl.h>
 
bool	rt_set_sphere_data(t_obj *obj, char **param, int param_count)
{
	if (param_count != 4)
		return(rt_print_err_msg("invalid sphere data."));
	obj->center = rt_parse_coordinate(param[1]);
	obj->radius = rt_strtod(param[2]) / 2;
	obj->radius2 = obj->radius * obj->radius;
	obj->color = rt_parse_color(param[3]);
	return (0);
}

bool	rt_set_plane_data(t_obj *obj, char **param, int param_count)
{
	if (param_count != 4)
		return(rt_print_err_msg("invalid plane data."));
	obj->center = rt_parse_coordinate(param[1]);
	obj->vector = rt_parse_vector(param[2]);
	obj->color = rt_parse_color(param[3]);
	return (0);
}

int	rt_set_cylinder_data(t_obj *obj, char **param, int param_count)
{
	if (param_count != 6)
		return(rt_print_err_msg("invalid cylinder data."));
	obj->center = rt_parse_coordinate(param[1]);
	obj->vector = rt_parse_vector(param[2]);
	obj->radius = rt_strtod(param[3]) / 2;
	obj->radius2 = obj->radius * obj->radius;
	obj->height = rt_strtod(param[4]);
	obj->color = rt_parse_color(param[5]);
	return (0);
}

void	rt_obj_add_back(t_rt_info *info, t_obj *obj)
{
	if (info->obj.head == NULL)
	{
		info->obj.head = obj;
		info->obj.tail = obj;
	}
	else
	{
		info->obj.tail->next = obj;
		info->obj.tail = obj;
	}
}

int	rt_init_object(t_rt_info *info, int identifier, char **param)
{
	int		valid;
	int		param_count;
	t_obj	*obj;

	valid = 1;
	param_count = 0;
	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!obj)
		return (rt_print_err_msg("error: failed allocation."));
	while (param[param_count])
		param_count++;
	obj->identifier = identifier;
	obj->center = rt_parse_coordinate(param[1]);
	if (identifier == SPHERE)
		valid = rt_set_sphere_data(obj, param, param_count);
	else if (identifier == PLANE)
		valid = rt_set_plane_data(obj, param, param_count);
	else if (identifier == CYLINDER)
		valid = rt_set_cylinder_data(obj, param, param_count);
	rt_obj_add_back(info, obj);
	return (valid);
}

int	rt_set_ambient(t_rt_info *info, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 3)
		return(rt_print_err_msg("invalid ambient data"));
	info->amb.amb_ratio = rt_strtod(param[1]);
	info->amb.color = rt_parse_color(param[2]);
	return (0);
}

int	rt_set_camera(t_rt_info *info, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 4)
		return (rt_print_err_msg("invalid camera data"));
	info->cam.origin = rt_parse_coordinate(param[1]);
	info->cam.direction = rt_parse_vector(param[2]);
	info->cam.fov = ft_atoi(param[3]);
	return (0);
}

int	rt_set_light(t_rt_info *info, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 3 && param_count != 4)
		return (rt_print_err_msg("invalid light data"));
	info->light.orig = rt_parse_coordinate(param[1]);
	info->light.bright = rt_strtod(param[2]);
	info->light.color = rt_parse_color(param[3]);
	return (0);
}

bool	rt_split_and_identify_line(char *line, t_rt_info *info)
{
	bool	invalid;
	char	**split;

	rt_tab_to_space(line);
	split = ft_split(line, ' ');
	invalid = 1;
	if (!split)
		invalid = rt_print_err_msg("Split failure.");
	else if (!rt_strcmp(split[0], "A"))
		invalid = rt_set_ambient(info, split);
	else if (!rt_strcmp(split[0], "C"))
		invalid = rt_set_camera(info, split);
	else if (!rt_strcmp(split[0], "L"))
		invalid = rt_set_light(info, split);
	else if (!rt_strcmp(split[0], "sp"))
		invalid = rt_init_object(info, SPHERE, split);
	else if (!rt_strcmp(split[0], "pl"))
		invalid = rt_init_object(info, PLANE, split);
	else if (!rt_strcmp(split[0], "cy"))
		invalid = rt_init_object(info, CYLINDER, split);
	else
		invalid = rt_print_err_msg("Unknown identifier.");
	rt_free_split(split);
	return (invalid);
}

char	*rt_strjoin_and_free(char *s1, char *s2)
{
	size_t	total_len;
	char	*new_string;

	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)malloc(sizeof(char) * total_len + 1);
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, total_len + 1);
	ft_strlcat(new_string, s2, total_len + 1);
	free(s1);
	free(s2);
	return (new_string);
}

int	rt_is_comma_or_period(char c)
{
	return (c == '.' || c == ',');
}

void	rt_check_numbers_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (rt_is_comma_or_period(line[i]))
		{
			i++;
			if (line[i] == '-' || line[i] == '+')
				i++;
			if (!ft_isdigit(line[i]))
			{
				free(line);
				exit(rt_print_err_msg("Invalid numbers found."));
			}
		}
		i++;
	}
}

char	**rt_gnl_and_split(char *file)
{
	int		fd;
	char	*buf;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(rt_print_err_msg("open failure."));
	line = ft_strdup("");
	while(1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		line = rt_strjoin_and_free(line, buf);
	}
	rt_tab_to_space(line);
	rt_check_numbers_in_line(line);
	split = ft_split(line, '\n');
	free(line);
	return (split);
}

void	rt_file_validate_and_save_data(char *file, t_rt_info *info)
{
	bool	invalid;
	int		i;
	char	**split;

	if (!rt_valid_file_format(file))
		exit(rt_print_err_msg("Wrong file format."));
	split = rt_gnl_and_split(file);
	if (!split)
		exit(rt_print_err_msg("Split failure."));
	i = 0;
	while (split[i])
	{
		invalid = rt_split_and_identify_line(split[i], info);
		if (invalid)
		{
			rt_free_obj(info);
			rt_free_split(split);
			exit (1);
		}
		i++;
	}
	rt_free_split(split);
	info->current_obj = info->obj.head;
}
