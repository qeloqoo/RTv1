/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:22:01 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:26:45 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_cylinder(t_viewport *v, char **tmp)
{
	t_vector	vec[2];
	double		radius;

	if (array_len(tmp) < 9)
		end_prog(1);
	vec[0] = vector_create(ft_atod(tmp[1]), ft_atod(tmp[2]),
		ft_atod(tmp[3]));
	vec[1] = vector_norm(vector_create(ft_atod(tmp[4]), ft_atod(tmp[5]),
		ft_atod(tmp[6])));
	radius = ft_atod(tmp[7]);
	prim_list_add(v, create_cylinder(vec[0], vec[1], radius,
		ft_atoi_base(tmp[8], 16)));
}

void	parse_cone(t_viewport *v, char **tmp)
{
	t_vector	vec[2];
	double		angle;

	if (array_len(tmp) < 9)
		end_prog(1);
	vec[0] = vector_create(ft_atod(tmp[1]), ft_atod(tmp[2]),
		ft_atod(tmp[3]));
	vec[1] = vector_norm(vector_create(ft_atod(tmp[4]), ft_atod(tmp[5]),
		ft_atod(tmp[6])));
	angle = ft_atod(tmp[7]);
	prim_list_add(v, create_cone(vec[0], vec[1], angle,
		ft_atoi_base(tmp[8], 16)));
}

void	parse_camera(t_viewport *v, char **tmp)
{
	if (array_len(tmp) < 10)
		end_prog(1);
	v->scene.cam.pos = vector_create(ft_atod(tmp[1]),
		ft_atod(tmp[2]), ft_atod(tmp[3]));
	v->scene.cam.dir = vector_create(0.0, 1.0, 0.0);
	v->scene.cam.pitch = ft_atoi(tmp[4]);
	v->scene.cam.roll = ft_atoi(tmp[5]);
	v->scene.cam.yaw = ft_atoi(tmp[6]);
	v->scene.cam.fov = ft_atoi(tmp[7]);
	v->scene.ambient = ft_atod(tmp[8]);
	v->scene.col = ft_atoi_base(tmp[9], 16);
}

void	parse_line(t_viewport *v, char **tmp)
{
	if (ft_strequ(tmp[0], "camera"))
		parse_camera(v, tmp);
	else if (ft_strequ(tmp[0], "light"))
		parse_light(v, tmp);
	else if (ft_strequ(tmp[0], "plane"))
		parse_plane(v, tmp);
	else if ((ft_strequ(tmp[0], "sphere")))
		parse_sphere(v, tmp);
	else if ((ft_strequ(tmp[0], "cylinder")))
		parse_cylinder(v, tmp);
	else if ((ft_strequ(tmp[0], "cone")))
		parse_cone(v, tmp);
	else if ((ft_strequ(tmp[0], "#")))
		;
	else
		end_prog(2);
}

void	file_read(t_viewport *v, char *file)
{
	int		fd;
	int		flag;
	char	*str;
	char	**tmp;

	if ((fd = open(file, O_RDONLY)) == -1)
		end_prog(3);
	else
	{
		while ((flag = get_next_line(fd, &str)) == 1)
		{
			tmp = ft_strsplit(str, ' ');
			parse_line(v, tmp);
			free(str);
			free_array(tmp);
		}
		if (flag == -1)
		{
			free(str);
			end_prog(3);
		}
	}
}
