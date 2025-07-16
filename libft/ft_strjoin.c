/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:27:02 by sipyeon           #+#    #+#             */
/*   Updated: 2024/10/08 17:07:06 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*new_string;

	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)malloc(sizeof(char) * total_len + 1);
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, total_len + 1);
	ft_strlcat(new_string, s2, total_len + 1);
	return (new_string);
}
