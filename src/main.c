/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/24 21:27:43 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scene.h"
#include "../includes/trace.h"
#include "../includes/mlx_utils.h"
#include "../includes/parse.h"

int	main(int ac, char **av)
{
	t_rt	rt;

	if (ac != 2)
		return (printf("invalid number of args\n"), 1);
	ft_bzero(&rt, sizeof(t_rt));
	if (!parse_rt(&rt.scene, av[1]))
		return (printf("parse error\n"), 1);
	rt.mlx = mlx_init();
	rt.win = mlx_new_window(rt.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	mlx_hook(rt.win, KEY_PRESS, 1, rt_keybind, &rt);
	mlx_hook(rt.win, ON_DESTROY, 0, close_rt, &rt);
	mlx_loop_hook(rt.mlx, rt_drawing, &rt);
	mlx_loop(rt.mlx);
	return (0);
}
