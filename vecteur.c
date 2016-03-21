/*
** vecteur.c for vecteur in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Wed Mar  9 20:08:38 2016 menett_a
** Last update Sun Mar 13 23:53:48 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "proto.h"

void	vec_light(t_loop *data, int i)
{
  data->ray.light_x = data->info.light[i].pos_x - data->collision.pos_x;
  data->ray.light_y = data->info.light[i].pos_y - data->collision.pos_y;
  data->ray.light_z = data->info.light[i].pos_z - data->collision.pos_z;
}

void		vec_normalize(double *x, double *y, double *z)
{
  double	coef;

  coef = 0;
  coef = sqrt((*x * *x) + (*y * *y) + (*z * *z));
  *x = *x / coef;
  *y = *y / coef;
  *z = *z / coef;
}

void	vec_scalaire(t_ray *ray, t_norm *norm, double *res)
{
  *res =
    norm->n_x * ray->light_x +
    norm->n_y * ray->light_y +
    norm->n_z * ray->light_z;
}

void	vec_reflexion(t_ray *ray, t_norm *norm,
		      t_ray* new, t_norm *_new)
{
  _new->n_x = norm->n_x;
  _new->n_y = norm->n_y;
  _new->n_z = norm->n_z;
  new->light_x = ray->light_x - 2 * norm->res * norm->n_x;
  new->light_y = ray->light_y - 2 * norm->res * norm->n_y;
  new->light_z = ray->light_z - 2 * norm->res * norm->n_z;
}
