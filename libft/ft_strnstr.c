/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:52:16 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/06 01:21:54 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	cmp;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] != 0 && i < len)
	{
		cmp = 0;
		if ((big[i] == little[cmp]) && (i + ft_strlen(little) - 1 < len))
		{
			while (little[cmp] != 0 && (big[i + cmp] == little[cmp]))
			{
				cmp++;
				if (little[cmp] == 0)
					return ((char *)big + i);
			}
		}
		i++;
	}
	return (0);
}
