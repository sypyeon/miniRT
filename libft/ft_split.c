/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:44:43 by sipyeon           #+#    #+#             */
/*   Updated: 2025/04/22 20:57:53 by seungsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup_split(char const *src, size_t size)
{
	size_t		i;
	char		*cpy;

	cpy = (char *)malloc((size + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (i == 0)
		{
			if (s[i] != c)
				word_count++;
		}
		else
		{
			if (s[i - 1] == c && s[i] != c)
				word_count++;
		}
		i++;
	}
	return (word_count);
}

static void	free_alloc(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**ft_split_start(char **split_str, const char *s, char c)
{
	size_t	i;
	size_t	str;
	size_t	split_i;

	i = 0;
	split_i = 0;
	while (s[i] && ft_word_count(s, c) > 0)
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		str = i;
		while (s[i] != c && s[i])
			i++;
		split_str[split_i++] = ft_strdup_split(s + str, i - str);
		if (!split_str[split_i - 1])
		{
			free_alloc(split_str);
			return (NULL);
		}
	}
	split_str[split_i] = NULL;
	return (split_str);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;

	if (!s)
		return (NULL);
	split_str = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!split_str)
		return (NULL);
	return (ft_split_start(split_str, s, c));
}
