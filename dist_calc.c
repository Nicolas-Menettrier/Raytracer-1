/*
** dist_calc.c for dist_calc in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Thu Mar  3 12:55:42 2016 menett_a
** Last update Wed Mar  9 18:01:55 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "proto.h"

void	calcul_pos(t_loop *data, double x, double *dist)
{
  data->collision.pos_x = (double)data->pos_x + x * data->ray.vec_x;
  data->collision.pos_y = (double)data->pos_y + x * data->ray.vec_y;
  data->collision.pos_z = (double)data->pos_z + x * data->ray.vec_z;
  *dist = sqrt(pow(data->collision.pos_x - data->pos_x, 2)
	       + pow(data->collision.pos_y - data->pos_y, 2)
	       + pow(data->collision.pos_z - data->pos_z, 2));
}
