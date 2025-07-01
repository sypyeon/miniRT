/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmatrix4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:13:38 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/01 23:20:17 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_dmatrix	*_Nullable	_append(t_list **dyn, t_dmatrix *_Nonnull a,
						t_dmatrix *_Nonnull b)
{
	size_t		i;
	t_dmatrix	*res;

	if (a->col == 0 || a->ptr->len == 0 || b->col == 0 || b->ptr->len == 0
		|| (a->col != b->col && a->ptr->len != b->ptr->len))
		return (NULL);
	i = 0;
	if (a->ptr->len == b->ptr->len)
	{
		res = _matcpy(dyn, a);
		while (i < b->col)
		{
			if (res == NULL || !_add_row(dyn, b->ptr[i], res))
				return (NULL);
			i++;
		}
		return (res);
	}
	res = _append(dyn, _transpose(dyn, a), _transpose(dyn, b));
	if (res == NULL)
		return (NULL);
	return (_transpose(dyn, res));
}

t_dmatrix	*_Nullable	_matcpy(t_list **dyn, t_dmatrix *_Nonnull mat)
{
	t_dmatrix	*cpy;
	t_dvec		*temp;
	size_t		i;

	if (mat->col == 0 || mat->ptr->len == 0)
		return (NULL);
	cpy = (t_dmatrix *)gc_calloc(dyn, 1, sizeof(t_dmatrix));
	if (cpy == NULL)
		return (NULL);
	cpy->ptr = (t_dvec *)gc_calloc(dyn, mat->col, sizeof(t_dvec));
	if (cpy->ptr == NULL)
		return (NULL);
	cpy->col = mat->col;
	cpy->cap = mat->col;
	i = 0;
	while (i < mat->col)
	{
		temp = _veccpy(dyn, mat->ptr[i]);
		if (temp == NULL)
			return (NULL);
		cpy->ptr[i] = *temp;
		i++;
	}
	return (cpy);
}
