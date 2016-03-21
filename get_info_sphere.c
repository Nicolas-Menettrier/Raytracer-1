/*
** get_info.c for get_info in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Sun Feb 28 22:20:00 2016 menett_a
** Last update Sun Mar 13 20:49:20 2016 menett_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

char	*get_ini_fields_sphe(t_bunny_ini *ini, t_info *info, int *nb, int sphe)
{
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "sphere", *nb),
		&info->sphe[sphe].pos_x) == -1)
    return ("Error while getting info of sphere's pos_x\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "sphere", *nb),
		&info->sphe[sphe].pos_y) == -1)
    return ("Error while getting info of sphere's pos_y\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "sphere", *nb),
		&info->sphe[sphe].pos_z) == -1)
    return ("Error while getting info of sphere's pos_z\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "sphere", *nb),
		&info->sphe[sphe].radius) == -1)
    return ("Error while getting info of sphere's radius\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "sphere", *nb),
		&info->sphe[sphe].color) == -1)
    return ("Error while getting info of sphere's color\n");
  *nb = *nb + 1;
  return (NULL);
}

char	*get_info_sphere(t_bunny_ini *ini, t_info *info)
{
  char	*str;
  int	sphere;
  int	nb;

  nb = 1;
  sphere = 0;
  while (sphere < info->nb_sphere)
    {
      if ((str = get_ini_fields_sphe(ini, info, &nb, sphere)) != NULL)
	return (str);
      sphere = sphere + 1;
    }
  return (NULL);
}
