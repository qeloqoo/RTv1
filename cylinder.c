/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:50:46 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:24:30 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_prim		*create_cylinder(t_vector pos, t_vector dir, double radius,
		int color)
{
	static const PFI	vtable = {F_CYLIND_I, F_CYLIND_N, F_CYLIND_C};
	static t_prim		base = {&vtable};
	t_cylinder			*c;

	c = malloc(sizeof(*c));
	ft_memcpy(&c->base, &base, sizeof(base));
	c->pos = pos;
	c->dir = dir;
	c->radius = radius;
	c->col = color;
	return (&c->base);
}

double		find_cylinder_intersect(t_prim *f, t_ray r)
{
	t_cylinder	*c;
	double		r_r;
	double		d_v;
	double		x_v;
	t_vector	x;

	c = (void*)f;
	r_r = c->radius * c->radius;
	x = vector_sum(r.pos, '-', c->pos);
	d_v = vector_dot(r.dir, c->dir);
	x_v = vector_dot(x, c->dir);
	return (sqr_equation(1 - d_v * d_v, 2 * (vector_dot(r.dir, x) - d_v * x_v),
		vector_dot(x, x) - x_v * x_v - r_r));
}

t_vector	find_cylinder_normal(t_prim *f, t_ray r, double dist)
{
	t_cylinder	*c;
	double		m;
	double		d_v;
	t_vector	p;

	c = (void*)f;
	d_v = vector_dot(r.dir, c->dir);
	p = vector_sum(r.pos, '+', vector_mult(r.dir, dist));
	m = d_v * dist + vector_dot(vector_sum(r.pos, '-', c->pos), c->dir);
	return (vector_norm(vector_sum(vector_sum(p, '-', c->pos), '-',
		vector_mult(c->dir, m))));
}

int			find_cylinder_color(t_prim *f)
{
	t_cylinder *c;

	c = (void*)f;
	return (c->col);
}
