/*
** main.c for main in /home/nicolas/Modules/gfx_raytracer1/tcore
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Sun Feb 28 16:38:20 2016 menett_a
** Last update Sun Mar 13 23:49:06 2016 menett_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

t_bunny_response	main_loop(t_loop *loop)
{
  view_pos(loop);
  init_color(&loop->pall);
  raytracer(loop);
  bunny_blit(&loop->win->buffer, &loop->pix->clipable, NULL);
  bunny_display(loop->win);
  return (GO_ON);
}

int		main(int argc, char **argv)
{
  t_loop	loop;
  char		*str;

  if (argc < 2)
    return (1);
  if ((str = load_ray(&loop, argv[1])) != NULL)
    return (put_err(str));
  if ((str = init_window(&loop)) != NULL)
    return (put_err(str));
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  bunny_set_key_response(key_rsp);
  init_move(&loop);
  bunny_loop(loop.win, 60, &loop);
  bunny_delete_clipable(&loop.pix->clipable);
  bunny_stop(loop.win);
  return (0);
}
