/*
** cone_collision.c for cone_collision in /home/nicolas/Modules/104intersection
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Sat Mar 12 16:10:10 2016 menett_a
** Last update Sun Mar 13 20:46:15 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "proto.h"

void		cone_norm(t_loop *data, int i)
{
  double	vx;
  double	vz;
  double	m;

  vx = data->collision.pos_x - data->info.cone[i].pos_x;
  vz = data->collision.pos_z - data->info.cone[i].pos_z;
  m = sqrt(vx * vx + vz * vz);
  vx = vx / m;
  vz = vz / m;
  data->norm.n_x = vx * 500 / data->info.cone[i].angle;
  data->norm.n_y = data->info.cone[i].angle / 500;
  data->norm.n_z = vz * 500 / data->info.cone[i].angle;
}

void	save_cone(t_loop *data, int i, double x)
{
  double	dist;

  calcul_pos(data, x, &dist);
  if (dist < data->collision.dist || data->collision.dist == 0)
    {
      data->collision.dist = dist;
      cone_norm(data, i);
      data->collision.color = data->info.cone[i].color;
      data->collision.is_collision = 1;
    }
}

void	find_cone(t_loop *data, int i)
{
  if (data->collision.x < data->collision._x
      && data->collision.x > 0.01)
    save_cone(data, i, data->collision.x);
  else if (data->collision._x < data->collision.x
  	   && data->collision._x > 0.01)
    save_cone(data, i, data->collision._x);
}

void	calcul_cone(t_loop *data, t_info *cone, int i)
{
  data->delta.a =
    pow(data->ray.vec_x, 2) + pow(data->ray.vec_z, 2)
    - pow(data->ray.vec_y, 2)
    * pow(tan(M_PI * cone->cone[i].angle / 180), 2);
  data->delta.b =
    (2 * (data->pos_x - cone->cone[i].pos_x) * data->ray.vec_x)
    + (2 * (data->pos_z - cone->cone[i].pos_z) * data->ray.vec_z)
    - (2 * (data->pos_y - cone->cone[i].pos_y)  * data->ray.vec_y)
    * pow(tan(M_PI * cone->cone[i].angle / 180), 2);
  data->delta.c =
    pow(data->pos_x - cone->cone[i].pos_x, 2)
    + pow(data->pos_z - cone->cone[i].pos_z, 2)
    - pow(data->pos_y - cone->cone[i].pos_y, 2)
    * pow(tan(M_PI * cone->cone[i].angle / 180) , 2);
  data->delta.delta = pow(data->delta.b, 2) -
    4 * data->delta.a * data->delta.c;
  if (find_delta(data) == 2)
    find_cone(data, i);
}

void	cone_collision(t_loop *data, t_info *cone)
{
  int	i;

  i = 0;
  while (i < cone->nb_cone)
    {
      calcul_cone(data, cone, i);
      if (data->collision.is_collision == 1)
	find_light(data);
      i = i + 1;
    }
}
