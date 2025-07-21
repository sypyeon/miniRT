/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/22 02:52:00 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	main(int ac, char **av)
{
	char	*pos;
	double	d;
	size_t	i;

	pos = NULL;
	if (ac != 2)
		return (1);
	d = ft_strtod(av[1], &pos);
	i = 0;
	while (av[1][i])
		i++;
	if (av[1] + i != pos)
		return (printf("parse error\n"), 1);
	printf("%.15f\n", d);
	return (0);
}
