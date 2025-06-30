/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 06:53:51 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/01 06:56:20 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

_Bool	_velem(const double c, const t_dvec v)
{
	size_t	i;

	i = 0;
	while (i < v.len)
	{
		if (v.ptr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	_veccmp(const t_dvec v1, const t_dvec v2)
{
	size_t	i;

	i = 0;
	while (i < v1.len && i < v2.len)
	{
		if (v1.ptr[i] != v2.ptr[i])
			return (v1.ptr[i] - v2.ptr[i]);
		i++;
	}
	if (v1.len > v2.len)
		return (1);
	else if (v2.len > v1.len)
		return (-1);
	return (0);
}
