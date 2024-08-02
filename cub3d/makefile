SRCS	=	app/cub3d.c							\
			game_funcs/file_name_control.c		\
			game_funcs/freee.c					\
			game_funcs/ft_get_read.c			\
			game_funcs/ft_split.c				\
			game_funcs/game_data_creats.c		\
			game_funcs/map_check.c				\
			game_funcs/map_find_and_clone.c		\
			game_funcs/textures_and_colors.c	\

OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	cube3d.a

all: $(NAME)
	ar rc $(NAME) $(OBJS)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
