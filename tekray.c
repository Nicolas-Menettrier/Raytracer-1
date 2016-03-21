/*
** tekray.c for tekray in /home/nicolas/Modules/gfx_raytracer1/tcore
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Sun Feb 28 16:24:19 2016 menett_a
** Last update Sun Mar 13 21:33:58 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"

void	tekray(t_view *screen,
	       double *x,
	       double *y,
	       double *z)
{
  *x = (screen->screen_info[0].x - screen->screen_info[1].x / 2)
    * cos(screen->angle * M_PI / 180) + (600 / (2 * tan(30 / 2)))
    * sin(screen->angle * M_PI / 180);
  *y = (screen->screen_info[0].y - screen->screen_info[1].y / 2);
  *z = (screen->screen_info[0].x - screen->screen_info[1].x / 2)
    * sin(screen->angle * M_PI / 180) - (600 / (2 * tan(30 / 2)))
    * cos(screen->angle * M_PI / 180);
}
