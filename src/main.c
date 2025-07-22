/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/22 23:22:52 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	main(int ac, char **av)
{
	t_obj	*sp;
	char	**ss;

	if (ac != 2)
		return (printf("invalid number of args\n"), 1);
	sp = ft_calloc(1, sizeof(t_obj));
	if (!sp)
		return (printf("alloc error\n"), 1);
	ss = ft_split(av[1], ' ');
	if (!ss || !parse_sphere(ss, sp))
		return (printf("parse error\n"), 1);
	printf("SPHERE { center: ( %.15f, %.15f, %.15f ), radius: %.15f, radius2: "
		"%.15f, color: color { r: %.15f, g: %.15f, b: %.15f } }\n",
		sp->data.sp.center.x, sp->data.sp.center.y, sp->data.sp.center.z,
		sp->data.sp.radius, sp->data.sp.radius2,
		sp->color.x, sp->color.y, sp->color.z);
	free(sp);
	free_split(ss);
	return (0);
}
