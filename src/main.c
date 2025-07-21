/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/22 07:37:54 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	main(int ac, char **av)
{
	t_obj	*amb;

	if (ac != 4)
		return (printf("invalid number of args\n"), 1);
	amb = ft_calloc(1, sizeof(t_obj));
	if (!amb)
		return (printf("alloc error\n"), 1);
	if (!parse_amb(av + 1, amb))
		return (printf("parse error\n"), 1);
	printf("AMB { ratio: %.15f, "
		"color: color { r: %.15f, g: %.15f, b: %.15f } }\n",
		amb->data.amb_ratio, amb->color.x, amb->color.y, amb->color.z);
	return (0);
}
