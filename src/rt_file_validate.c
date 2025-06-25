/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/20 17:35:07 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"
#include "rt_utils.h"
#include "../libft/libft.h"
#include <fcntl.h>
 
void	rt_set_sphere_data(t_obj *obj, char **param, int param_count)
{
	if (param_count != 4)
		rt_print_err_msg("invalid sphere data.");
	obj->center = rt_set_coordinate(param[1]);
	obj->diameter = rt_strtod(param[2]);
	obj->color = rt_set_color(param[3]);
}

void	rt_set_plane_data(t_obj *obj, char **param, int param_count)
{
	if (param_count != 4)
		rt_print_err_msg("invalid plane data.");
	obj->center = rt_set_coordinate(param[1]);
	obj->vector = rt_set_vector(param[2]);
	obj->color = rt_set_color(param[3]);
}

void	rt_set_cylinder_data(t_obj *obj, char **param, int param_count)
{
	if (param_count != 6)
		rt_print_err_msg("invalid cylinder data.");
	obj->center = rt_set_coordinate(param[1]);
	obj->vector = rt_set_vector(param[2]);
	obj->diameter = rt_strtod(param[3]);
	obj->height = rt_strtod(param[4]);
	obj->color = rt_set_color(param[5]);
}

void	rt_obj_add_back(t_rt_info *info, t_obj *obj)
{
	if (!info->obj.head)
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

void	rt_init_object(t_rt_info *info, int identifier, char **param)
{
	int		param_count;
	t_obj	*obj;

	param_count = 0;
	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!obj)
		exit(rt_print_err_msg("error: failed allocation."));
	while (param[param_count])
		param_count++;
	obj->identifier = identifier;
	obj->center = rt_set_coordinate(param[1]);
	if (identifier == SPHERE)
		rt_set_sphere_data(obj, param, param_count);
	else if (identifier == PLANE)
		rt_set_plane_data(obj, param, param_count);
	else if (identifier == CYLINDER)
		rt_set_cylinder_data(obj, param, param_count);
	rt_obj_add_back(info, obj);
}

void	rt_set_ambient(t_rt_info *info, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 3)
		exit(rt_print_err_msg("invalid ambient data"));
	info->amb.amb_ratio = rt_strtod(param[1]);
	info->amb.color = rt_set_color(param[2]);
}

void	rt_set_camera(t_rt_info *info, char **param)
{
	int		param_count;

	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 4)
		exit(rt_print_err_msg("invalid camera data"));
	info->cam.orig = rt_set_coordinate(param[1]);
	info->cam.direction = rt_set_vector(param[2]);
}

void	rt_set_light(t_rt_info *info, char **param)
{
	int		param_count;

	printf("This is light setting \n\n");
	param_count = 0;
	while (param[param_count])
		param_count++;
	if (param_count != 3 && param_count != 4)
		exit(rt_print_err_msg("invalid light data"));
	info->light.orig = rt_set_coordinate(param[1]);
	info->light.bright = rt_strtod(param[2]);
}

void	rt_split_and_identify_line(char *line, t_rt_info *info)
{
	char	**split;

	rt_tab_to_space(line);
	split = ft_split(line, ' ');
	if (!split)
		exit(rt_print_err_msg("Split failure."));
	else if (!rt_strcmp(split[0], "A"))
		rt_set_ambient(info, split);
	else if (!rt_strcmp(split[0], "C"))
		rt_set_camera(info, split);
	else if (!rt_strcmp(split[0], "L"))
		rt_set_light(info, split);
	else if (!rt_strcmp(split[0], "sp"))
		rt_init_object(info, SPHERE, split);
	else if (!rt_strcmp(split[0], "pl"))
		rt_init_object(info, PLANE, split);
	else if (!rt_strcmp(split[0], "cy"))
		rt_init_object(info, CYLINDER, split);
	rt_free_split(split);
	exit(rt_print_err_msg("Unknown identifier."));
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
	split = ft_split(line, '\n');
	free(line);
	return (split);
}

void	rt_file_validate_and_save_data(char *file, t_rt_info *info)
{
	int		i;
	char	**split;

	printf("%s\n", file);
	if (!rt_valid_file_format(file))
		exit(rt_print_err_msg("Wrong file format."));
	split = rt_gnl_and_split(file);
	if (!split)
		exit(rt_print_err_msg("Split failure."));
	i = 0;           
	for (int i = 0; i < 6; i++)
		printf("%s\n", split[i]);
	while (!split[i])
	{
		rt_split_and_identify_line(split[i], info);
		i++;
	}
}
//gnl 다 붙이고 개행 단위로 split해서 파싱해보기
