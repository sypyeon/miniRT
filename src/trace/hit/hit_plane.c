/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:06:06 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/23 07:06:42 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/trace.h"

_Bool	hit_plane(t_obj *pl_obj, t_ray *ray, t_hit_record *rec)
{
    t_plane	*pl;
    t_vec	oc;
    double	denom;
    double	t;
    double	numer;

    pl = &pl_obj->data.pl;
    
    // 광선 방향과 평면 법선의 내적
    denom = vdot(ray->dir, pl->norm);
    
    // 평행한 경우 (광선이 평면과 평행)
    if (fabs(denom) < 1e-8)
        return (0);
    
    // 광선 시작점에서 평면 위의 점으로의 벡터
    oc = vminus(pl_obj->origin, ray->orig);
    
    // 교차점까지의 거리 계산
    numer = vdot(oc, pl->norm);
    t = numer / denom;
    
    // 범위 체크
    if (t < rec->tmin || t > rec->tmax)
        return (0);
    
    // 교차 정보 기록
    rec->t = t;
    rec->p = ray_at(ray, t);
    rec->norm = pl->norm;  // 평면의 법선 사용
    set_face_normal(ray, rec);
    rec->albedo = pl_obj->color;
    
    return (1);
}
