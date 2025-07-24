/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:47:01 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/25 03:40:55 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "../libft/libft.h"

# define LUMEN 5
# define MINI_RT "miniRT"

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_vec	t_point;
typedef struct s_vec	t_color;

typedef enum e_obj_type
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
}	t_obj_type;

typedef struct s_ray
{
	t_point	orig;
	t_vec	dir;
}	t_ray;

typedef struct s_axis
{
	t_vec	x;
	t_vec	y;
	t_vec	z;
}	t_axis;

typedef struct s_sphere
{
	double	radius;
	double	radius2;
}	t_sphere;

typedef struct s_cylinder
{
	double	radius;
	double	radius2;
	double	height;
	t_vec	norm;
}	t_cylinder;

typedef struct s_plane
{
	t_vec	norm;
}	t_plane;

typedef struct s_light
{
	double	bright_ratio;
}	t_light;

typedef struct s_camera
{
	t_vec	dir;
	int		fov;
	t_vec	horizontal;
	t_vec	vertical;
	double	focal_len;
	t_point	left_bottom;
	t_axis	axis;
}	t_camera;

typedef struct s_obj
{
	t_obj_type		type;
	t_point			origin;
	union u_obj_data
	{
		double			amb_ratio;
		t_camera		cam;
		t_light			light;
		t_sphere		sp;
		t_plane			pl;
		t_cylinder		cy;
	}	data;
	t_color			color;
}	t_obj;

typedef struct s_objs
{
	t_obj	*ptr;
	size_t	size;
	size_t	cap;
}	t_objs;

typedef struct s_hit_record
{
	t_point	p;
	t_vec	norm;
	double	tmin;
	double	tmax;
	double	t;
	_Bool	front_face;
	t_color	albedo;
}	t_hit_record;

typedef struct s_scene
{
	t_objs			objs;
	size_t			cam;
	size_t			curr;
	size_t			light;
	size_t			amb;
	t_ray			ray;
	t_hit_record	rec;
}	t_scene;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_rt
{
	void	*mlx;
	void	*win;
	t_image	img;
	t_scene	scene;
}	t_rt;

#endif
