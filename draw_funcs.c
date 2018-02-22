/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:57:28 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/20 13:46:53 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		end_prog(int n)
{
	if (n == 0)
		;
	else if (n == 1)
		ft_putstr("Not enough data in one of the lines of the chosen scene\n");
	else if (n == 2)
		ft_putstr("Unexpected data in the chosen scene file\n");
	else if (n == 3)
		ft_putstr("Error while reading file\n");
	else if (n == 4)
		ft_putstr("Could not allocate memory\n");
	else if (n == 5)
		ft_putstr("No such scene exist\n");
	exit(0);
	return (0);
}

void	reload(t_viewport *v)
{
	v->img = mlx_new_image(v->mlx, WIN_W, WIN_H);
	v->pxls = mlx_get_data_addr(v->img, &(v->bits_per_pixel),
		&(v->size_line), &(v->endian));
	cast_rays(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	mlx_destroy_image(v->mlx, v->img);
}

int		expose(t_viewport *v)
{
	reload(v);
	return (0);
}

void	init_viewport(t_viewport *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIN_W, WIN_H, "RTv1");
	mlx_expose_hook(v->win, expose, v);
	mlx_hook(v->win, 2, 3, kbrd_hook, v);
	mlx_hook(v->win, 17, 0L, end_prog, NULL);
}

void	init_scene(t_viewport *v, int choice)
{
	if (choice == 0)
		file_read(v, "simple_sphere.rt");
	else if (choice == 1)
		file_read(v, "simple_cylinder.rt");
	else if (choice == 2)
		file_read(v, "cone_plane.rt");
	else if (choice == 3)
		file_read(v, "scene.rt");
	else if (choice == 4)
		file_read(v, "scene1.rt");
	else if (choice == 5)
		file_read(v, "scene2.rt");
	else if (choice == 666)
		file_read(v, "secret.rt");
	else
		end_prog(5);
}
