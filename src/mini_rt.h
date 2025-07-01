/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:33:13 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/02 07:00:14 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H
# include <fcntl.h>
# include "../ft_printf/src/ft_printf.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_dvec
{
	double *_Nullable	ptr;
	size_t				len;
	size_t				cap;
}	t_dvec;

typedef struct s_dmatrix
{
	size_t				col;
	size_t				cap;
	t_dvec *_Nullable	ptr;
}	t_dmatrix;

typedef struct s_ray
{
	t_dmatrix	orig;
	t_dmatrix	dir;
}	t_ray;

void				_push_back(t_list *_Nullable *_Nonnull dyn,
						t_dvec *_Nonnull vec, const double value);
void				_push_front(t_list *_Nullable *_Nonnull dyn,
						t_dvec *_Nonnull vec, const double value);
double	*_Nullable		_pop_back(t_list *_Nullable *_Nonnull dyn,
						t_dvec *_Nullable vec);
void				_vecalloc(t_list *_Nullable *_Nonnull dyn,
						t_dvec *_Nonnull vec);
t_dvec	*_Nullable		_veccpy(t_list *_Nullable *_Nonnull dyn,
						const t_dvec v);
_Bool				_velem(const double c, const t_dvec v);
int					_veccmp(const t_dvec v1, const t_dvec v2);
t_dvec	*_Nullable		vecadd(t_list *_Nullable *_Nonnull dyn,
						const t_dvec *_Nonnull a, const t_dvec *_Nonnull b);
t_dvec	*_Nullable		vecsub(t_list *_Nullable *_Nonnull dyn,
						const t_dvec *_Nonnull a, const t_dvec *_Nonnull b);
void				vecscale(const double k, t_dvec *_Nonnull v);

void				_matalloc(t_list *_Nullable *_Nonnull dyn,
						t_dmatrix *_Nonnull mat);
_Bool				_add_row(t_list *_Nullable *_Nonnull dyn, const t_dvec row,
						t_dmatrix *_Nonnull mat);
_Bool				_add_col(t_list *_Nullable *_Nonnull dyn, const t_dvec col,
						t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_matmul(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull a,
						const t_dmatrix *_Nonnull b);
t_dmatrix	*_Nullable	_matmul2(t_list *_Nullable *_Nonnull dyn,
						t_dmatrix *_Nonnull c, const t_dmatrix *_Nonnull a,
						const t_dmatrix *_Nonnull b);
double	*_Nullable		_dot_prod(t_list *_Nullable *_Nonnull dyn,
						const t_dvec row, const t_dmatrix *_Nonnull mat,
						const size_t col);
t_dmatrix	*_Nullable	_rotate(t_list *_Nullable *_Nonnull dyn,
						const double angx, const double angy,
						const t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_rotate2(t_list *_Nullable *_Nonnull dyn,
						const double angz,
						const t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_get_xrot(t_list *_Nullable *_Nonnull dyn,
						const double angle);
t_dmatrix	*_Nullable	_get_yrot(t_list *_Nullable *_Nonnull dyn,
						const double angle);
t_dmatrix	*_Nullable	_get_zrot(t_list *_Nullable *_Nonnull dyn,
						const double angle);
t_dmatrix	*_Nullable	_ortho_proj(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	__3d_point_col(t_list *_Nullable *_Nonnull dyn,
						const double x, const double y, const double z);
t_dvec	*_Nullable		_mat2vec(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_transpose(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_append(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull a,
						const t_dmatrix *_Nonnull b);
t_dmatrix	*_Nullable	_matcpy(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_matadd(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull a,
						const t_dmatrix *_Nonnull b);
t_dmatrix	*_Nullable	_matsub(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull a,
						const t_dmatrix *_Nonnull b);
void				matscale(const double k, t_dmatrix *_Nonnull mat);
double	*_Nullable		norm(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_matunit(t_list *_Nullable *_Nonnull dyn,
						const t_dmatrix *_Nonnull mat);

t_ray	*_Nullable		ray(t_list *_Nullable *_Nonnull dyn,
						t_dmatrix *_Nonnull o, t_dmatrix *_Nonnull d);
t_dmatrix	*_Nullable	ray_at(t_list *_Nullable *_Nonnull dyn,
						t_ray *_Nonnull ray, const double t);

#endif
