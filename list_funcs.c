/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 12:49:32 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 20:28:17 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	prim_list_add(t_viewport *v, t_prim *fig)
{
	t_primlist	*temp;

	temp = NULL;
	if (v->scene.obj != NULL)
		temp = v->scene.obj;
	v->scene.obj = (t_primlist*)malloc(sizeof(t_primlist));
	v->scene.obj->prim = fig;
	v->scene.obj->next = temp;
}

void	light_list_add(t_viewport *v, t_light *lit)
{
	t_lightlist *temp;

	temp = NULL;
	if (v->scene.light != NULL)
		temp = v->scene.light;
	v->scene.light = (t_lightlist*)malloc(sizeof(t_lightlist));
	v->scene.light->entity = lit;
	v->scene.light->next = temp;
}
