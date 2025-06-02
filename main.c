/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:40:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/03 04:45:58 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_minirt.h"
#include "mlx.h"

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_rt_info	info;

	(void)av;
	if (ac != 2)
		return (rt_print_err_msg("Input argument error."));
	rt_file_validate_and_save_data(av[1], &info);
	if (!rt_valid_file_format(av[1]))
		return (rt_print_err_msg("Wrong file format."));
	mlx.mlx = mlx_init();
	return (0);
}
