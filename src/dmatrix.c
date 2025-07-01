/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmatrix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:04:15 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/01 23:22:50 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	_matalloc(t_list **dyn, t_dmatrix *_Nonnull mat)
{
	if (mat->cap == 0)
		mat->ptr = (t_dvec *)gc_calloc(dyn, 1, sizeof(t_dvec));
	else
		gc_realloc(dyn, (void **)&mat->ptr, mat->cap * sizeof(t_dvec),
			mat->cap * 2 * sizeof(t_dvec));
	if (!mat->ptr)
		return ;
	if (mat->cap == 0)
		mat->cap = 1;
	else
		mat->cap *= 2;
}

_Bool	_add_row(t_list **dyn, const t_dvec row, t_dmatrix *_Nonnull mat)
{
	t_dvec	*v;

	if (mat->col == mat->cap)
		_matalloc(dyn, mat);
	if (mat->col != 0 && mat->ptr[0].len != row.len)
		return (0);
	v = _veccpy(dyn, row);
	if (v == NULL)
		return (0);
	mat->ptr[mat->col++] = *v;
	return (1);
}

_Bool	_add_col(t_list **dyn, const t_dvec col, t_dmatrix *_Nonnull mat)
{
	size_t	i;
	_Bool	temp;

	temp = 0;
	if (mat->col == 0)
	{
		i = 0;
		while (i < col.len)
		{
			temp = _add_row(dyn, (t_dvec){.ptr = NULL, .len = 0, .cap = 0},
					mat);
			if (!temp)
				return (0);
			i++;
		}
	}
	else if (mat->col != col.len)
		return (0);
	i = 0;
	while (i < mat->col)
	{
		_push_back(dyn, mat->ptr + i, col.ptr[i]);
		i++;
	}
	return (1);
}

t_dmatrix	*_Nullable	_matmul(t_list **dyn, t_dmatrix *_Nonnull a,
								t_dmatrix *_Nonnull b)
{
	t_dmatrix	*c;
	size_t		i;

	if (a->col == 0 || b->col == 0 || a->ptr->len != b->col)
		return (NULL);
	c = (t_dmatrix *)gc_calloc(dyn, 1, sizeof(t_dmatrix));
	if (c == NULL)
		return (NULL);
	c->ptr = (t_dvec *)gc_calloc(dyn, a->col, sizeof(t_dvec));
	if (c->ptr == NULL)
		return (NULL);
	i = 0;
	c->cap = a->col;
	c->col = a->col;
	while (i < a->col)
	{
		c->ptr[i].ptr = (double *)gc_calloc(dyn, b->ptr->len, sizeof(double));
		if (c->ptr[i].ptr == NULL)
			return (NULL);
		c->ptr[i].cap = b->ptr->len;
		c->ptr[i].len = b->ptr->len;
		i++;
	}
	return (_matmul2(dyn, c, a, b));
}

t_dmatrix	*_Nullable	_matmul2(t_list **dyn, t_dmatrix *_Nonnull c,
	t_dmatrix *_Nonnull a, t_dmatrix *_Nonnull b)
{
	size_t	i;
	size_t	j;
	double	*temp;

	i = 0;
	while (i < a->col)
	{
		j = 0;
		while (j < b->ptr->len)
		{
			temp = _dot_prod(dyn, a->ptr[i], b, j);
			if (!temp)
				return (NULL);
			c->ptr[i].ptr[j] = *temp;
			j++;
		}
		i++;
	}
	return (c);
}
