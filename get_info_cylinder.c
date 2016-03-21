/*
** get_info_cylinder.c for get_info_cylinder in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Sat Mar  5 16:27:18 2016 menett_a
** Last update Wed Mar  9 17:28:44 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "proto.h"

char	*get_ini_fields_cyli(t_bunny_ini *ini, t_info *info, int *nb, int cyli)
{
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "cyli", *nb),
		&info->cyli[cyli].pos_y) == -1)
    return ("Error while getting cylinder's pos_y\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "cyli", *nb),
		&info->cyli[cyli].pos_z) == -1)
    return ("Error while getting cylinder's pos_z\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "cyli", *nb),
		&info->cyli[cyli].radius) == -1)
    return ("Error while getting cylinder's radius\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "cyli", *nb),
		&info->cyli[cyli].color) == -1)
    return ("Error while getting cylinder's color\n");
  *nb = *nb + 1;
  return (NULL);
}

char	*get_info_cylinder(t_bunny_ini *ini, t_info *info)
{
  char	*str;
  int	cyli;
  int	nb;

  nb = 1;
  cyli = 0;
  while (cyli < info->nb_cyli)
    {
      if ((str = get_ini_fields_cyli(ini, info, &nb, cyli)) != NULL)
	return (str);
      cyli = cyli + 1;
    }
  return (NULL);
}
