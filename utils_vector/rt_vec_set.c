/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 00:57:08 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 16:24:17 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_vector.h"

void	rt_set_vec(t_vec *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}
