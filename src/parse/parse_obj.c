/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/22 07:19:26 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

_Bool	parse_amb(char **toks, t_obj *amb)
{
	char	*pos;
	size_t	i;

	i = 0;
	if (ft_strcmp(toks[i++], "A"))
		return (0);
	pos = NULL;
	amb->type = AMBIENT;
	amb->data.amb_ratio = ft_strtod(toks[i], &pos);
	if (toks[i] + ft_strlen(toks[i]) != pos || amb->data.amb_ratio < 0
		|| amb->data.amb_ratio > 1)
		return (0);
	i++;
	amb->color = parse_vec(toks[i++]);
	if (is_nanv(&amb->color) || amb->color.x < 0 || amb->color.x > 255
		|| amb->color.y < 0 || amb->color.y > 255
		|| amb->color.z < 0 || amb->color.z > 255 || toks[i])
		return (0);
	return (1);
}
