/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 06:53:51 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/02 05:42:59 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

_Bool	_velem(const double c, const t_dvec v)
{
	size_t	i;

	i = 0;
	while (i < v.len)
	{
		if (v.ptr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	_veccmp(const t_dvec v1, const t_dvec v2)
{
	size_t	i;

	i = 0;
	while (i < v1.len && i < v2.len)
	{
		if (v1.ptr[i] != v2.ptr[i])
			return (v1.ptr[i] - v2.ptr[i]);
		i++;
	}
	if (v1.len > v2.len)
		return (1);
	else if (v2.len > v1.len)
		return (-1);
	return (0);
}

t_dvec	*_Nullable	vecadd(t_list *_Nullable *_Nonnull dyn,
						const t_dvec *_Nonnull a, const t_dvec *_Nonnull b)
{
	size_t	i;
	t_dvec	*res;

	res = (t_dvec *)gc_calloc(dyn, 1, sizeof(t_dvec));
	if (a->len != b->len || res == NULL)
		return (NULL);
	i = 0;
	while (i < a->len)
	{
		_push_back(dyn, res, a->ptr[i] + b->ptr[i]);
		i++;
	}
	return (res);
}

t_dvec	*_Nullable	vecsub(t_list *_Nullable *_Nonnull dyn,
						const t_dvec *_Nonnull a, const t_dvec *_Nonnull b)
{
	size_t	i;
	t_dvec	*res;

	res = (t_dvec *)gc_calloc(dyn, 1, sizeof(t_dvec));
	if (a->len != b->len || res == NULL)
		return (NULL);
	i = 0;
	while (i < a->len)
	{
		_push_back(dyn, res, a->ptr[i] - b->ptr[i]);
		i++;
	}
	return (res);
}

void	vecscale(const double k, t_dvec *_Nonnull v)
{
	size_t	i;

	i = 0;
	while (i < v->len)
	{
		v->ptr[i] *= k;
		i++;
	}
}
