/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:37:37 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/27 16:49:58 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (0);
}

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substring;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substring = (char *)malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	i = 0;
	while (s[start + i] != 0 && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_gnl_str_join(char *dest, char *src)
{
	int		i;
	int		j;
	int		dest_len;
	int		src_len;
	char	*join;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	join = (char *)malloc(sizeof(char) * (dest_len + src_len + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (i < dest_len)
	{
		join[i] = dest[i];
		i++;
	}
	j = 0;
	while (j < src_len)
	{
		join[i + j] = src[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_gnl_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*dup;

	i = 0;
	s_len = 0;
	while (s[s_len] != 0)
		s_len++;
	dup = (char *)malloc(sizeof(char) * s_len + 1);
	if (!(dup))
		return (0);
	while (s[i] != 0)
	{
		dup[i] = s[i];
		i ++;
	}
	dup[i] = '\0';
	return (dup);
}
