/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 13:34:37 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:17:14 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_prim		*create_cone(t_vector pos, t_vector dir, double angle, int color)
{
	static const PFI	vtable = {F_CONE_I, F_CONE_N, F_CONE_C};
	static t_prim		base = {&vtable};
	t_cone				*c;

	c = malloc(sizeof(*c));
	ft_memcpy(&c->base, &base, sizeof(base));
	c->pos = pos;
	c->dir = dir;
	c->angle = angle;
	c->col = color;
	return (&c->base);
}

double		find_cone_intersect(t_prim *f, t_ray r)
{
	t_cone		*c;
	double		k_k;
	double		d_v;
	double		x_v;
	t_vector	x;

	c = (void*)f;
	x = vector_sum(r.pos, '-', c->pos);
	k_k = d_power(tan((c->angle / 2.0) * M_PI / 180), 2);
	d_v = vector_dot(r.dir, c->dir);
	x_v = vector_dot(x, c->dir);
	return (sqr_equation((1 - (1 + k_k) * d_v * d_v),
		2 * ((vector_dot(r.dir, x) - (1 + k_k) * d_v * x_v)),
		(vector_dot(x, x) - (1 + k_k) * x_v * x_v)));
}

t_vector	find_cone_normal(t_prim *f, t_ray r, double dist)
{
	t_cone		*c;
	double		m;
	double		d_v;
	double		k;
	t_vector	p;

	c = (void*)f;
	d_v = vector_dot(r.dir, c->dir);
	k = tan((c->angle / 2.0) * M_PI / 180);
	p = vector_sum(r.pos, '+', vector_mult(r.dir, dist));
	m = d_v * dist + vector_dot(vector_sum(r.pos, '-', c->pos), c->dir);
	return (vector_norm(vector_sum(vector_sum(p, '-', c->pos), '-',
		vector_mult(c->dir, m * (1 + k * k)))));
}

int			find_cone_color(t_prim *f)
{
	t_cone *c;

	c = (void*)f;
	return (c->col);
}
