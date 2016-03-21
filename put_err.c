/*
** put_err.c for put_err in /home/nicolas/Modules/gfx_raytracer1
** 
** Made by menett_a
** Login   <menett_a@epitech.eu>
** 
** Started on  Tue Mar  1 14:47:03 2016 menett_a
** Last update Tue Mar  1 14:48:57 2016 menett_a
*/

#include <unistd.h>

void	my_putcherr(char c)
{
  write(2, &c, 1);
}

int	put_err(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putcherr(str[i]);
      i = i + 1;
    }
  return (1);
}
