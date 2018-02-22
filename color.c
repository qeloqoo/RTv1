/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:10:50 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:10:40 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color	color_mult(t_color col, double n)
{
	col.r *= n;
	col.g *= n;
	col.b *= n;
	return (col);
}

t_color	color_add(t_color col1, t_color col2)
{
	col1.r += col2.r;
	col1.g += col2.g;
	col1.b += col2.b;
	return (col1);
}

t_color	color_clamp(t_color col)
{
	col.r < 0.0 ? col.r = 0.0 : 1;
	col.r > 1.0 ? col.r = 1.0 : 1;
	col.g < 0.0 ? col.g = 0.0 : 1;
	col.g > 1.0 ? col.g = 1.0 : 1;
	col.b < 0.0 ? col.b = 0.0 : 1;
	col.b > 1.0 ? col.b = 1.0 : 1;
	return (col);
}

int		drgb2hex(double rr, double gg, double bb)
{
	int r;
	int g;
	int b;

	r = rr * 255;
	g = gg * 255;
	b = bb * 255;
	r = ((r << 16) & 0xFF0000);
	g = ((g << 8) & 0x00FF00);
	b = (b & 0x0000FF);
	return (r | g | b);
}

void	color_pixel(t_viewport *v, int x, int y, int col)
{
	int	byte;

	byte = (x * v->bits_per_pixel / 8) + (y * v->size_line);
	v->pxls[byte] = col;
	v->pxls[++byte] = col >> 8;
	v->pxls[++byte] = col >> 16;
}
