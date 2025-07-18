/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:47:01 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/19 08:24:35 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
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

typedef struct s_sphere
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
	t_obj_type		type;
	union u_mat
	{
		t_sphere	sp;
		t_cylinder	cy;
		t_plane		pl;
		t_light		light;
	}	mat;
	t_color			color;
	t_color			albedo;
	struct s_obj	*next;
}	t_obj;

typedef struct s_camera
{
	t_point3	orig;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horiz;
	t_vec3		vert;
	double		focal_len;
	t_point3	left_bottom;
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
	t_canvas		canvas;
	t_camera		camera;
	t_obj			*objs;
	t_color			ambient;
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
