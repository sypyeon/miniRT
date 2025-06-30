/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 03:46:21 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/01 07:28:35 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <unistd.h>

void	_push_back(t_list **dyn, t_dvec *_Nonnull vec, const double value)
{
	if (vec->len == vec->cap)
		_vecalloc(dyn, vec);
	vec->ptr[vec->len++] = value;
}

void	_push_front(t_list **dyn, t_dvec *_Nonnull vec, const double value)
{
	double	*newp;
	double	*temp;

	if (vec->len == vec->cap)
	{
		if (vec->cap == 0)
		{
			_push_back(dyn, vec, value);
			return ;
		}
		newp = (double *)gc_calloc(dyn, 2 * vec->cap, sizeof(double));
		vec->cap *= 2;
	}
	else
		newp = (double *)gc_calloc(dyn, vec->cap, sizeof(double));
	temp = newp + 1;
	ft_memmove(temp, vec->ptr, sizeof(double) * (vec->len++));
	*newp = value;
	vec->ptr = newp;
}

double	*_Nullable	_pop_back(t_list **dyn, t_dvec *_Nullable vec)
{
	double	*res;

	if (vec == NULL || vec->len == 0 || !vec->ptr)
		return (NULL);
	res = (double *)gc_calloc(dyn, 1, sizeof(double));
	if (!res)
		return (NULL);
	*res = vec->ptr[--vec->len];
	return (res);
}

void	_vecalloc(t_list **dyn, t_dvec *_Nonnull vec)
{
	if (vec->cap == 0)
		vec->ptr = (double *)gc_calloc(dyn, 1, sizeof(double));
	else
		gc_realloc(dyn, (void **)&vec->ptr, vec->cap * sizeof(double),
			vec->cap * 2 * sizeof(double));
	if (!vec->ptr)
		return ;
	if (vec->cap == 0)
		vec->cap = 1;
	else
		vec->cap *= 2;
}

t_dvec	*_Nullable	_veccpy(t_list **dyn, const t_dvec v)
{
	t_dvec	*res;

	res = (t_dvec *)gc_calloc(dyn, 1, sizeof(t_dvec));
	if (res == NULL)
		return (NULL);
	res->ptr = (double *)gc_calloc(dyn, v.cap, sizeof(double));
	ft_memmove(res->ptr, v.ptr, v.len * sizeof(double));
	res->cap = v.cap;
	res->len = v.len;
	return (res);
}
