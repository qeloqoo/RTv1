/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_ops2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:17:34 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:53:37 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_quat		quat_mult_q(t_quat a, t_quat b)
{
	t_quat res;

	res.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	res.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
	res.y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x;
	res.z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w;
	return (res);
}

t_quat		quat_mult_v(t_quat a, t_vector b)
{
	t_quat res;

	res.w = -a.x * b.x - a.y * b.y - a.z * b.z;
	res.x = a.w * b.x + a.y * b.z - a.z * b.y;
	res.y = a.w * b.y - a.x * b.z + a.z * b.x;
	res.z = a.w * b.z + a.x * b.y - a.y * b.x;
	return (res);
}

t_vector	quat_trans_v(t_quat q, t_vector v)
{
	t_quat		tmp;
	t_vector	res;

	tmp = quat_mult_v(q, v);
	tmp = quat_mult_q(tmp, quat_inv(q));
	res = vector_create(tmp.x, tmp.y, tmp.z);
	return (res);
}

t_quat		quat_cam_pry(double pitch, double roll, double yaw)
{
	t_quat		qpitch;
	t_quat		qroll;
	t_quat		qyaw;
	t_quat		qtmp;

	qpitch = quat_create(vector_create(1.0, 0.0, 0.0), pitch);
	qroll = quat_create(vector_create(0.0, 1.0, 0.0), roll);
	qyaw = quat_create(vector_create(0.0, 0.0, 1.0), yaw);
	qtmp = quat_mult_q(qpitch, qroll);
	qtmp = quat_mult_q(qtmp, qyaw);
	return (qtmp);
}
