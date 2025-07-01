/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmatrix2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:41:57 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/02 01:40:03 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	*_Nullable	_dot_prod(t_list **dyn, const t_dvec row,
	t_dmatrix *_Nonnull mat, size_t col)
{
	double	*res;
	size_t	k;

	if (row.len != mat->col)
		return (NULL);
	res = (double *)gc_calloc(dyn, 1, sizeof(double));
	if (!res)
		return (NULL);
	k = 0;
	while (k < mat->col)
	{
		*res += row.ptr[k] * mat->ptr[k].ptr[col];
		k++;
	}
	return (res);
}

t_dmatrix	*_Nullable	_rotate(t_list **dyn, double angx, double angy,
						t_dmatrix *_Nonnull mat)
{
	t_dmatrix	*yrot;
	t_dmatrix	*xrot;
	t_dmatrix	*res;

	if (mat->col != 3)
		return (NULL);
	yrot = _get_yrot(dyn, angy);
	xrot = _get_xrot(dyn, angx);
	if (yrot == NULL || xrot == NULL)
		return (NULL);
	res = _matmul(dyn, xrot, mat);
	if (res == NULL)
		return (NULL);
	return (_matmul(dyn, yrot, res));
}

t_dmatrix	*_Nullable	_get_xrot(t_list **dyn, double angle)
{
	t_dmatrix	*rot;
	t_dmatrix	*temp;
	t_dvec		*tempv;

	rot = __3d_point_col(dyn, SCALE, 0, 0);
	if (rot == NULL)
		return (NULL);
	temp = __3d_point_col(dyn, 0, SCALE * cos(angle), SCALE * sin(angle));
	if (temp == NULL)
		return (NULL);
	tempv = _mat2vec(dyn, temp);
	if (tempv == NULL || !_add_col(dyn, *tempv, rot))
		return (NULL);
	temp = __3d_point_col(dyn, 0, -SCALE * sin(angle), SCALE * cos(angle));
	if (temp == NULL)
		return (NULL);
	tempv = _mat2vec(dyn, temp);
	if (tempv == NULL || !_add_col(dyn, *tempv, rot))
		return (NULL);
	return (rot);
}

t_dmatrix	*_Nullable	_get_yrot(t_list **dyn, double angle)
{
	t_dmatrix	*rot;
	t_dmatrix	*temp;
	t_dvec		*tempv;

	rot = __3d_point_col(dyn, SCALE * cos(angle), 0, -SCALE * sin(angle));
	if (rot == NULL)
		return (NULL);
	temp = __3d_point_col(dyn, 0, SCALE, 0);
	if (temp == NULL)
		return (NULL);
	tempv = _mat2vec(dyn, temp);
	if (tempv == NULL || !_add_col(dyn, *tempv, rot))
		return (NULL);
	temp = __3d_point_col(dyn, SCALE * sin(angle), 0, SCALE * cos(angle));
	if (temp == NULL)
		return (NULL);
	tempv = _mat2vec(dyn, temp);
	if (tempv == NULL || !_add_col(dyn, *tempv, rot))
		return (NULL);
	return (rot);
}

t_dmatrix	*_Nullable	_get_zrot(t_list **dyn, double angle)
{
	t_dmatrix	*rot;
	t_dmatrix	*temp;
	t_dvec		*tempv;

	rot = __3d_point_col(dyn, SCALE * cos(angle), SCALE * sin(angle), 0);
	if (rot == NULL)
		return (NULL);
	temp = __3d_point_col(dyn, -SCALE * sin(angle), SCALE * cos(angle), 0);
	if (temp == NULL)
		return (NULL);
	tempv = _mat2vec(dyn, temp);
	if (tempv == NULL || !_add_col(dyn, *tempv, rot))
		return (NULL);
	temp = __3d_point_col(dyn, 0, 0, SCALE);
	if (temp == NULL)
		return (NULL);
	tempv = _mat2vec(dyn, temp);
	if (tempv == NULL || !_add_col(dyn, *tempv, rot))
		return (NULL);
	return (rot);
}
