/*
** proto.h for proto in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Tue Mar  1 14:07:36 2016 menett_a
** Last update Sun Mar 13 21:36:28 2016 menett_a
*/

#ifndef	PROTO_H_
# define PROTO_H_

#include "struct.h"

/*
** KEY_RSP functions
*/

void			key_down(t_loop *loop,
			       t_bunny_keysym key);
void			key_up(t_loop *loop,
			       t_bunny_keysym key);
t_bunny_response	key_rsp(t_bunny_event_state event,
				t_bunny_keysym key,
				void *data);
t_bunny_response	main_loop(t_loop *loop);

/*
** INI functions
*/

char	*get_ini_fields_sphe(t_bunny_ini *ini, t_info *info, int *nb, int sphe);
char	*get_ini_fields_cone(t_bunny_ini *ini, t_info *info, int *nb, int cone);
char	*get_ini_fields_plan(t_bunny_ini *ini, t_info *info, int *nb, int plan);
char	*get_ini_fields_cyli(t_bunny_ini *ini, t_info *info, int *nb, int cyli);
char	*get_ini_fields_light(t_bunny_ini *ini, t_info *info, int *nb, int l);
char	*get_info_cylinder(t_bunny_ini *ini, t_info *info);
char	*get_info_sphere(t_bunny_ini *ini, t_info *info);
char	*get_info_light(t_bunny_ini *ini, t_info *info);
char	*get_info_plan(t_bunny_ini *ini, t_info *info);
char	*get_info_cone(t_bunny_ini *ini, t_info *info);
char	*init_view(t_bunny_ini *ini, t_loop *data);
char	*push_info(t_bunny_ini *ini, t_info *info);
char	*get_args(t_bunny_ini *ini, t_info *info);
char	*load_ray(t_loop *info, char *name);
char	*malloc_info(t_info *info);
char	*init_window(t_loop *loop);
void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);
void	check_collision(t_loop *data);
void	tekray(t_view *screen_info,
	       double *x,
	       double *y,
	       double *z);
void	init_values(t_loop *data);
void	init_color(t_pall *color);
void	_init_color(t_loop *data, double *res, double *_res);
void	raytracer(t_loop *data);
void	init_move(t_loop *loop);
void	view_pos(t_loop *loop);
void	my_putcherr(char c);
int	my_getnbr(const char *str, int *nb);
int	find_delta(t_loop *data);
int	put_err(char *str);

/*
** SPHERE functions
*/

void	calcul_pos(t_loop *data, double x, double *dist);
void	calcul_sphere(t_loop *data, t_info *sphe, int i);
void	save_collision(t_loop *data, int i, double x);
void	sphere_collision(t_loop *data, t_info *sphe);
void	sphere_norm(t_loop *data, int i);
void	x_two(t_loop *data, int i);

/*
** PLAN functions
*/

void	plan_collision(t_loop *data, t_info *plan);
void	quadrillage(t_collision *collision);
void	calcul_plan(t_loop *data, int i);
void	plan_normal(t_loop *data, int i);
void	_x_plan(t_loop *data, int i);
void	x_plan(t_loop *data, int i);

/*
** CYLINDER functions
*/

void	calcul_cylinder(t_loop *data, t_info *cyli, int i);
void	cylinder_collision(t_loop *data, t_info *cyli);
void	save_cyli_coll(t_loop *data, int i, double x);
void	cylinder_norm(t_loop *data, int i);
void	cylinder_two(t_loop *data, int i);

/*
** CONE functions
*/

void	calcul_cone(t_loop *data, t_info *cone, int i);
void	cone_collision(t_loop *data, t_info *cone);
void	save_cone(t_loop *data, int i, double x);
void	find_cone(t_loop *data, int i);
void	cone_norm(t_loop *data, int i);

/*
** LIGHT functions
*/

void	_norm(t_loop *data, t_norm *_new, t_ray *new, int *i);
void	phong_light(t_norm *norm, t_loop *data);
void	color_light(t_loop *data);
void	find_light(t_loop *data);

/*
** VECTEUR functions
*/

void	vec_reflexion(t_ray *ray, t_norm *norm, t_ray* new, t_norm *_new);
void	calc_res(t_loop *data, t_norm _new, double *res, double *_res);
void	vec_scalaire(t_ray *ray, t_norm *norm, double *res);
void	vec_normalize(double *x, double *y, double *z);
void	vec_light(t_loop *data, int i);

#endif /* !PROTO_H_ */
