/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:04:19 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/22 01:44:42 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

t_vec	parse_vec(char *param)
{
}

t_vec	nan_vec(void)
{
	return ((t_vec){.x = NAN, .y = NAN, .z = NAN});
}
