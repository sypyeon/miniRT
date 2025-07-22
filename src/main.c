/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/23 03:50:54 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	main(int ac, char **av)
{
	t_obj	*cy;
	char	**ss;

	if (ac != 2)
		return (printf("invalid number of args\n"), 1);
	cy = ft_calloc(1, sizeof(t_obj));
	if (!cy)
		return (printf("alloc error\n"), 1);
	ss = ft_split(av[1], ' ');
	if (!ss || !parse_cylinder(ss, cy))
		return (printf("parse error\n"), 1);
	printf("CYLINDER { base: ( %.15f, %.15f, %.15f ), norm: ( %.15f, %.15f,"
		" %.15f ), radius: %.15f, radius2: %.15f, height: %.15f, "
		"color: color { r: %.15f, g: %.15f, b: %.15f } }\n",
		cy->data.cy.base.x, cy->data.cy.base.y, cy->data.cy.base.z,
		cy->data.cy.norm.x, cy->data.cy.norm.y, cy->data.cy.norm.z,
		cy->data.cy.radius, cy->data.cy.radius2, cy->data.cy.height,
		cy->color.x, cy->color.y, cy->color.z);
	free(cy);
	free_split(ss);
	return (0);
}
