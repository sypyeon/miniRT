/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 01:42:29 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../includes/structures.h"
#include <fcntl.h>

_Bool	parse_sphere(t_sphere *sp, char **param, int param_count)
{
	if (param_count != 4)
		return (print_err_ln("invalid sphere data."), 0);
	sp->center = parse_coord(param[1]);
	sp->radius = ft_strtod(param[2]) / 2;
	sp->color = parse_color(param[3]);
	return (1);
}

_Bool	parse_plane(t_plane *pl, char **param, int param_count)
{
	if (param_count != 4)
		return (print_err_ln("invalid plane data."), 0);
	pl->base = parse_coord(param[1]);
	pl->norm = parse_vec(param[2]);
	pl->color = parse_color(param[3]);
	return (1);
}

int	parse_cylinder(t_cylinder *cy, char **param, int param_count)
{
	if (param_count != 6)
		return (print_err_ln("invalid cylinder data."), 0);
	cy->base = parse_coord(param[1]);
	cy->height_norm = vscale(vunit(parse_vec(param[2])), ft_strtod(param[4]));
	cy->radius = ft_strtod(param[3]) / 2;
	cy->color = parse_color(param[5]);
	return (1);
}

_Bool	init_obj(t_scene *scene, t_obj_type type, char **param)
{
	_Bool	valid;
	int		param_count;
	t_obj	*obj;

	valid = 1;
	param_count = 0;
	obj = (t_obj *)ft_calloc(1, sizeof(t_obj));
	if (!obj)
		return (print_err_ln("error: failed allocation."), 0);
	while (param[param_count])
		param_count++;
	obj->type = type;
	if (type == SPHERE)
		valid = parse_sphere(obj, param, param_count);
	else if (type == PLANE)
		valid = parse_plane(obj, param, param_count);
	else if (type == CYLINDER)
		valid = parse_cylinder(obj, param, param_count);
	obj_add(&scene->obj, obj);
	return (valid);
}
