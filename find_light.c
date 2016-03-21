/*
** find_light.c for find_light in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Tue Mar  8 16:32:29 2016 menett_a
** Last update Sun Mar 13 23:58:00 2016 menett_a
*/

#include <lapin.h>
#include <math.h>
#include "struct.h"
#include "proto.h"
#include "macro.h"

void		color_light(t_loop *data)
{
  if (data->norm.res <= AMBIANT)
    {
      data->collision._color.argb[0] =
  	MAX(data->pall.color[data->collision.color].argb[0] * AMBIANT);
      data->collision._color.argb[1] =
  	MAX(data->pall.color[data->collision.color].argb[1] * AMBIANT);
      data->collision._color.argb[2] =
  	MAX(data->pall.color[data->collision.color].argb[2] * AMBIANT);
    }
  else if (data->norm.res > 0)
    {
      data->collision._color.argb[0] =
  	MAX(data->pall.color[data->collision.color].argb[0] * data->norm.res);
      data->collision._color.argb[1] =
  	MAX(data->pall.color[data->collision.color].argb[1] * data->norm.res);
      data->collision._color.argb[2] =
  	MAX(data->pall.color[data->collision.color].argb[2] * data->norm.res);
    }
}

void	phong_light(t_norm *norm, t_loop *data)
{
  if (norm->res > 0)
    {
      data->collision._color.argb[0] =
  	MAX(255.0 * norm->res +
	    (double)data->collision._color.argb[0] *
	    (1 - norm->res));
      data->collision._color.argb[1] =
  	MAX(255.0 * norm->res +
	    (double)data->collision._color.argb[1] *
	    (1 - norm->res));
      data->collision._color.argb[2] =
  	MAX(255.0 * norm->res +
	    (double)data->collision._color.argb[2]
	    * (1 - norm->res));
    }
}

void	_init_color(t_loop *data, double *res, double *_res)
{
  data->collision._color.argb[0] = 0;
  data->collision._color.argb[1] = 0;
  data->collision._color.argb[2] = 0;
  data->norm.res = 0;
  data->norm._res = 0;
  data->norm.__res = 0;
  *res = 0;
  *_res = 0;
}

void	_norm(t_loop *data, t_norm *_new, t_ray *new, int *i)
{
  vec_light(data, *i);
  vec_normalize(&data->ray.light_x, &data->ray.light_y,
		&data->ray.light_z);
  vec_scalaire(&data->ray, &data->norm, &data->norm.res);
  vec_reflexion(&data->ray, &data->norm, new, _new);
  if (data->norm.res > 0)
    _new->_res = data->norm.res + _new->_res;
  _new->res =
    new->light_x * data->ray.vec_x
    + new->light_y * data->ray.vec_y
    + new->light_z * data->ray.vec_z;
  if (_new->res > 0)
    _new->__res = _new->__res + pow(_new->res, PHONG);
  *i = *i + 1;
}

void		find_light(t_loop *data)
{
  t_ray		new;
  t_norm	_new;
  int		i;

  i = 0;
  vec_normalize(&data->norm.n_x, &data->norm.n_y,
  		&data->norm.n_z);
  _init_color(data, &_new._res, &_new.__res);
  while (i < data->info.nb_light)
    _norm(data, &_new, &new, &i);
  if (_new._res > 1)
    _new._res = 1;
  if (_new.__res > 1)
    _new.__res = 1;
  data->norm.res = _new._res;
  _new.res = _new.__res;
  color_light(data);
  phong_light(&_new, data);
  data->collision.is_collision = 0;
}
