/*
** get_info_cone.c for get_info_cone in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Tue Mar  1 13:52:48 2016 menett_a
** Last update Sun Mar 13 20:47:59 2016 menett_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

char	*get_ini_fields_cone(t_bunny_ini *ini, t_info *info, int *nb, int cone)
{
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "cone", *nb),
		&info->cone[cone].pos_x) == -1)
    return ("Error while getting info of cone's pos_x\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "cone", *nb),
		&info->cone[cone].pos_y) == -1)
    return ("Error while getting info of cone's pos_y\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "cone", *nb),
		&info->cone[cone].pos_z) == -1)
    return ("Error while getting info of cone's pos_z\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "cone", *nb),
		&info->cone[cone].angle) == -1)
    return ("Error while getting info of cone's angle\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "cone", *nb),
		&info->cone[cone].color) == -1)
    return ("Error while getting info of cone's color\n");
  *nb = *nb + 1;
  return (NULL);
}

char	*get_info_cone(t_bunny_ini *ini, t_info *info)
{
  char	*str;
  int	cone;
  int	nb;

  nb = 1;
  cone = 0;
  while (cone < info->nb_cone)
    {
      if ((str = get_ini_fields_cone(ini, info, &nb, cone)) != NULL)
	return (str);
      cone = cone + 1;
    }
  return (NULL);
}
