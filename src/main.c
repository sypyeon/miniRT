/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:41:27 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/07 08:02:49 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(void)
{
	size_t		i, j;
	double		u, v;
	t_dmatrix	*color;
	t_canvas	*canv;
	t_camera	*cam;
	t_ray		*ray;
	t_list		*dyn;

	dyn = NULL;
	canv = canvas(&dyn, 100, 100);
	cam = camera(&dyn, canv, __3d_point_col(&dyn, 0.0, 0.0, 0.0));
	ft_fprintf(STDOUT_FILENO, "P3\n%d %d\n255\n", canv->width, canv->height);
	j = canv->height - 1;
	while (1)
	{
		i = 0;
		while (i < canv->width)
		{
			u = (double)i / (canv->width - 1);
			v = (double)j / (canv->height - 1);
			ray = ray_primary(&dyn, cam, u, v);
			color = ray_color(&dyn, ray);
			// write_color(color);
			i++;
		}
		if (j == 0)
			return (0);
		j--;
	}
	return (0);
}
