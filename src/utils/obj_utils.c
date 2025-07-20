/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:41:35 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 06:28:02 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	obj_add(t_obj **list, t_obj *new)
{
	t_obj	*cur;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

t_obj	*obj_last(t_obj *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
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
