/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/19 01:27:29 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../includes/structures.h"
#include <fcntl.h>

t_bool	rt_set_sphere_data(t_object *obj, char **param, int param_count)
{
	if (param_count != 4)
		return (rt_print_err_msg("invalid sphere data."));
	obj->center = rt_parse_coordinate(param[1]);
	obj->radius = rt_strtod(param[2]) / 2;
	obj->radius2 = obj->radius * obj->radius;
	obj->color = rt_parse_color(param[3]);
	return (0);
}

t_bool	rt_set_plane_data(t_object *obj, char **param, int param_count)
{
	if (param_count != 4)
		return (rt_print_err_msg("invalid plane data."));
	obj->center = rt_parse_coordinate(param[1]);
	obj->vector = rt_parse_vector(param[2]);
	obj->color = rt_parse_color(param[3]);
	return (0);
}

int	rt_set_cylinder_data(t_object *obj, char **param, int param_count)
{
	if (param_count != 6)
		return (rt_print_err_msg("invalid cylinder data."));
	obj->center = rt_parse_coordinate(param[1]);
	obj->vector = rt_parse_vector(param[2]);
	obj->radius = rt_strtod(param[3]) / 2;
	obj->radius2 = obj->radius * obj->radius;
	obj->height = rt_strtod(param[4]);
	obj->color = rt_parse_color(param[5]);
	return (0);
}

void	rt_obj_add_back(t_rt_info *info, t_object *obj)
{
	if (info->obj_lst.head == NULL)
	{
		info->obj_lst.head = obj;
		info->obj_lst.tail = obj;
	}
	else
	{
		info->obj_lst.tail->next = obj;
		info->obj_lst.tail = obj;
	}
}

int	rt_init_object(t_rt_info *info, int type, char **param, t_color albedo)
{
	int			valid;
	int			param_count;
	t_object	*obj;

	valid = 1;
	param_count = 0;
	obj = (t_object *)ft_calloc(1, sizeof(t_object));
	if (!obj)
		return (rt_print_err_msg("error: failed allocation."));
	while (param[param_count])
		param_count++;
	obj->type = type;
	obj->center = rt_parse_coordinate(param[1]);
	if (type == SPHERE)
		valid = rt_set_sphere_data(obj, param, param_count);
	else if (type == PLANE)
		valid = rt_set_plane_data(obj, param, param_count);
	else if (type == CYLINDER)
		valid = rt_set_cylinder_data(obj, param, param_count);
	obj->albedo = albedo;
	rt_obj_add_back(info, obj);
	return (valid);
}
