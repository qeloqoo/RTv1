/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:44:29 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:49:47 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_prim		*create_plane(t_vector pos, t_vector norm, int color)
{
	static const PFI	vtable = {F_PLANE_I, F_PLANE_N, F_PLANE_C};
	static t_prim		base = {&vtable};
	t_plane				*p;

	p = malloc(sizeof(*p));
	ft_memcpy(&p->base, &base, sizeof(base));
	p->pos = pos;
	p->norm = norm;
	p->col = color;
	return (&p->base);
}

double		find_plane_intersect(t_prim *f, t_ray r)
{
	t_plane		*p;
	double		d_v;
	double		x_v;
	double		dist;

	p = (void*)f;
	d_v = vector_dot(r.dir, p->norm);
	if (d_v == 0.0)
		return (-1.0);
	x_v = vector_dot(vector_sum(r.pos, '-', p->pos), p->norm);
	if ((x_v > 0.0 && d_v < 0.0) || (x_v < 0.0 && d_v > 0.0))
	{
		dist = -x_v / d_v;
		dist = (dist < 0.1f) ? -1.0 : dist;
		return (dist);
	}
	else
		return (-1.0);
}

t_vector	find_plane_normal(t_prim *f, t_ray r, double dist)
{
	t_plane	*p;

	p = (void*)f;
	if (vector_dot(r.dir, p->norm) > 0.0 && dist != 0.0)
		return (vector_mult(p->norm, -1.0));
	return (p->norm);
}

int			find_plane_color(t_prim *f)
{
	t_plane *p;

	p = (void*)f;
	return (p->col);
}
