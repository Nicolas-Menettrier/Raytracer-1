/*
** macro.h for macro in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Wed Mar  9 18:46:59 2016 menett_a
** Last update Sat Mar 12 13:56:50 2016 menett_a
*/

#ifndef	MACRO_H_
# define MACRO_H_

# ifndef SPEED
#  define SPEED (5)
# endif /* !SPEED */

# ifndef MAX
#  define MAX(x) (x > 255 ? 255 : (x)) 
# endif /* !MAX */

# ifndef AMBIANT
#  define AMBIANT (0.15)
# endif /* !AMBIANT */

# ifndef PHONG
#  define PHONG (8)
# endif /* !PHONG */

#endif /* !MACRO_H_ */
