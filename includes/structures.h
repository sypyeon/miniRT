/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:47:01 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/20 19:25:28 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "../ft_printf/src/ft_printf.h"
# define LUMEN 3

typedef enum e_obj_type
{
	SPHERE,
	CYLINDER,
	PLANE,
	LIGHT
}	t_obj_type;

typedef struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
}	t_ray;

typedef struct s_axis
{
	t_vec	x;
	t_vec	y;
	t_vec	z;
}	t_axis;


typedef struct  s_sphere
{
	t_point3	center;
	double		radius;
}	t_sphere;

typedef struct s_cylinder
{
	t_point3	base;
	double		radius;
	t_vec3		height_norm;
}	t_cylinder;

typedef struct s_plane
{
	t_point3	base;
	t_vec3		norm;
}	t_plane;

typedef struct s_light
{
	t_point3	origin;
	double		bright_ratio;
}	t_light;

typedef struct s_obj
{
    t_point	orig;  // 카메라 원점(위치)
    t_vec   direction;
    int     fov;
    double	viewport_h; // 뷰포트 세로길이
    double	viewport_w; // 뷰포트 가로길이
    t_vec	horizontal; // 수평길이 벡터
    t_vec	vertical; // 수직길이 벡터
    double	focal_len; // focal length
    t_point	left_bottom; // 왼쪽 아래 코너점
	t_axis	axis;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		norm;
	double		tmin;
	double		tmax;
	double		t;
	_Bool		front_face;
	t_color		albedo;
}	t_hit_record;

typedef struct s_scene
{
    t_color color;
    double  ratio;
}   t_ambient;


typedef struct  s_scene
{
    t_canvas		canvas;
    t_camera		camera;
    t_object        *current;
    t_object		*object;
    t_object		*light;
    t_ambient		amb; // 8.4에서 설명할 요소
    t_ray			ray;
    t_hit_record	rec;
}	t_scene;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
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
