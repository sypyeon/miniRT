/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 06:47:03 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/02 07:11:46 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	*_Nullable	norm(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull mat)
{
	double	*res;
	size_t	i;

	res = (double *)gc_calloc(dyn, 1, sizeof(double));
	if (mat->col != 3 || mat->ptr->len != 1 || res == NULL)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		*res += pow(*(mat->ptr[i].ptr), 2);
		i++;
	}
	return (res);
}

t_dmatrix	*_Nullable	_matunit(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull mat)
{
	double		*d;
	t_dmatrix	*res;

	d = norm(dyn, mat);
	res = _matcpy(dyn, mat);
	if (d == NULL || mat == NULL)
		return (NULL);
	matscale(1 / (*d), res);
	return (res);
}

t_ray	*_Nullable	ray(t_list *_Nullable *_Nonnull dyn,
						t_dmatrix *_Nonnull o, t_dmatrix *_Nonnull d)
{
	t_ray		*res;
	t_dmatrix	*temp;

	temp = _matunit(dyn, d);
	res = (t_ray *)gc_calloc(dyn, 1, sizeof(t_ray));
	if (temp == NULL || res == NULL)
		return (NULL);
	res->orig = *o;
	res->dir = *temp;
	return (res);
}

t_dmatrix	*_Nullable	ray_at(t_list *_Nullable *_Nonnull dyn,
						t_ray *_Nonnull ray, const double t)
{
	t_dmatrix	*temp;

	temp = _matcpy(dyn, &ray->dir);
	if (temp == NULL)
		return (NULL);
	matscale(t, temp);
	return (_matadd(dyn, &ray->orig, temp));
}
