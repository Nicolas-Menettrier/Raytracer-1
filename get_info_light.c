/*
** get_info_light.c for get_info_light in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Tue Mar  8 15:53:28 2016 menett_a
** Last update Wed Mar  9 17:26:49 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "proto.h"

char	*get_ini_fields_light(t_bunny_ini *ini, t_info *info, int *nb, int l)
{
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "light", *nb),
		&info->light[l].pos_x) == -1)
    return ("Error while getting info of light's pos_x\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "light", *nb),
		&info->light[l].pos_y) == -1)
    return ("Error while getting info of light's pos_x\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "light", *nb),
		&info->light[l].pos_z) == -1)
    return ("Error while getting info of light's pos_x\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "light", *nb),
		&info->light[l].brt) == -1)
    return ("Error while getting info of light's brightness\n");
  *nb = *nb + 1;
  return (NULL);
}

char	*get_info_light(t_bunny_ini *ini, t_info *info)
{
  char	*str;
  int	l;
  int	nb;

  nb = 1;
  l = 0;
  while (l < info->nb_light)
    {
      if ((str = get_ini_fields_light(ini, info, &nb, l)) != NULL)
	return (str);
      l = l + 1;
    }
  return (NULL);
}
