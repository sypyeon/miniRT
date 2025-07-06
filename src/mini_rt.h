/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:33:13 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/07 07:10:08 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H
# include <fcntl.h>
# include "../ft_printf/src/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# define PIC_WIDTH 1080
# define PIC_HEIGHT 1080

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

typedef struct s_camera
{
	t_dmatrix	orig;
	double		viewport_w;
	double		viewport_h;
	t_dmatrix	horizontal;
	t_dmatrix	vertical;
	double		focal_len;
	t_dmatrix	left_bottom;
}	t_camera;

typedef struct s_canvas
{
	size_t	width;
	size_t	height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

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
t_canvas	*_Nullable	canvas(t_list *_Nullable *_Nonnull dyn,
						size_t width, size_t height);
t_camera	*_Nullable	camera(t_list *_Nullable *_Nonnull dyn,
						t_canvas *_Nonnull canvas, t_dmatrix *_Nonnull orig);
t_ray	*_Nullable		ray_primary(t_list *_Nullable *_Nonnull dyn,
						t_camera *_Nonnull cam, double u, double v);
t_dmatrix	*_Nullable	ray_color(t_list *_Nullable *_Nonnull dyn,
						t_ray *_Nonnull r);
_Bool				init_img(t_list *_Nullable *_Nonnull dyn,
						void *_Nonnull mlx, t_img *_Nullable *_Nonnull img);
void				put_pixel(t_img *_Nonnull img, int x, int y, int color);

#endif
