/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:10:58 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/21 06:28:53 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_strcmp(const char *str, const char *cmp)
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

char	*ft_strjoin_(char *s1, char *s2)
{
	size_t	total_len;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * total_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, total_len + 1);
	ft_strlcat(new_str, s2, total_len + 1);
	free(s1);
	free(s2);
	return (new_str);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
