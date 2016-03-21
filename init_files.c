/*
** init_window.c for init_window in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Tue Mar  1 21:41:04 2016 menett_a
** Last update Mon Mar 14 00:03:37 2016 menett_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

void	init_color(t_pall *color)
{
  color->color[0].full = BLACK;
  color->color[1].full = WHITE;
  color->color[2].full = RED;
  color->color[3].full = GREEN;
  color->color[4].full = BLUE;
  color->color[5].full = PINK;
}

void	init_values(t_loop *data)
{
  data->ray.vec_x = 0;
  data->ray.vec_y = 0;
  data->ray.vec_z = 0;
  data->collision.dist = 0;
  data->collision.color = 0;
  data->collision._color.full = BLACK;
  data->collision.pos.x = data->ray.i;
  data->collision.pos.y = data->ray.j;
  data->collision.is_collision = 0;
  data->ray.light_x = 0;
  data->ray.light_y = 0;
  data->ray.light_z = 0;
  data->info.screen_info.screen_info[1].y = data->pix->clipable.clip_height;
  data->info.screen_info.screen_info[1].x = data->pix->clipable.clip_width;
  data->info.screen_info.screen_info[0].y = data->ray.j;
  data->info.screen_info.screen_info[0].x = data->ray.i;
  tekray(&data->info.screen_info,
	 &data->ray.vec_x, &data->ray.vec_y, &data->ray.vec_z);
}

char	*init_view(t_bunny_ini *ini, t_loop *data)
{
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "view", 0),
		&data->pos_x) == -1)
    return ("Error while getting view's pos_x\n");
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "view", 1),
		&data->pos_y) == -1)
    return ("Error while getting view's pos_y\n");
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "view", 2),
		&data->pos_z) == -1)
    return ("Error while getting view's pos_z\n");
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "view", 3),
		&data->info.screen_info.angle) == -1)
    return ("Error while getting view's angle\n");
  return (NULL);
}

char	*init_window(t_loop *loop)
{
  if ((loop->win = bunny_start(600, 600, false, "raytracer1")) == NULL)
    return ("Failed while init window\n");
  if ((loop->pix = bunny_new_pixelarray(600, 600)) == NULL)
    return ("Failed while init pixelarray\n");
  return (NULL);
}
