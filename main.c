/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:55:40 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:31:44 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char **argv)
{
	t_viewport	*v;
	int			choice;

	if (argc < 2)
		choice = 0;
	else
		choice = ft_atoi(argv[1]);
	if (!(v = (t_viewport*)ft_memalloc(sizeof(t_viewport))))
		end_prog(4);
	init_viewport(v);
	init_scene(v, choice);
	reload(v);
	mlx_loop(v->mlx);
	return (0);
}
