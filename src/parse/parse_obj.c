/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/22 21:13:59 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

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
	amb->color = parse_vec(toks[2]);
	if (is_nanv(&amb->color) || amb->color.x < 0 || amb->color.x > 255
		|| amb->color.y < 0 || amb->color.y > 255
		|| amb->color.z < 0 || amb->color.z > 255)
		return (0);
	return (1);
}

_Bool	parse_light(char **toks, t_obj *light)
{
	char	*pos;
	size_t	len;

	len = split_len((const char **)toks);
	if ((len != 3 && len != 4) || ft_strcmp(toks[0], "L"))
		return (0);
	pos = NULL;
	light->type = LIGHT;
	light->data.light.orig = parse_vec(toks[1]);
	if (is_nanv(&light->data.light.orig))
		return (0);
	light->data.light.bright_ratio = ft_strtod(toks[2], &pos);
	if (toks[2] + ft_strlen(toks[2]) != pos
		|| light->data.light.bright_ratio < 0
		|| light->data.light.bright_ratio > 1)
		return (0);
	light->color = nan_vec();
	if (len == 3)
		return (1);
	light->color = parse_vec(toks[3]);
	if (is_nanv(&light->color) || light->color.x < 0 || light->color.x > 255
		|| light->color.y < 0 || light->color.y > 255
		|| light->color.z < 0 || light->color.z > 255)
		return (0);
	return (1);
}
