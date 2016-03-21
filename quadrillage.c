/*
** quadrillage.c for quadrillage in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Mon Mar  7 13:22:48 2016 menett_a
** Last update Thu Mar 10 02:27:02 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "proto.h"

void		quadrillage(t_collision *collision)
{
  double	x;
  double	y;
  double	z;

  if ((x = (collision->pos_x / 1.75)) < 0)
    x = -x + 1;
  if ((y = (collision->pos_y / 1.75)) < 0)
    y = -y + 1;
  if ((z = (collision->pos_z / 1.75)) < 0)
    z = -z + 1;
  if ((int)z % 2 == 0)
    {
      if (((int)x % 2 == 0 && (int)y % 2 == 0)
	  || ((int)x % 2 == 1 && (int)y % 2 == 1))
	collision->color = 0;
      else
	collision->color = 1;
        }
  else
    {
      if (((int)x % 2 == 0 && (int)y % 2 == 0)
  	  || ((int)x % 2 == 1 && (int)y % 2 == 1))
  	collision->color = 1;
      else
  	collision->color = 0;
    }
}
