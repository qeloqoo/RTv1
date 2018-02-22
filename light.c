/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 16:06:22 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:27:27 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light	*create_light(t_vector pos, double energy, double falloff)
{
	t_light	*lit;

	lit = malloc(sizeof(*lit));
	lit->pos = pos;
	lit->energy = energy;
	lit->falloff = falloff;
	return (lit);
}
