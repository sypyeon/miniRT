/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:35:54 by sipyeon           #+#    #+#             */
/*   Updated: 2025/06/28 16:05:50 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils_vector.h"


double	rt_vec_len_sq(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	rt_vec_len(t_vec vec)
{
	return (sqrt(rt_vec_len_sq(vec)));
}
