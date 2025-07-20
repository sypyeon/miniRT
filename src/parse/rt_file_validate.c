/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/20 17:13:09 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../includes/structures.h"
#include "../../includes/utils.h"
#include "../../libft/libft.h"
#include <fcntl.h>
 
bool	rt_set_sphere_data(t_sphere *sp, char **param, int param_count)
{
	if (param_count != 4)
		return(print_err_msg("invalid sphere data."));
	sp->center = parse_coordinate(param[1]);
	sp->radius = rt_strtod(param[2]) / 2;
	sp->radius2 = sp->radius * sp->radius;
	sp->color = parse_color(param[3]);
	return (0);
}

bool	rt_set_plane_data(t_plane *pl, char **param, int param_count)
{
	if (param_count != 4)
		return(print_err_msg("invalid plane data."));
	pl->center = parse_coordinate(param[1]);
	pl->vector = parse_vector(param[2]);
	pl->color = parse_color(param[3]);
	return (0);
}

int	rt_set_cylinder_data(t_cylinder *cy, char **param, int param_count)
{
	if (param_count != 6)
		return(print_err_msg("invalid cylinder data."));
	cy->center = parse_coordinate(param[1]);
	cy->vector = parse_vector(param[2]);
	cy->radius = rt_strtod(param[3]) / 2;
	cy->radius2 = cy->radius * cy->radius;
	cy->height = rt_strtod(param[4]);
	cy->color = parse_color(param[5]);
	return (0);
}

void	rt_obj_add_back(t_object *obj, t_object *new)
{
	if (!new)
		return ;
	if (!obj)
	{
		obj = new;
		new->next = NULL;
		return ;
	}
	while (obj->next)
		obj = obj->next;
	obj->next = new;
	new->next = NULL;
}

int	rt_init_object(t_scene *scene, int type, char **param)
{
	int		valid;
	int		param_count;
	t_object	*obj;

	valid = 1;
	param_count = 0;
	obj = (t_object *)ft_calloc(1, sizeof(t_object));
	if (!obj)
		return (print_err_msg("error: failed allocation."));
	while (param[param_count])
		param_count++;
	obj->type = type;
	if (type == SPHERE)
		valid = rt_set_sphere_data(obj, param, param_count);
	else if (type == PLANE)
		valid = rt_set_plane_data(obj, param, param_count);
	else if (type == CYLINDER)
		valid = rt_set_cylinder_data(obj, param, param_count);
	rt_obj_add_back(scene->object, obj);
	return (valid);
}

int	rt_set_ambient(t_scene *scene, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 3)
		return(print_err_msg("invalid ambient data"));
	scene->amb.ratio = rt_strtod(param[1]);
	scene->amb.color = parse_color(param[2]);
	return (0);
}

int	rt_set_camera(t_scene *scene, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 4)
		return (print_err_msg("invalid camera data"));
	scene->camera.orig = parse_coordinate(param[1]);
	scene->camera.direction = parse_vector(param[2]);
	scene->camera.fov = ft_atoi(param[3]);
	return (0);
}

int	rt_set_light(t_scene *scene, char **param)
{
	int		param_count;
	t_light	light;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 3 && param_count != 4)
		return (print_err_msg("invalid light data"));
	light.origin = parse_coordinate(param[1]);
	light.bright_ratio = rt_strtod(param[2]);
	light.color = parse_color(param[3]);
	return (0);
}

bool	rt_split_and_identify_line(char *line, t_scene *scene)
{
	bool	invalid;
	char	**split;

	rt_tab_to_space(line);
	split = ft_split(line, ' ');
	invalid = 1;
	if (!split)
		invalid = print_err_msg("Split failure.");
	else if (!rt_strcmp(split[0], "A"))
		invalid = rt_set_ambient(scene, split);
	else if (!rt_strcmp(split[0], "C"))
		invalid = rt_set_camera(scene, split);
	else if (!rt_strcmp(split[0], "L"))
		invalid = rt_set_light(scene, split);
	else if (!rt_strcmp(split[0], "sp"))
		invalid = rt_init_object(scene, SPHERE, split);
	else if (!rt_strcmp(split[0], "pl"))
		invalid = rt_init_object(scene, PLANE, split);
	else if (!rt_strcmp(split[0], "cy"))
		invalid = rt_init_object(scene, CYLINDER, split);
	else
		invalid = print_err_msg("Unknown type.");
	rt_free_split(split);
	return (invalid);
}

char	*strjoin_and_free(char *s1, char *s2)
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

int	ft_is_comma_or_period(char c)
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
				exit(print_err_msg("Invalid numbers found."));
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
		exit(print_err_msg("open failure."));
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

void	file_validate_and_save_data(char *file, t_scene *scene)
{
	bool	invalid;
	int		i;
	char	**split;

	if (!valid_file_format(file))
		exit(print_err_msg("Wrong file format."));
	split = rt_gnl_and_split(file);
	if (!split)
		exit(print_err_msg("Split failure."));
	i = 0;
	while (split[i])
	{
		invalid = rt_split_and_identify_line(split[i], scene);
		if (invalid)
		{
			rt_free_obj(scene);
			rt_free_split(split);
			exit (1);
		}
		i++;
	}
	rt_free_split(split);
}
