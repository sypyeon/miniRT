/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/22 05:58:23 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	main(int ac, char **av)
{
	t_vec	v;

	if (ac != 2)
		return (1);
	v = parse_vec(av[1]);
	if (is_nanv(&v))
		return (printf("parse error\n"), 1);
	printf("vec { x: %.15f, y: %.15f, z: %.15f }\n", v.x, v.y, v.z);
	return (0);
}
