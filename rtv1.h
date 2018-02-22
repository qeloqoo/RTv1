/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubrovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:54:29 by mdubrovs          #+#    #+#             */
/*   Updated: 2017/06/07 21:31:52 by mdubrovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RTV1_H
# define __RTV1_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>

# define WIN_W 800
# define WIN_H 600
# define SC v->scene
# define ENT cur->entity
# define PFI t_primfuncinterface
# define F_CONE_I find_cone_intersect
# define F_CONE_N find_cone_normal
# define F_CONE_C find_cone_color
# define F_SPHERE_I find_sphere_intersect
# define F_SPHERE_N find_sphere_normal
# define F_SPHERE_C find_sphere_color
# define F_CYLIND_I find_cylinder_intersect
# define F_CYLIND_N find_cylinder_normal
# define F_CYLIND_C find_cylinder_color
# define F_PLANE_I find_plane_intersect
# define F_PLANE_N find_plane_normal
# define F_PLANE_C find_plane_color
# define KEY_ESC 53
# define KEY_NUM8 91
# define KEY_NUM2 84
# define KEY_NUM7 89
# define KEY_NUM9 92
# define KEY_NUM1 83
# define KEY_NUM3 85
# define KEY_NUM4 86
# define KEY_NUM6 88

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct	s_quat
{
	double	w;
	double	x;
	double	y;
	double	z;
}				t_quat;

typedef struct	s_ray
{
	t_vector	pos;
	t_vector	dir;
}				t_ray;

typedef struct	s_prim
{
	const struct s_primfuncinterface * const	vtable;
}				t_prim;

typedef struct	s_primfuncinterface
{
	double		(*intersect)(t_prim *, t_ray);
	t_vector	(*normal)(t_prim *, t_ray, double);
	int			(*color)(t_prim *);
}				t_primfuncinterface;

typedef	struct	s_primlist
{
	t_prim				*prim;
	struct s_primlist	*next;
}				t_primlist;

typedef struct	s_light
{
	t_vector	pos;
	double		energy;
	double		falloff;
	int			col;
}				t_light;

typedef	struct	s_lightlist
{
	t_light				*entity;
	struct s_lightlist	*next;
}				t_lightlist;

typedef	struct	s_camera
{
	t_vector	pos;
	t_vector	dir;
	double		pitch;
	double		roll;
	double		yaw;
	double		fov;
}				t_camera;

typedef struct	s_scene
{
	int			col;
	t_camera	cam;
	t_primlist	*obj;
	t_lightlist	*light;
	double		ambient;
}				t_scene;

typedef struct	s_viewport
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*pxls;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_scene	scene;
}				t_viewport;

typedef struct	s_sphere
{
	t_prim		base;
	t_vector	pos;
	double		radius;
	int			col;
}				t_sphere;

typedef	struct	s_plane
{
	t_prim		base;
	t_vector	pos;
	t_vector	norm;
	int			col;
}				t_plane;

typedef struct	s_cylinder
{
	t_prim		base;
	t_vector	pos;
	t_vector	dir;
	double		radius;
	int			col;
}				t_cylinder;

typedef struct	s_cone
{
	t_prim		base;
	t_vector	pos;
	t_vector	dir;
	double		angle;
	int			col;
}				t_cone;

void			prim_list_add(t_viewport *v, t_prim *fig);
void			light_list_add(t_viewport *v, t_light *lit);
void			cast_rays(t_viewport *v);
void			color_pixel(t_viewport *v, int x, int y, int col);
void			free_array(char **tmp);
void			parse_light(t_viewport *v, char **tmp);
void			parse_plane(t_viewport *v, char **tmp);
void			parse_sphere(t_viewport *v, char **tmp);
void			parse_cylinder(t_viewport *v, char **tmp);
void			parse_cone(t_viewport *v, char **tmp);
void			parse_camera(t_viewport *v, char **tmp);
void			parse_line(t_viewport *v, char **tmp);
void			file_read(t_viewport *v, char *file);
void			reload(t_viewport *v);
void			init_viewport(t_viewport *v);
void			init_scene(t_viewport *v, int choice);
t_prim			*create_plane(t_vector pos, t_vector norm, int color);
t_prim			*create_sphere(t_vector pos, double radius, int color);
t_prim			*create_cylinder(t_vector pos, t_vector dir, double radius,
					int color);
t_prim			*create_cone(t_vector pos, t_vector dir, double angle,
					int color);
t_light			*create_light(t_vector pos, double energy, double falloff);
double			find_intersect(t_prim *f, t_ray r);
double			check_intersect(t_viewport *v, t_ray r, t_primlist **res);
double			find_plane_intersect(t_prim *f, t_ray r);
double			find_sphere_intersect(t_prim *f, t_ray r);
double			find_cylinder_intersect(t_prim *f, t_ray r);
double			find_cone_intersect(t_prim *f, t_ray r);
double			deg2rad(double deg);
double			vector_len(t_vector a);
double			sqr_equation(double a, double b, double c);
double			trace_shadow(t_viewport *v, t_vector p, t_vector norm);
double			quat_len(t_quat q);
double			d_power(double number, int pow);
double			vector_dot(t_vector a, t_vector b);
double			ft_atod(char *str);
t_vector		find_normal(t_prim *f, t_ray r, double dist);
t_vector		find_plane_normal(t_prim *f, t_ray r, double dist);
t_vector		find_sphere_normal(t_prim *f, t_ray r, double dist);
t_vector		find_cylinder_normal(t_prim *f, t_ray r, double dist);
t_vector		find_cone_normal(t_prim *f, t_ray r, double dist);
t_vector		quat_trans_v(t_quat q, t_vector v);
t_vector		vector_sum(t_vector a, char s, t_vector b);
t_vector		vector_norm(t_vector a);
t_vector		vector_mult(t_vector a, double b);
t_vector		vector_create(double x, double y, double z);
int				find_color(t_prim *f);
int				find_plane_color(t_prim *f);
int				find_sphere_color(t_prim *f);
int				find_cylinder_color(t_prim *f);
int				find_cone_color(t_prim *f);
int				array_len(char **tmp);
int				drgb2hex(double rr, double gg, double bb);
int				end_prog(int n);
int				expose(t_viewport *v);
int				kbrd_hook(int keycode, t_viewport *v);
t_quat			quat_create(t_vector v, double w);
t_quat			quat_scale(t_quat q, double val);
t_quat			quat_norm(t_quat q);
t_quat			quat_inv(t_quat q);
t_quat			quat_mult_q(t_quat a, t_quat b);
t_quat			quat_mult_v(t_quat a, t_vector b);
t_quat			quat_cam_pry(double pitch, double roll, double yaw);
t_color			color_mult(t_color col, double n);
t_color			color_add(t_color col1, t_color col2);
t_color			color_clamp(t_color col);

#endif
