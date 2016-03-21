/*
** load_ini.c for load_ini in /home/nicolas/Modules/gfx_raytracer1/tcore
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Sun Feb 28 16:36:18 2016 menett_a
** Last update Sun Mar 13 23:33:38 2016 menett_a
*/

#include <lapin.h>
#include "struct.h"
#include "proto.h"

char	*push_info(t_bunny_ini *ini, t_info *info)
{
  char	*str;

  if ((str = get_info_sphere(ini, info)) != NULL)
    return (str);
  if ((str = get_info_cone(ini, info)) != NULL)
    return (str);
  if ((str = get_info_cylinder(ini, info)) != NULL)
    return (str);
  if ((str = get_info_plan(ini, info)) != NULL)
    return (str);
  if ((str = get_info_light(ini, info)) != NULL)
    return (str);
  return (NULL);
}

char	*malloc_info(t_info *info)
{
  if (info->nb_sphere > 0)
    if ((info->sphe = bunny_malloc(sizeof(t_sphe) * info->nb_sphere))
	== NULL)
      return ("Malloc failed at line 35 in load.ini.c\n");
  if (info->nb_cone > 0)
    if ((info->cone = bunny_malloc(sizeof(t_cone) * info->nb_cone))
	== NULL)
      return ("Malloc failed at line 39 in load.ini.c\n");
  if (info->nb_plan > 0)
    if ((info->plan = bunny_malloc(sizeof(t_plan) * info->nb_plan))
	== NULL)
      return ("Malloc failed at line 43 in load.ini.c\n");
  if (info->nb_cyli > 0)
    if ((info->cyli = bunny_malloc(sizeof(t_cyli) * info->nb_cyli))
	== NULL)
      return ("Malloc failed at line 47 in load.ini.c\n");
  if (info->nb_light > 0)
    if ((info->light = bunny_malloc(sizeof(t_light) * info->nb_light))
	== NULL)
      return ("Malloc failed at line 51 in load.ini.c\n");
  return (NULL);
}

char	*get_args(t_bunny_ini *ini, t_info *info)
{
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "sphere", 0),
		&info->nb_sphere) == -1)
    return ("Error in .ini.\nNumber of sphere\n");
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "cone", 0),
		&info->nb_cone) == -1)
    return ("Error in .ini.\nNumber of cone\n");
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "plan", 0),
		&info->nb_plan) == -1)
    return ("Error in .ini\nNumber of plan\n");
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "cyli", 0),
		&info->nb_cyli) == -1)
    return ("Error in .ini\nNumber of cylindre\n");
  if (my_getnbr(bunny_ini_get_field(ini, "raytracer1", "light", 0),
		&info->nb_light) == -1)
    return ("Error in .ini\nNumber of lights\n");
  return (NULL);
}

char		*load_ray(t_loop *data, char *name)
{
  char		*str;
  t_bunny_ini	*ini;

  if ((ini = bunny_load_ini(name)) == NULL)
    return ("Error while loading .ini file\n");
  if ((str = get_args(ini, &data->info)) != NULL)
    return (str);
  if ((str = malloc_info(&data->info)) != NULL)
    return (str);
  if ((str = push_info(ini, &data->info)) != NULL)
    return (str);
  if ((str = init_view(ini, data)) != NULL)
    return (str);
  return (NULL);
}
