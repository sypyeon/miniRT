/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 03:55:02 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/03 05:38:59 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"

int	rt_strcmp(const char *str, const char *cmp)
{
	if (!str || !cmp)
		return (0);
	while (str && cmp)
	{
		if (*str != *cmp)
			return (*str - *cmp);
		str++;
		cmp++;
	}
	return (*str - *cmp);
}
