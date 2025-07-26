/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:18:24 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/26 23:28:56 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

_Bool	parse_cam(char **toks, t_obj *cam)
{
	char	*pos;
	double	fov;

	if (split_len((const char **)toks) != 4 || ft_strcmp(toks[0], "C"))
		return (0);
	cam->type = CAMERA;
	cam->origin = parse_vec(toks[1]);
	if (is_nanv(&cam->origin))
		return (0);
	cam->data.cam.dir = parse_vec(toks[2]);
	if (is_nanv(&cam->data.cam.dir) || fabs(cam->data.cam.dir.x) > 1
		|| fabs(cam->data.cam.dir.y) > 1 || fabs(cam->data.cam.dir.z) > 1)
		return (0);
	pos = NULL;
	fov = ft_strtod(toks[3], &pos);
	if (toks[3] + ft_strlen(toks[3]) != pos || fmod(fov, 1) != 0
		|| fov > 180 || fov < 0)
		return (0);
	cam->data.cam.fov = fov;
	if (cam->data.cam.dir.x == 0 && cam->data.cam.dir.z == 0)
		return (0);
	return (1);
}

_Bool	parse_amb(char **toks, t_obj *amb)
{
	char	*pos;

	if (split_len((const char **)toks) != 3 || ft_strcmp(toks[0], "A"))
		return (0);
	pos = NULL;
	amb->type = AMBIENT;
	amb->data.amb_ratio = ft_strtod(toks[1], &pos);
	if (toks[1] + ft_strlen(toks[1]) != pos || amb->data.amb_ratio < 0
		|| amb->data.amb_ratio > 1)
		return (0);
	amb->color = vdiv(parse_vec(toks[2]), 255.999);
	if (is_nanv(&amb->color) || !is_color(&amb->color))
		return (0);
	return (1);
}

size_t	count_obj(t_objs *objs, t_obj_type type)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (i < objs->size)
	{
		if (objs->ptr[i].type == type)
			count++;
		i++;
	}
	return (count);
}
