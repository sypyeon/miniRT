/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:27:29 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/15 20:14:19 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	total_size;

	if (size && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	total_size = (nmemb * size);
	alloc = malloc(total_size);
	if (!alloc)
		return (NULL);
	ft_memset(alloc, 0, total_size);
	return (alloc);
}
