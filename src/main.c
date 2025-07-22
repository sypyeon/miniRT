/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/22 21:11:14 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	main(int ac, char **av)
{
	t_obj	*light;
	char	**ss;

	if (ac != 2)
		return (printf("invalid number of args\n"), 1);
	light = ft_calloc(1, sizeof(t_obj));
	if (!light)
		return (printf("alloc error\n"), 1);
	ss = ft_split(av[1], ' ');
	if (!ss || !parse_light(ss, light))
		return (printf("parse error\n"), 1);
	printf("LIGHT { origin: ( %.15f, %.15f, %.15f ), bright_ratio: %.15f",
		light->data.light.orig.x, light->data.light.orig.y,
		light->data.light.orig.z,
		light->data.light.bright_ratio);
	if (!is_nanv(&light->color))
		printf(", color: color { r: %.15f, g: %.15f, b: %.15f }",
			light->color.x, light->color.y, light->color.z);
	printf(" }\n");
	free(light);
	free_split(ss);
	return (0);
}
