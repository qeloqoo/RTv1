/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:21:16 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:55:42 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			check_intersect(t_viewport *v, t_ray r, t_primlist **res)
{
	t_primlist	*cur;
	double		dist;
	double		curdist;

	dist = -1.0;
	curdist = dist;
	cur = SC.obj;
	while (cur != NULL)
	{
		curdist = find_intersect(cur->prim, r);
		if ((curdist > 0) && (curdist < dist || dist == -1.0))
		{
			dist = curdist;
			*res = cur;
		}
		cur = cur->next;
	}
	return (dist);
}

static double	calc_shadow(t_viewport *v, t_vector p, t_vector norm,
		t_lightlist *cur)
{
	t_primlist	*object;
	t_ray		shadow_r;
	double		dist[2];
	double		intensity;
	double		res;

	shadow_r.pos = p;
	shadow_r.dir = vector_sum(ENT->pos, '-', p);
	dist[0] = vector_len(shadow_r.dir);
	intensity = ENT->energy * (d_power(ENT->falloff, 2) /
		(d_power(ENT->falloff, 2) +
			vector_dot(shadow_r.dir, shadow_r.dir)));
	shadow_r.dir = vector_norm(shadow_r.dir);
	dist[1] = check_intersect(v, shadow_r, &object);
	res = 1.0 - SC.ambient;
	if (dist[1] == -1.0 || dist[1] > dist[0])
	{
		res *= vector_dot(norm, shadow_r.dir) * intensity;
		res *= (res > 0.0) ? 1.0 : 0.0;
	}
	else
		res = 0.0;
	return (res);
}

double			trace_shadow(t_viewport *v, t_vector p, t_vector norm)
{
	t_lightlist	*cur;
	double		res;
	int			i;

	i = 0;
	res = 0.0;
	cur = SC.light;
	while (cur != NULL)
	{
		res += calc_shadow(v, p, norm, cur);
		i++;
		cur = cur->next;
	}
	res = (i != 0) ? res / i : 0;
	res += d_power(res, 16);
	return (res);
}

t_color			trace_ray(t_viewport *v, t_ray r)
{
	t_primlist	*object;
	double		dist;
	t_vector	norm;
	t_vector	p;
	t_color		col[2];

	dist = -1.0;
	object = NULL;
	dist = check_intersect(v, r, &object);
	if (object != NULL)
	{
		norm = find_normal(object->prim, r, dist);
		p = vector_sum(vector_mult(r.dir, dist), '+', r.pos);
		col[0] = hex2rgb(find_color(object->prim));
		col[1] = color_mult(col[0], trace_shadow(v, p, norm));
		col[0] = color_add(color_mult(col[0], SC.ambient), col[1]);
	}
	else
		col[0] = hex2rgb(SC.col);
	return (col[0]);
}

void			cast_rays(t_viewport *v)
{
	t_ray	r;
	int		xy[2];
	double	pr[4];
	t_color	color;
	t_quat	camrot;

	pr[0] = WIN_W / (double)WIN_H;
	pr[1] = tan(SC.cam.fov / 2 * M_PI / 180);
	r.pos = SC.cam.pos;
	camrot = quat_cam_pry(SC.cam.pitch, SC.cam.roll, SC.cam.yaw);
	xy[0] = -1;
	while (++xy[0] < WIN_W)
	{
		pr[2] = (2 * (xy[0] + 0.5) / WIN_W - 1) * pr[0] * pr[1];
		xy[1] = -1;
		while (++xy[1] < WIN_H)
		{
			pr[3] = (1 - 2 * (xy[1] + 0.5) / WIN_H) * pr[1];
			r.dir = vector_norm((vector_create(pr[2], SC.cam.dir.y, pr[3])));
			r.dir = quat_trans_v(camrot, r.dir);
			color = color_clamp(trace_ray(v, r));
			color_pixel(v, xy[0], xy[1], drgb2hex(color.r, color.g, color.b));
		}
	}
}
