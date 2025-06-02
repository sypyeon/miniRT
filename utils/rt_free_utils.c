/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 05:24:52 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/03 05:29:59 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"
#include "rt_struct.h"

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

void	rt_free_obj(t_rt_info *info)
{
	t_obj	*obj;
	t_obj	*to_free;

	obj = info->obj.head;
	if (obj == NULL)
		return ;
	while (obj)
	{
		to_free = obj;
		obj = obj->next;
		free(to_free);
	}
}
