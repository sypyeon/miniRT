/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:46:12 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/24 16:28:36 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

_Bool	parse_light(char **toks, t_obj *light)
{
	char	*pos;
	size_t	len;

	len = split_len((const char **)toks);
	if ((len != 3 && len != 4) || ft_strcmp(toks[0], "L"))
		return (0);
	pos = NULL;
	light->type = LIGHT;
	light->origin = parse_vec(toks[1]);
	if (is_nanv(&light->origin))
		return (0);
	light->data.light.bright_ratio = ft_strtod(toks[2], &pos);
	if (toks[2] + ft_strlen(toks[2]) != pos
		|| light->data.light.bright_ratio < 0
		|| light->data.light.bright_ratio > 1)
		return (0);
	light->color = nan_vec();
	if (len == 3)
		return (1);
	light->color = vdiv(parse_vec(toks[3]), 255);
	if (is_nanv(&light->color) || !is_color(&light->color))
		return (0);
	return (1);
}

_Bool	parse_sphere(char **toks, t_obj *sp)
{
	char	*pos;

	if (split_len((const char **)toks) != 4 || ft_strcmp(toks[0], "sp"))
		return (0);
	pos = NULL;
	sp->type = SPHERE;
	sp->origin = parse_vec(toks[1]);
	if (is_nanv(&sp->origin))
		return (0);
	sp->data.sp.radius = ft_strtod(toks[2], &pos);
	if (toks[2] + ft_strlen(toks[2]) != pos || sp->data.sp.radius < 0
		|| sp->data.sp.radius < 2 * DBL_EPSILON)
		return (0);
	sp->data.sp.radius /= 2;
	sp->data.sp.radius2 = sp->data.sp.radius * sp->data.sp.radius;
	if (sp->data.sp.radius2 < 1e-15)
		return (0);
	sp->color = vdiv(parse_vec(toks[3]), 255);
	if (is_nanv(&sp->color) || !is_color(&sp->color))
		return (0);
	return (1);
}

_Bool	parse_plane(char **toks, t_obj *pl)
{
	if (split_len((const char **)toks) != 4 || ft_strcmp(toks[0], "pl"))
		return (0);
	pl->type = PLANE;
	pl->origin = parse_vec(toks[1]);
	if (is_nanv(&pl->origin))
		return (0);
	pl->data.pl.norm = parse_vec(toks[2]);
	if (is_nanv(&pl->data.pl.norm) || fabs(pl->data.pl.norm.x) > 1
		|| fabs(pl->data.pl.norm.y) > 1 || fabs(pl->data.pl.norm.z) > 1)
		return (0);
	pl->color = vdiv(parse_vec(toks[3]), 255);
	if (is_nanv(&pl->color) || !is_color(&pl->color))
		return (0);
	return (1);
}

static _Bool	finish_parse_cy(t_obj *cy)
{
	if (is_nanv(&cy->color) || !is_color(&cy->color))
		return (0);
	cy->origin = vminus(cy->origin,
			vscale(vunit(cy->data.cy.norm), cy->data.cy.height / 2));
	return (1);
}

_Bool	parse_cylinder(char **toks, t_obj *cy)
{
	char	*pos;

	if (split_len((const char **)toks) != 6 || ft_strcmp(toks[0], "cy"))
		return (0);
	cy->type = CYLINDER;
	cy->origin = parse_vec(toks[1]);
	if (is_nanv(&cy->origin))
		return (0);
	cy->data.cy.norm = parse_vec(toks[2]);
	if (is_nanv(&cy->data.cy.norm) || fabs(cy->data.cy.norm.x) > 1
		|| fabs(cy->data.cy.norm.y) > 1 || fabs(cy->data.cy.norm.z) > 1)
		return (0);
	cy->data.cy.radius = ft_strtod(toks[3], &pos);
	if (toks[3] + ft_strlen(toks[3]) != pos || cy->data.cy.radius < 0
		|| cy->data.cy.radius < 2 * DBL_EPSILON)
		return (0);
	cy->data.cy.radius /= 2;
	cy->data.cy.radius2 = cy->data.cy.radius * cy->data.cy.radius;
	if (cy->data.cy.radius2 < 1e-15)
		return (0);
	cy->data.cy.height = ft_strtod(toks[4], &pos);
	if (toks[4] + ft_strlen(toks[4]) != pos || cy->data.cy.height <= 0)
		return (0);
	cy->color = parse_vec(toks[5]);
	return (finish_parse_cy(cy));
}
