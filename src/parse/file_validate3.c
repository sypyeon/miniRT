/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validate3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 22:15:49 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/21 01:49:18 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int	is_punc(char c)
{
	return (c == '.' || c == ',');
}

void	check_ln_nums(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_punc(line[i]))
		{
			i++;
			if (line[i] == '-' || line[i] == '+')
				i++;
			if (!ft_isdigit(line[i]))
			{
				free(line);
				return (print_err_ln("Invalid numbers found."));
			}
		}
		i++;
	}
}

char	**gnl_split(char *file)
{
	int		fd;
	char	*buf;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_err_ln("open failure."), NULL);
	line = ft_strdup("");
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		line = ft_strjoin_(line, buf);
	}
	ft_tab_to_space(line);
	check_ln_nums(line);
	split = ft_split(line, '\n');
	free(line);
	return (split);
}

void	fvalidate_save(char *file, t_scene *info)
{
	_Bool	invalid;
	int		i;
	char	**split;

	if (!valid_file_fmt(file))
		return (print_err_ln("Wrong file format."));
	split = gnl_split(file);
	if (!split)
		return (print_err_ln("Split failure."));
	i = 0;
	while (split[i])
	{
		invalid = split_identify_line(split[i], info);
		if (invalid)
		{
			free_obj(info);
			free_split(split);
			return ;
		}
		i++;
	}
	free_split(split);
	info->curr = info->obj_lst.head;
}
