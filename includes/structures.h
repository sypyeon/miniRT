/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:47:01 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 21:18:10 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# define FALSE 0
# define TRUE 1
# define SP 0
# define LIGHT_POINT 1
# define EPSILON 1e-6
# define LUMEN 3  // 이 값을 조절하여 장면의 밝기를 조절할 수 있다.

typedef struct s_vec	t_color;
typedef struct s_vec	t_point;
typedef int				t_bool;
typedef int				t_object_type;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_ray
{
	t_point	orig;
	t_vec	dir;
}	t_ray;

typedef struct s_sphere
{
	t_point	center;
	double	radius;
	double	radius2;
}	t_sphere;

typedef struct s_cylinder
{
	t_point	center;
	double	radius;
	double	radius2;
}	t_cylinder;

typedef struct s_object
{
	t_object_type	type;
	void			*element;
	t_color			albedo;
	struct s_object	*next;
}	t_object;

typedef struct s_light
{
	t_point	origin;
	t_color	light_color;
	double	bright_ratio;
}	t_light;

typedef struct s_camera
{
	t_point	orig;
	double	viewport_h;
	double	viewport_w;
	t_vec	horizontal;
	t_vec	vertical;
	double	focal_len;
	t_point	left_bottom;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_hit_record
{
	t_point	p;
	t_vec	normal;
	double	tmin;
	double	tmax;
	double	t;
	t_bool	front_face;
	t_color	albedo;
}	t_hit_record;

typedef struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*object;
	t_object		*light;
	t_color			ambient;
	t_ray			ray;
	t_hit_record	rec;
}	t_scene;

typedef struct s_data
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mrt
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_scene	scene;
}	t_mrt;

#endif
