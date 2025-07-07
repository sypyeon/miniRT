/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:49:19 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/07 19:29:18 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCT_H
# define RT_STRUCT_H

# define bool	_Bool

typedef struct s_vec t_point;

typedef struct s_vec
{
    double x;
    double y;
    double z;
}	t_vec;

typedef struct s_color
{
    double r;
    double g;
    double b;
}	t_color;

typedef struct s_axis
{
	t_vec	x;
	t_vec	y;
	t_vec	z;
}	t_axis;

typedef struct s_ambient
{
	bool	exist;
	double	amb_ratio;
	t_color	color;
}	t_ambient;

typedef struct  s_camera
{
	t_point		origin;
	t_axis		axis;
	double		viewport_h;
	double		viewport_w;
	t_vec		direction;
	t_vec		horizontal;
	t_vec		vertical;
	double		focal_len;
	t_point		left_bottom;
	int			fov;
}	t_camera;

typedef struct  s_canvas
{
    int     width;
    int     height;
    double  aspect_ratio;
}	t_canvas;

typedef struct s_light
{
	double	bright;
	t_point	orig;
	t_color	color;
}	t_light;

typedef struct s_ray
{
	t_point	origin;
	t_vec	direction;
}	t_ray;

typedef struct s_obj
{
	int				identifier;
	t_color			color;
	t_point			center;
	t_vec			vector;
	double			radius;
	double			radius2;
	double			height;
	struct s_obj	*next;
}	t_obj;

typedef struct s_obj_list
{
	int		size;
	t_obj	*head;
	t_obj	*tail;
}	t_obj_list;

typedef struct s_rt_info
{
	t_ambient	amb;
	t_camera	cam;
	t_light		light;
	t_obj_list	obj;
	t_obj		*current_obj;
	int			current;
}	t_rt_info;

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
	void		*mlx;
	void		*win;
	t_data		img;
	t_rt_info	info;
}	t_mrt;

#endif
