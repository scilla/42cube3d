SRCS			= main.c random_check.c
#INC				= /usr/include
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBS			= -Lmlx -lmlx -lm -lXext -lX11
#MLX				= libmlx.dylib

NAME			= cube3D.a

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

clean:
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

g:				$(MLX) $(OBJS)
				gcc -g -o ${NAME} ${SRCS} ${LIBS}

.PHONY:			all clean fclean re
