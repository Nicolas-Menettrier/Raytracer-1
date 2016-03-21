/*
** cylinder_collision.c for cylinder_collision in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Sun Mar  6 14:38:49 2016 menett_a
** Last update Sun Mar 13 21:57:15 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "proto.h"

void	cylinder_norm(t_loop *data, int i)
{
  data->norm.n_x = 0;
  data->norm.n_y = data->collision.pos_y - data->info.cyli[i].pos_y;
  data->norm.n_z = data->collision.pos_z - data->info.cyli[i].pos_z;
}

void		save_cyli_coll(t_loop *data, int i, double x)
{
  double	dist;

  calcul_pos(data, x, &dist);
  if (dist < data->collision.dist || data->collision.dist == 0)
    {
      data->collision.dist = dist;
      cylinder_norm(data, i);
      data->collision.color = data->info.cyli[i].color;
      data->collision.is_collision = 1;
    }
}

void	cylinder_two(t_loop *data, int i)
{
  if (data->collision.x < data->collision._x
      && data->collision.x > 0.01)
    save_cyli_coll(data, i, data->collision.x);
  else if (data->collision._x < data->collision.x
  	   && data->collision._x > 0.01)
    save_cyli_coll(data, i, data->collision._x);
}

void	calcul_cylinder(t_loop *data, t_info *cyli, int i)
{
  data->delta.a =
    pow(data->ray.vec_y, 2) + pow(data->ray.vec_z, 2);
  data->delta.b =
    2 * (data->ray.vec_y * (data->pos_y - data->info.cyli[i].pos_y)
	 + data->ray.vec_z * (data->pos_z - data->info.cyli[i].pos_z));
  data->delta.c =
    pow(data->pos_y - data->info.cyli[i].pos_y, 2) +
    pow(data->pos_z - data->info.cyli[i].pos_z, 2) -
    pow(cyli->cyli[i].radius, 2);
  data->delta.delta = pow(data->delta.b, 2) -
    4 * data->delta.a * data->delta.c;
  if (find_delta(data) == 2)
    cylinder_two(data, i);
}

void	cylinder_collision(t_loop *data, t_info *cyli)
{
  int	i;

  i = 0;
  while (i < cyli->nb_cyli)
    {
      calcul_cylinder(data, cyli, i);
      if (data->collision.is_collision == 1)
	find_light(data);
      i = i + 1;
    }
}
