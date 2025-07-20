/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:37:35 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/27 16:49:13 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cut_line(char **read_line, char **save_line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *save_line;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	*save_line = ft_gnl_substr(*read_line, i + 1, ft_strlen(*read_line));
	free(tmp);
	tmp = *read_line;
	*read_line = ft_gnl_substr(*read_line, 0, i + 1);
	free(tmp);
}

static int	ft_read_file(int fd, char **buf, char **save_line)
{
	int		n;
	char	*tmp;

	if (!*save_line)
		*save_line = ft_gnl_strdup("");
	n = 1;
	while (!(ft_gnl_strchr(*save_line, '\n')) && n)
	{
		n = read(fd, *buf, BUFFER_SIZE);
		if (n == -1)
			return (-1);
		(*buf)[n] = '\0';
		tmp = *save_line;
		*save_line = ft_gnl_str_join(tmp, *buf);
		free(tmp);
		tmp = NULL;
		if (!*save_line)
			return (-1);
	}
	return (n);
}

static char	*ft_get_line(int fd, char **buf, char **save_line)
{
	int	n;

	n = ft_read_file(fd, buf, save_line);
	if (n == -1 || !save_line)
		return (NULL);
	if (n == 0 && !save_line)
		return (NULL);
	if (*save_line || n > 0)
		return (ft_strdup(*save_line));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save_line[1048577];
	char		*buf;
	char		*read_line;

	if (fd < 0 || fd > 1048576 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_line = ft_get_line(fd, &buf, &save_line[fd]);
	if (read_line)
		ft_cut_line(&read_line, &save_line[fd]);
	if (!read_line || *read_line == '\0')
	{
		free(save_line[fd]);
		save_line[fd] = NULL;
		free(read_line);
		read_line = NULL;
	}
	free(buf);
	return (read_line);
}
