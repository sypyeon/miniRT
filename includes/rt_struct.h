/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:49:19 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/03 00:59:31 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCT_H
# define RT_STRUCT_H

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

typedef struct s_ambient
{
	double	amb_ratio;
	int		color;
}	t_ambient;

typedef struct  s_camera
{
	t_point		orig; 
	double		viewport_h;
	double		viewport_w;
	t_vec		horizontal;
	t_vec		vertical;
	double		focal_len;
	t_point		left_bottom;
}	t_camera;

typedef struct s_light
{
	double	x;
	double	y;
	double	z;
	double	bright;
	int		color;
}	t_light;

typedef struct s_object
{
	int				identifier;
	double			x;
	double			y;
	double			z;
	double			diameter;
	double			height;
	int				color;
	struct s_object	*next;
}	t_object;

typedef struct s_obj_list
{
	int			size;
	t_object	*head;
	t_object	*tail;
}	t_obj_list;


typedef struct s_rt_info
{
	t_ambient	amb;
	t_camera	cam;
	t_light		light;
	t_obj_list	objects;
}	t_rt_info;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_data		img_data;
	t_rt_info	info;
}	t_mlx;

#endif
