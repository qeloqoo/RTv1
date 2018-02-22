/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:25:01 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 21:35:03 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		vector_dot(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vector	vector_sum(t_vector a, char s, t_vector b)
{
	t_vector	c;
	int			i;

	if (s == '-')
		i = -1;
	else if (s == '+')
		i = 1;
	else
		return (a);
	c.x = a.x + i * b.x;
	c.y = a.y + i * b.y;
	c.z = a.z + i * b.z;
	return (c);
}

double		vector_len(t_vector a)
{
	return (sqrt(vector_dot(a, a)));
}

t_vector	vector_norm(t_vector a)
{
	double		len;

	len = vector_len(a);
	if (len != 0)
	{
		a.x /= len;
		a.y /= len;
		a.z /= len;
	}
	return (a);
}

t_vector	vector_mult(t_vector a, double b)
{
	t_vector c;

	c.x = a.x * b;
	c.y = a.y * b;
	c.z = a.z * b;
	return (c);
}
