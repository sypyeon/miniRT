/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:04:47 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/23 04:01:36 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

_Bool	valid_file_fmt(char *file)
{
	size_t	i;
	char	**pieces;
	_Bool	res;

	i = 0;
	if (!file || file[0] == '.' || !ft_strchr(file, '.'))
		return (0);
	pieces = ft_split(file, '.');
	if (!pieces)
		return (0);
	while (pieces[i])
		i++;
	if (i == 0)
		return (free_split(pieces), 0);
	res = ft_strcmp(pieces[i - 1], "rt") == 0;
	return (free_split(pieces), res);
}

_Bool	finish_parse_cy(t_obj *cy)
{
	if (is_nanv(&cy->color) || !is_color(&cy->color))
		return (0);
	cy->data.cy.base = vminus(cy->data.cy.base,
			vscale(vunit(cy->data.cy.norm), cy->data.cy.height / 2));
	return (1);
}
