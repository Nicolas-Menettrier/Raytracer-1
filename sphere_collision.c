/*
** sphere_collision.c for sphere_collision in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Tue Mar  1 23:31:49 2016 menett_a
** Last update Sat Mar 12 16:39:57 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "proto.h"

void	sphere_norm(t_loop *data, int i)
{
  data->norm.n_x = data->collision.pos_x - data->info.sphe[i].pos_x;
  data->norm.n_y = data->collision.pos_y - data->info.sphe[i].pos_y;
  data->norm.n_z = data->collision.pos_z - data->info.sphe[i].pos_z;
}

void		save_collision(t_loop *data, int i, double x)
{
  double	dist;

  calcul_pos(data, x, &dist);
  if (dist < data->collision.dist || data->collision.dist == 0)
    {
      data->collision.dist = dist;
      sphere_norm(data, i);
      data->collision.color = data->info.sphe[i].color;
      data->collision.is_collision = 1;
    }
}

void	x_two(t_loop *data, int i)
{
  if (data->collision.x < data->collision._x
      && data->collision.x > 0.01)
    save_collision(data, i, data->collision.x);
  else if (data->collision._x < data->collision.x
  	   && data->collision._x > 0.01)
    save_collision(data, i, data->collision._x);
}

void	calcul_sphere(t_loop *data, t_info *sphe, int i)
{
  data->delta.a =
    pow(data->ray.vec_x, 2) + pow(data->ray.vec_y, 2) +
    pow(data->ray.vec_z, 2);
  data->delta.b =
    2 * (data->pos_x - sphe->sphe[i].pos_x) * data->ray.vec_x +
    2 * (data->pos_y - sphe->sphe[i].pos_y) * data->ray.vec_y +
    2 * (data->pos_z - sphe->sphe[i].pos_z) * data->ray.vec_z;
  data->delta.c =
    pow(data->pos_x - sphe->sphe[i].pos_x, 2)
    + pow(data->pos_y - sphe->sphe[i].pos_y, 2)
    + pow(data->pos_z - sphe->sphe[i].pos_z, 2) - pow(sphe->sphe[i].radius, 2);
  data->delta.delta = pow(data->delta.b, 2) - 4 * data->delta.a * data->delta.c;
  if (find_delta(data) == 2)
    x_two(data, i);
}

void	sphere_collision(t_loop *data, t_info *sphe)
{
  int	i;

  i = 0;
  while (i < sphe->nb_sphere)
    {
      calcul_sphere(data, sphe, i);
      if (data->collision.is_collision == 1)
	find_light(data);
      i = i + 1;
    }
}
