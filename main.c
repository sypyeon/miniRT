/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:40:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/06 21:25:59 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_minirt.h"
#include "mlx.h"

void	check_parse_data(t_rt_info info);

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_rt_info	info;

	(void)av;
	if (ac != 2)
		return (rt_print_err_msg("Input argument error."));
	rt_file_validate_and_save_data(av[1], &info);
	check_parse_data(info);
	if (!rt_valid_file_format(av[1]))
		return (rt_print_err_msg("Wrong file format."));
	mlx.mlx = mlx_init();
	return (0);
}
