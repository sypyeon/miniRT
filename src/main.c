/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:00:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/24 12:45:05 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	main(int ac, char **av)
{
	t_scene	s;
	size_t	i;

	ft_bzero(&s, sizeof(t_scene));
	if (ac != 2)
		return (printf("invalid number of args\n"), 1);
	if (!parse_rt(&s, av[1]))
		return (printf("parse error\n"), 1);
	i = 0;
	printf("%zu objs\n", s.objs.size);
	while (i < s.objs.size)
	{
		printf("type: %d\n", s.objs.ptr[i].type);
		i++;
	}
	free(s.objs.ptr);
	return (0);
}
