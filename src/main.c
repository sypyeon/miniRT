/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/23 02:39:12 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	main(int ac, char **av)
{
	t_obj	*pl;
	char	**ss;

	if (ac != 2)
		return (printf("invalid number of args\n"), 1);
	pl = ft_calloc(1, sizeof(t_obj));
	if (!pl)
		return (printf("alloc error\n"), 1);
	ss = ft_split(av[1], ' ');
	if (!ss || !parse_plane(ss, pl))
		return (printf("parse error\n"), 1);
	printf("PLANE { base: ( %.15f, %.15f, %.15f ), norm: ( %.15f, %.15f, %.15f "
		"), color: color { r: %.15f, g: %.15f, b: %.15f } }\n",
		pl->data.pl.base.x, pl->data.pl.base.y, pl->data.pl.base.z,
		pl->data.pl.norm.x, pl->data.pl.norm.y, pl->data.pl.norm.z,
		pl->color.x, pl->color.y, pl->color.z);
	free(pl);
	free_split(ss);
	return (0);
}
