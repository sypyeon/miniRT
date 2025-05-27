/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:40:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/05/26 22:26:50 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_struct.h"
#include "rt_parse.h"
#include "mlx.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (write(STDERR_FILENO, "Input argument error.", 22));
	mlx_init
}
