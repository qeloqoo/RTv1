/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 18:05:03 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:51:52 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_quat	quat_create(t_vector v, double w)
{
	t_quat	res;
	double	tmp;

	v = vector_norm(v);
	tmp = sin(deg2rad(w / 2.0));
	res.w = cos(deg2rad(w / 2.0));
	res.x = v.x * tmp;
	res.y = v.y * tmp;
	res.z = v.z * tmp;
	return (res);
}

t_quat	quat_scale(t_quat q, double val)
{
	q.w = q.w * val;
	q.x = q.x * val;
	q.y = q.y * val;
	q.z = q.z * val;
	return (q);
}

double	quat_len(t_quat q)
{
	return (sqrt(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z));
}

t_quat	quat_norm(t_quat q)
{
	double n;

	n = quat_len(q);
	n = (n != 0.0) ? 1 / n : 1;
	return (quat_scale(q, n));
}

t_quat	quat_inv(t_quat q)
{
	q.x = -q.x;
	q.y = -q.y;
	q.z = -q.z;
	return (quat_norm(q));
}
