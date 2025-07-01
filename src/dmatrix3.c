/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmatrix3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:58:24 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/02 01:09:20 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_dmatrix	*_Nullable	_rotate2(t_list **dyn, double angz,
						t_dmatrix *_Nonnull mat)
{
	t_dmatrix	*zrot;

	zrot = _get_zrot(dyn, angz);
	if (zrot == NULL)
		return (NULL);
	return (_matmul(dyn, zrot, mat));
}

t_dmatrix	*_Nullable	_ortho_proj(t_list **dyn, t_dmatrix *_Nonnull mat)
{
	t_dmatrix	*proj;

	proj = __3d_point_col(dyn, 1, 0, 0);
	if (proj == NULL)
		return (NULL);
	if (__3d_point_col(dyn, 0, 1, 0) == NULL
		|| _mat2vec(dyn, __3d_point_col(dyn, 0, 1, 0)) == NULL
		|| !_add_col(dyn, *_mat2vec(dyn, __3d_point_col(dyn, 0, 1, 0)), proj))
		return (NULL);
	if (__3d_point_col(dyn, 0, 0, 0) == NULL
		|| _mat2vec(dyn, __3d_point_col(dyn, 0, 0, 0)) == NULL
		|| !_add_col(dyn, *_mat2vec(dyn, __3d_point_col(dyn, 0, 0, 0)), proj))
		return (NULL);
	return (_matmul(dyn, proj, mat));
}

t_dmatrix	*_Nullable	__3d_point_col(t_list **dyn, double x, double y,
	double z)
{
	t_dmatrix	*p;
	t_dvec		v;

	p = (t_dmatrix *)gc_calloc(dyn, 1, sizeof(t_dmatrix));
	if (p == NULL)
		return (NULL);
	p->col = 0;
	p->cap = 0;
	v = (t_dvec){.ptr = NULL, .len = 0, .cap = 0};
	_push_back(dyn, &v, x);
	if (!_add_row(dyn, v, p))
		return (NULL);
	v.ptr[0] = y;
	if (!_add_row(dyn, v, p))
		return (NULL);
	v.ptr[0] = z;
	if (!_add_row(dyn, v, p))
		return (NULL);
	return (p);
}

t_dvec	*_Nullable	_mat2vec(t_list **dyn, t_dmatrix *_Nonnull mat)
{
	t_dvec	v;
	size_t	i;

	if (mat->col != 1 && mat->col > 0 && mat->ptr[0].len != 1)
		return (NULL);
	if (mat->col == 1)
		return (_veccpy(dyn, mat->ptr[0]));
	v = (t_dvec){.ptr = NULL, .len = 0, .cap = 0};
	i = 0;
	while (i < mat->col)
	{
		_push_back(dyn, &v, mat->ptr[i].ptr[0]);
		i++;
	}
	return (_veccpy(dyn, v));
}

t_dmatrix	*_Nullable	_transpose(t_list **dyn, t_dmatrix *_Nonnull mat)
{
	t_dmatrix	*t;
	size_t		i;

	if (mat->col == 0 || mat->ptr->len == 0)
		return (NULL);
	t = (t_dmatrix *)gc_calloc(dyn, 1, sizeof(t_dmatrix));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (i < mat->col)
	{
		if (!_add_col(dyn, mat->ptr[i], t))
			return (NULL);
		i++;
	}
	return (t);
}
