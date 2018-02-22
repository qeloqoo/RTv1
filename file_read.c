/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:29:18 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:25:09 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		array_len(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i] != NULL)
		i++;
	return (i);
}

void	free_array(char **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i] != NULL)
		free(tmp[i]);
	free(tmp);
}

void	parse_light(t_viewport *v, char **tmp)
{
	t_vector vec;

	if (array_len(tmp) < 6)
		end_prog(1);
	vec = vector_create(ft_atod(tmp[1]),
		ft_atod(tmp[2]), ft_atod(tmp[3]));
	light_list_add(v, create_light(vec, ft_atod(tmp[4]), ft_atod(tmp[5])));
}

void	parse_plane(t_viewport *v, char **tmp)
{
	t_vector vec[2];

	if (array_len(tmp) < 8)
		end_prog(1);
	vec[0] = vector_create(ft_atod(tmp[1]), ft_atod(tmp[2]),
		ft_atod(tmp[3]));
	vec[1] = vector_norm(vector_create(ft_atod(tmp[4]), ft_atod(tmp[5]),
		ft_atod(tmp[6])));
	prim_list_add(v, create_plane(vec[0], vec[1], ft_atoi_base(tmp[7], 16)));
}

void	parse_sphere(t_viewport *v, char **tmp)
{
	t_vector	vec;

	if (array_len(tmp) < 6)
		end_prog(1);
	vec = vector_create(ft_atod(tmp[1]), ft_atod(tmp[2]),
		ft_atod(tmp[3]));
	prim_list_add(v, create_sphere(vec, ft_atod(tmp[4]),
		ft_atoi_base(tmp[5], 16)));
}
