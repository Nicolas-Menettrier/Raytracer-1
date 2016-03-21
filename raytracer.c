/*
** raytracer.c for raytracer in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Tue Mar  1 22:02:01 2016 menett_a
** Last update Sat Mar 12 16:42:42 2016 menett_a
*/

#include <lapin.h>
#include <unistd.h>
#include "struct.h"
#include "proto.h"

void		check_collision(t_loop *data)
{
  sphere_collision(data, &data->info);
  plan_collision(data, &data->info);
  cone_collision(data, &data->info);
  cylinder_collision(data, &data->info);
}

void		raytracer(t_loop *data)
{
  data->ray.j = 0;
  while (data->ray.j < data->pix->clipable.clip_height)
    {
      data->ray.i = 0;
      while (data->ray.i < data->pix->clipable.clip_width)
	{
	  init_values(data);
	  vec_normalize(&data->ray.vec_x, &data->ray.vec_y,
			&data->ray.vec_z);
	  check_collision(data);
	  if (data->collision.dist == 0)
	    data->collision._color.full = BLACK;
	  tekpixel(data->pix, &data->collision.pos, &data->collision._color);
	  data->ray.i = data->ray.i + 1;
	}
      data->ray.j = data->ray.j + 1;
    }
}
