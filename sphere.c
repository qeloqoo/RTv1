/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:18:46 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 21:33:17 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_prim		*create_sphere(t_vector pos, double radius, int color)
{
	static const PFI	vtable = {F_SPHERE_I, F_SPHERE_N, F_SPHERE_C};
	static t_prim		base = {&vtable};
	t_sphere			*s;

	s = malloc(sizeof(*s));
	ft_memcpy(&s->base, &base, sizeof(base));
	s->pos = pos;
	s->radius = radius;
	s->col = color;
	return (&s->base);
}

double		find_sphere_intersect(t_prim *f, t_ray r)
{
	t_sphere	*s;
	t_vector	dist;

	s = (void*)f;
	dist = vector_sum(r.pos, '-', s->pos);
	return (sqr_equation(1.0, (2.0 * vector_dot(r.dir, dist)),
		(vector_dot(dist, dist) - (s->radius * s->radius))));
}

t_vector	find_sphere_normal(t_prim *f, t_ray r, double dist)
{
	t_sphere	*s;

	s = (void*)f;
	return (vector_norm(vector_sum(vector_sum(r.pos, '+',
		vector_mult(r.dir, dist)), '-', s->pos)));
}

int			find_sphere_color(t_prim *f)
{
	t_sphere *s;

	s = (void*)f;
	return (s->col);
}
