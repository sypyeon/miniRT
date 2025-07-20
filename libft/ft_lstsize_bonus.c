/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:04:33 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/11 16:27:13 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	lst_size;

	if (!lst)
		return (0);
	lst_size = 0;
	while (lst)
	{
		lst_size++;
		lst = lst -> next;
	}
	return (lst_size);
}
