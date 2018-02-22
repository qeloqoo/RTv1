/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:19:10 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 21:34:13 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			deg2rad(double deg)
{
	return (deg * M_PI / 180);
}

double			sqr_equation(double a, double b, double c)
{
	double	discr;
	double	sdiscr;
	double	t[2];

	t[0] = -1.0;
	t[1] = -1.0;
	discr = b * b - 4 * a * c;
	if (discr >= 0.0)
	{
		sdiscr = sqrt(discr);
		t[0] = (-b + sdiscr) / (2 * a);
		t[1] = (-b - sdiscr) / (2 * a);
		if (((t[0] > t[1] || t[0] < 0.1f) && t[1] != -1.0) || (t[0] == -1.0))
			t[0] = t[1];
		return (t[0]);
	}
	return (-1.0);
}

double			d_power(double number, int pow)
{
	if (pow == 0)
		return (1);
	return (number * d_power(number, pow - 1));
}

static double	fraction_part(char *str, int i)
{
	double	f;
	double	res;

	f = 1.0;
	res = 0.0;
	while (ft_isdigit(str[i]))
	{
		f *= 0.1;
		res += f * (str[i++] - '0');
	}
	return (res);
}

double			ft_atod(char *str)
{
	int		int_res;
	double	frac_res;
	int		sign;
	int		i;

	int_res = 0;
	sign = 1;
	i = 0;
	frac_res = 0.0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
		(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		int_res = (int_res * 10) + (str[i++] - '0');
	if (str[i] == '.')
		frac_res = fraction_part(str, ++i);
	return (sign * (int_res + frac_res));
}
