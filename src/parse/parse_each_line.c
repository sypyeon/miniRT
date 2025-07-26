/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_each_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 23:06:57 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/26 23:26:36 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static _Bool	parse_obj(char **toks, t_objs *objs)
{
	t_obj	*obj;

	if (split_len((const char **)toks) == 0)
		return (0);
	obj = obj_to_push(objs);
	if (!obj)
		return (0);
	if (!ft_strcmp(toks[0], "A"))
		return (parse_amb(toks, obj));
	if (!ft_strcmp(toks[0], "C"))
		return (parse_cam(toks, obj));
	if (!ft_strcmp(toks[0], "L"))
		return (parse_light(toks, obj));
	if (!ft_strcmp(toks[0], "sp"))
		return (parse_sphere(toks, obj));
	if (!ft_strcmp(toks[0], "pl"))
		return (parse_plane(toks, obj));
	if (!ft_strcmp(toks[0], "cy"))
		return (parse_cylinder(toks, obj));
	return (0);
}

_Bool	parse_each_line(t_scene *s, char **lines)
{
	char	**toks;
	size_t	i;

	i = 0;
	while (lines[i])
	{
		toks = ft_split(lines[i], ' ');
		if (!toks)
			return (0);
		if (!parse_obj(toks, &s->objs))
			return (free_split(toks), 0);
		free_split(toks);
		i++;
	}
	return (1);
}
