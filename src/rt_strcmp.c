/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 03:55:02 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/25 15:22:35 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"

int	rt_strcmp(const char *str, const char *cmp)
{
	int	i;

	i = 0;
	if (!str || !cmp)
		return (0);
	while (str[i] && cmp[i])
	{
		if (str[i] != cmp[i])
			return (str[i] - cmp[i]);
		i++;
	}
	return (str[i] - cmp[i]);
}
