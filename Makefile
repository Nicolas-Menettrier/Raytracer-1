##
## Makefile for wolf in /home/menett_a/Modules/infographie/gfx_wolf3d
## 
## Made by Nicolas Menettrier
## Login   <menett_a@epitech.net>
## 
## Started on  Tue Dec 22 12:13:51 2015 Nicolas Menettrier
## Last update Mon Mar 14 00:13:09 2016 menett_a
##

NAME		=	raytracer1

LIB		=	-L/home/${USER}/.froot/lib/ -llapin 	\
			-L/usr/local/lib 			\
			-lsfml-audio 				\
			-lsfml-graphics 			\
			-lsfml-window 				\
			-lsfml-system 				\
			-lstdc++ -ldl 				\
			-lm

CFLAGS		+=	-Werror -W -Wall -ansi -pedantic -I/home/${USER}/.froot/include/

SRC		= 	cylinder_collision.c	\
			get_info_cylinder.c	\
			sphere_collision.c	\
			get_info_sphere.c	\
			cone_collision.c	\
			plan_collision.c	\
			get_info_light.c	\
			get_info_cone.c		\
			get_info_plan.c		\
			key_response.c		\
			quadrillage.c		\
			find_light.c		\
			init_files.c		\
			my_getnbr.c		\
			raytracer.c		\
			dist_calc.c		\
			load_ini.c		\
			tekpixel.c		\
			put_err.c		\
			vecteur.c		\
			tekray.c		\
			delta.c			\
			main.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) $(LIB) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
