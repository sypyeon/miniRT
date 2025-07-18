/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:12:02 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/18 20:13:03 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "structures.h"

void	rt_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	rt_free_obj(t_object *obj)
{
	t_object	*to_free;

	if (obj == NULL)
		return ;
	while (obj)
	{
		to_free = obj;
		obj = obj->next;
		free(to_free);
	}
}
