/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:55:56 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/20 13:46:31 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			kbrd_hook(int keycode, t_viewport *v)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	else if (keycode == KEY_NUM8)
		SC.cam.pitch = (SC.cam.pitch < 359) ? SC.cam.pitch + 1 : 0;
	else if (keycode == KEY_NUM2)
		SC.cam.pitch = (SC.cam.pitch > -359) ? SC.cam.pitch - 1 : 0;
	else if (keycode == KEY_NUM7)
		SC.cam.roll = (SC.cam.roll > -359) ? SC.cam.roll - 1 : 0;
	else if (keycode == KEY_NUM9)
		SC.cam.roll = (SC.cam.roll < 359) ? SC.cam.roll + 1 : 0;
	else if (keycode == KEY_NUM1)
		SC.cam.fov -= (SC.cam.fov > 30) ? 1 : 0;
	else if (keycode == KEY_NUM3)
		SC.cam.fov += (SC.cam.fov < 90) ? 1 : 0;
	else if (keycode == KEY_NUM4)
		SC.cam.yaw = (SC.cam.yaw < 359) ? SC.cam.yaw + 1 : 0;
	else if (keycode == KEY_NUM6)
		SC.cam.yaw = (SC.cam.yaw > -359) ? SC.cam.yaw - 1 : 0;
	reload(v);
	return (0);
}
