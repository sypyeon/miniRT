/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:33:13 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/01 07:26:22 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H
# include <fcntl.h>
# include "../ft_printf/src/ft_printf.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_dvec
{
	double	*ptr;
	size_t	len;
	size_t	cap;
}	t_dvec;

typedef struct s_dmatrix
{
	size_t	col;
	size_t	cap;
	t_dvec	*ptr;
}	t_dmatrix;

void				_push_back(t_list **dyn, t_dvec *_Nonnull vec,
						const double value);
void				_push_front(t_list **dyn, t_dvec *_Nonnull vec,
						const double value);
double	*_Nullable		_pop_back(t_list **dyn, t_dvec *_Nullable vec);
void				_vecalloc(t_list **dyn, t_dvec *_Nonnull vec);
t_dvec	*_Nullable		_veccpy(t_list **dyn, const t_dvec v);
_Bool				_velem(const double c, const t_dvec v);
int					_veccmp(const t_dvec v1, const t_dvec v2);

void				_matalloc(t_list **dyn, t_dmatrix *_Nonnull mat);
_Bool				_add_row(t_list **dyn, const t_dvec row,
						t_dmatrix *_Nonnull mat);
_Bool				_add_col(t_list **dyn, const t_dvec col,
						t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_matmul(t_list **dyn, t_dmatrix *_Nonnull a,
						t_dmatrix *_Nonnull b);
t_dmatrix	*_Nonnull	_matmul2(t_dmatrix *_Nonnull c, t_dmatrix *_Nonnull a,
						t_dmatrix *_Nonnull b);
int	*_Nullable		_dot_prod(const t_vec row, t_dmatrix *_Nonnull mat,
						size_t col);
t_dmatrix	*_Nullable	_rotate(t_list **dyn, double angx, double angy,
						t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_rotate2(t_list **dyn, double angz,
						t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_get_yrot(t_list **dyn, double angle);
t_dmatrix	*_Nullable	_get_xrot(t_list **dyn, double angle);
t_dmatrix	*_Nullable	_get_zrot(t_list **dyn, double angle);
t_dmatrix	*_Nullable	_ortho_proj(t_list **dyn, t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	__3d_point_col(t_list **dyn, int x, int y, int z);
t_dvec	*_Nullable		_mat2vec(t_list **dyn, t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_transpose(t_list **dyn, t_dmatrix *_Nonnull mat);
t_dmatrix	*_Nullable	_append(t_list **dyn, t_dmatrix *_Nonnull a,
						t_dmatrix *_Nonnull b);
t_dmatrix	*_Nullable	_matcpy(t_list **dyn, t_dmatrix *_Nonnull mat);

#endif
