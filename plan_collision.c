/*
** plan_collision.c for plan_collision in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Fri Mar  4 00:09:43 2016 menett_a
** Last update Sun Mar 13 21:58:00 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include "proto.h"
#include "struct.h"

void	plan_normal(t_loop *data, int i)
{
  data->norm.n_x = data->info.plan[i].pos_x;
  data->norm.n_y = data->info.plan[i].pos_y;
  data->norm.n_z = data->info.plan[i].pos_z;
}

void		calcul_plan(t_loop *data, int i)
{
  double	dist;

  data->delta.a =
    data->info.plan[i].pos_x * (data->pos_x - data->info.plan[i].x) +
    data->info.plan[i].pos_y * (data->pos_y - data->info.plan[i].y) +
    data->info.plan[i].pos_z * (data->pos_z - data->info.plan[i].z);
  data->delta.b =
    data->info.plan[i].pos_x * data->ray.vec_x +
    data->info.plan[i].pos_y * data->ray.vec_y +
    data->info.plan[i].pos_z * data->ray.vec_z;
  if (data->delta.b != 0)
    data->collision.x = -(data->delta.a / data->delta.b);
  if (data->collision.x > 0.01)
    {
      calcul_pos(data, data->collision.x, &dist);
      if (dist < data->collision.dist || data->collision.dist == 0)
  	{
  	  data->collision.dist = dist;
	  plan_normal(data, i);
	  quadrillage(&data->collision);
	  data->collision.is_collision = 1;
  	}
    }
}

void	plan_collision(t_loop *data, t_info *plan)
{
  int	i;

  i = 0;
  while (i < plan->nb_plan)
    {
      calcul_plan(data, i);
      if (data->collision.is_collision == 1)
	find_light(data);
      i = i + 1;
    }
}
