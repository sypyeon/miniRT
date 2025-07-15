/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:39:56 by sipyeon           #+#    #+#             */
/*   Updated: 2025/07/15 17:38:22 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_trace.h"
#include "rt_utils_vector.h"

#define FALSE	0
#define TRUE	1

void    set_face_normal(t_ray *r, t_hit_record *rec)
{
    // 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 앞면(객체의)에 hit 한 것이다
    rec->front_face = rt_vec_inner(r->direction, rec->normal) < 0;
    // 광선의 앞면에 hit 면 그대로 아니면 법선을 반대로 뒤집는다. (항상 광선 방향벡터와 법선 벡터를 반대인 상태로 사용하기위해)
    rec->normal = (rec->front_face) ? rec->normal : rt_vec_mult(rec->normal, -1);
}

bool	rt_hit_sphere(t_obj *sp, t_ray *ray, t_hit_record *rec)
{
	t_vec  oc;
	double  a;
	//b를 half_b로 변경
	double  half_b;
	double  c;
	double  discriminant; //판별식
	double  sqrt_d;
	double  root;
	oc = rt_vec_minus_vec(ray->origin, sp->center);
	a = rt_vec_len_sq(ray->direction);
	half_b = rt_vec_inner(oc, ray->direction);
	c = rt_vec_len_sq(oc) - sp->radius2;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrt_d = sqrt(discriminant);
	//두 실근(t) 중 tmin과 tmax 사이에 있는 근이 있는지 체크, 작은 근부터 체크.
	root = (-half_b - sqrt_d) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrt_d) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = rt_ray_at(ray, root);
	rec->normal = rt_vec_div(rt_vec_minus_vec(rec->p, sp->center), sp->radius); // 정규화된 법선 벡터.
	set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
	return (TRUE);
}

bool	rt_hit_obj(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	bool	hit_result;

	hit_result = FALSE;
	if (obj->type == SPHERE)
		hit_result = rt_hit_sphere(obj, ray, rec); // hit_sphere의 첫번째 인자도 t_sphere *에서 t_obj *로 수정해주자.
	return (hit_result);
}

bool	rt_hit(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec; // temp_rec의 tmin, tmax 값 초기화를 위해.
	hit_anything = FALSE;
	while (obj)
	{
		if (rt_hit_obj(obj, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		obj = obj->next;
	}
	return (hit_anything);
}
