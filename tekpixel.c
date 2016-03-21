/*
** tekpixel.c for tekpixel in /home/nicolas/Modules/gfx_raytracer1/tcore
** 
** Made by menett_a
** Login   <nicolas@epitech.eu>
** 
** Started on  Sun Feb 28 16:22:43 2016 menett_a
** Last update Tue Mar  1 14:17:31 2016 menett_a
*/

#include <lapin.h>

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int	position;

  position = pix->clipable.clip_width * pos->y + pos->x;
  if (pos->x >= 0 && pos->x < pix->clipable.clip_width
      && pos->y >= 0 && pos->y < pix->clipable.clip_height)
    ((int*)pix->pixels)[position] = color->full;
}
