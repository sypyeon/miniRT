/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 06:31:40 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/23 22:32:07 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

static _Bool	objalloc(t_objs *objs)
{
	t_obj	*newp;

	if (!objs)
		return (0);
	if (objs->cap == 0 || !objs->ptr)
	{
		objs->ptr = (t_obj *)ft_calloc(1, sizeof(t_obj));
		if (!objs->ptr)
			return (0);
		objs->cap = 1;
		objs->size = 0;
		return (1);
	}
	newp = (t_obj *)ft_calloc(objs->cap * 2, sizeof(t_obj));
	if (!newp)
		return (0);
	ft_memmove(newp, objs->ptr, objs->cap * sizeof(t_obj));
	objs->cap *= 2;
	free(objs->ptr);
	objs->ptr = newp;
	return (1);
}

t_obj	*obj_to_push(t_objs *objs)
{
	if (!objs)
		return (NULL);
	if ((!objs->ptr || objs->size == objs->cap) && !objalloc(objs))
		return (free(objs->ptr), NULL);
	return (objs->ptr + objs->size++);
}
