/*
** delta.c for delta in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Wed Mar  2 11:17:12 2016 menett_a
** Last update Thu Mar  3 21:40:55 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include <unistd.h>
#include "struct.h"
#include "proto.h"

int	find_delta(t_loop *data)
{
  if (data->delta.delta == 0)
    {  
      data->collision.x = (-data->delta.b) / (2 * data->delta.a);
      return (1);
    }
  else if (data->delta.delta > 0)
    {
      data->collision.x = (-data->delta.b + sqrt(data->delta.delta))
	/ (2 * data->delta.a);
      data->collision._x = (-data->delta.b - sqrt(data->delta.delta))
	/ (2 * data->delta.a);
      return (2);
    }
  return (0);
}
