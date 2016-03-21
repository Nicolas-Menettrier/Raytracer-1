/*
** get_info_plan.c for get_info_plan in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Sat Mar  5 14:08:07 2016 menett_a
** Last update Sun Mar 13 20:48:34 2016 menett_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

char	*get_ini_fields_plan(t_bunny_ini *ini, t_info *info, int *nb, int plan)
{
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "plan", *nb),
		&info->plan[plan].pos_x) == -1)
    return ("Error while getting info of plan pos_x\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "plan", *nb),
		&info->plan[plan].pos_y) == -1)
    return ("Error while getting info of plan pos_y\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "plan", *nb),
		&info->plan[plan].pos_z) == -1)
    return ("Error while getting info of plan pos_z\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "plan", *nb),
		&info->plan[plan].x) == -1)
    return ("Error while getting info of plan x\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "plan", *nb),
		&info->plan[plan].y) == -1)
    return ("Error while getting info of plan y\n");
  *nb = *nb + 1;
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "plan", *nb),
		&info->plan[plan].z) == -1)
    return ("Error while getting info of plan z\n");
  *nb = *nb + 1;
  return (NULL);
}

char	*get_info_plan(t_bunny_ini *ini, t_info *info)
{
  char	*str;
  int	plan;
  int	nb;

  nb = 1;
  plan = 0;
  while (plan < info->nb_plan)
    {
      if ((str = get_ini_fields_plan(ini, info, &nb, plan)) != NULL)
	return (str);
      if (my_getnbr(bunny_ini_get_field(ini,"raytracer1", "plan", nb),
		    &info->plan[plan].color) == -1)
	return ("Error while getting info of plan color\n");
      nb = nb + 1;
      plan = plan + 1;
    }
  return (NULL);
}
