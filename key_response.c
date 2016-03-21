/*
** key_response.c for key_response in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Tue Mar  1 21:53:33 2016 menett_a
** Last update Sun Mar 13 23:52:39 2016 menett_a
*/

#include <lapin.h>
#include "macro.h"
#include "struct.h"

void	init_move(t_loop *loop)
{
  loop->move.move_z = 0;
  loop->move._move_z = 0;
  loop->move.move_y = 0;
  loop->move._move_y = 0;
  loop->move.move_x = 0;
  loop->move._move_x = 0;
  loop->move._angle = 0;
  loop->move.angle = 0;
}

void	view_pos(t_loop *loop)
{
  if (loop->move.move_z == 1)
    loop->pos_z = loop->pos_z + SPEED;
  if (loop->move._move_z == -1)
    loop->pos_z = loop->pos_z - SPEED;
  if (loop->move.move_y == 1)
    loop->pos_y = loop->pos_y + SPEED;
  if (loop->move._move_y == -1)
    loop->pos_y = loop->pos_y - SPEED;
  if (loop->move.move_x == 1)
    loop->pos_x = loop->pos_x + SPEED;
  if (loop->move._move_x == -1)
    loop->pos_x = loop->pos_x - SPEED;
  if (loop->move.angle == 1)
    loop->info.screen_info.angle = loop->info.screen_info.angle - 2;
  if (loop->move._angle == -1)
    loop->info.screen_info.angle = loop->info.screen_info.angle + 2;
}

void	key_down(t_loop *loop, t_bunny_keysym key)
{
  if (key == BKS_Z)
    loop->move.move_z = 1;
  if (key == BKS_S)
    loop->move._move_z = -1;
  if (key == BKS_D)
    loop->move.move_x = 1;
  if (key == BKS_Q)
    loop->move._move_x = -1;
  if (key == BKS_A)
    loop->move._move_y = -1;
  if (key == BKS_E)
    loop->move.move_y = 1;
  if (key == BKS_J)
    loop->move._angle = -1;
  if (key == BKS_L)
    loop->move.angle = 1;
}

void	key_up(t_loop *loop, t_bunny_keysym key)
{
  if (key == BKS_Z)
    loop->move.move_z = 0;
  if (key == BKS_S)
    loop->move._move_z = 0;
  if (key == BKS_D)
    loop->move.move_x = 0;
  if (key == BKS_Q)
    loop->move._move_x = 0;
  if (key == BKS_A)
    loop->move._move_y = 0;
  if (key == BKS_E)
    loop->move.move_y = 0;
  if (key == BKS_J)
    loop->move._angle = 0;
  if (key == BKS_L)
    loop->move.angle = 0;
}

t_bunny_response	key_rsp(t_bunny_event_state event,
				t_bunny_keysym key,
				void *data)
{
  t_loop		*loop;

  loop = data;
  if (event == GO_UP && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (event == GO_DOWN)
    key_down(loop, key);
  if (event == GO_UP)
    key_up(loop, key);
  return (GO_ON);
}
