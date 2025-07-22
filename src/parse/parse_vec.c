/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:04:19 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/22 21:32:37 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

static double	parse_field(char *str, size_t *idx, size_t *prev, _Bool final)
{
	char	*sub;
	char	*pos;
	double	res;

	pos = NULL;
	while (str[*idx] && (str[*idx] != ',' || final))
		(*idx)++;
	if (!str[*idx] && !final)
		return (NAN);
	sub = ft_substr(str, *prev, *idx - *prev);
	res = ft_strtod(sub, &pos);
	if ((size_t)(pos - sub) != ft_strlen(sub))
		return (free(sub), NAN);
	return (free(sub), res);
}

t_vec	parse_vec(char *str)
{
	size_t	i;
	size_t	prev;
	t_vec	v;

	prev = 0;
	i = 0;
	v.x = parse_field(str, &i, &prev, 0);
	if (isnan(v.x))
		return (nan_vec());
	prev = ++i;
	v.y = parse_field(str, &i, &prev, 0);
	if (isnan(v.y))
		return (nan_vec());
	prev = ++i;
	v.z = parse_field(str, &i, &prev, 1);
	if (isnan(v.z))
		return (nan_vec());
	return (v);
}

t_vec	nan_vec(void)
{
	return ((t_vec){.x = NAN, .y = NAN, .z = NAN});
}

_Bool	is_nanv(t_vec *v)
{
	return (isnan(v->x) && isnan(v->y) && isnan(v->z));
}

_Bool	is_color(t_color *c)
{
	return (!(c->x < 0 || c->x > 255
			|| c->y < 0 || c->y > 255
			|| c->z < 0 || c->z > 255));
}
