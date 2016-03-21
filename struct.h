/*
** struct.h for struct in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Sun Feb 28 16:39:55 2016 menett_a
** Last update Sun Mar 13 21:40:51 2016 menett_a
*/

#ifndef	STRUCT_H_
# define STRUCT_H_

typedef struct		s_sphe
{
  int			pos_x;
  int			pos_y;
  int			pos_z;
  int			radius;
  int			color;
}			t_sphe;

typedef struct		s_cone
{
  int			pos_x;
  int			pos_y;
  int			pos_z;
  int			angle;
  int			color;
}			t_cone;

typedef struct		s_plan
{
  int			pos_x;
  int			pos_y;
  int			pos_z;
  int			x;
  int			y;
  int			z;
  int			color;
}			t_plan;

typedef struct		s_cyli
{
  int			pos_y;
  int			pos_z;
  int			radius;
  int			color;
}			t_cyli;

typedef struct		s_light
{
  int			pos_x;
  int			pos_y;
  int			pos_z;
  int			brt;
}			t_light;

typedef struct		s_view
{
  int			angle;
  t_bunny_position	screen_info[2];
}			t_view;

typedef struct		s_info
{
  int			nb_sphere;
  int			nb_light;
  int			nb_cone;
  int			nb_plan;
  int			nb_cyli;
  t_view		screen_info;
  t_sphe		*sphe;
  t_cone		*cone;
  t_plan		*plan;
  t_cyli		*cyli;
  t_light		*light;
}			t_info;

typedef struct		s_delta
{
  double		a;
  double		b;
  double		c;
  double		delta;
}			t_delta;

typedef struct		s_norm
{
  double		n_x;
  double		n_y;
  double		n_z;
  double		res;
  double		_res;
  double		__res;
}			t_norm;

typedef struct		s_ray
{
  double		vec_x;
  double		vec_y;
  double		vec_z;
  double		light_x;
  double		light_y;
  double		light_z;
  int			i;
  int			j;
}			t_ray;

typedef struct		s_pall
{
  t_color		color[6];
}			t_pall;

typedef struct		s_collision
{
  t_bunny_position	pos;
  double		x;
  double		_x;
  double		pos_x;
  double		pos_y;
  double		pos_z;
  double		dist;
  int			color;
  t_color		_color;
  int			is_collision;
}			t_collision;

typedef struct		s_move
{
  int			move_x;
  int			move_y;
  int			move_z;
  int			_move_x;
  int			_move_y;
  int			_move_z;
  int			angle;
  int			_angle;
}			t_move;

typedef struct		s_loop
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  int			pos_x;
  int			pos_y;
  int			pos_z;
  t_norm		norm;
  t_move		move;
  t_info		info;
  t_ray			ray;
  t_pall		pall;
  t_delta		delta;
  t_collision		collision;
}			t_loop;

#endif /* !STRUCT_H_ */
