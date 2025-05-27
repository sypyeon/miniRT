/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:09:05 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/28 23:17:25 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start_i;
	size_t	end_i;
	char	*new_str;

	if (!s1)
		return (NULL);
	start_i = 0;
	while (ft_strchr(set, s1[start_i]) && s1[start_i])
		start_i++;
	end_i = ft_strlen(s1);
	if (end_i < 1)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end_i - 1]) && start_i < end_i)
		end_i--;
	new_str = (char *)malloc(sizeof(char) * (end_i - start_i + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < end_i - start_i && s1[start_i + i])
		new_str[i] = s1[start_i + i];
	new_str[i] = '\0';
	return (new_str);
}
