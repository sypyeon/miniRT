/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:12:02 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 01:06:03 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/utils.h"

void	free_split(char **split)
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

void	free_obj(t_obj *obj)
{
	t_obj	*to_free;

	if (obj == NULL)
		return ;
	while (obj)
	{
		to_free = obj;
		obj = obj->next;
		free(to_free);
	}
}
