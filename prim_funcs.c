/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prim_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 12:48:47 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:50:25 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

extern inline double	find_intersect(t_prim *f, t_ray r)
{
	return (f->vtable->intersect(f, r));
}

extern inline t_vector	find_normal(t_prim *f, t_ray r, double dist)
{
	return (f->vtable->normal(f, r, dist));
}

extern inline int		find_color(t_prim *f)
{
	return (f->vtable->color(f));
}
