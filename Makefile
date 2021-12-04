SRCS			= main.c img_utils.c img_utils2.c gen_wall.c math_utils.c parse_map.c placer.c \
				skybox.c collisions.c sound.c key_mouse.c sprites_utils.c \
				sprites_dyn.c minimap.c hud.c expire.c loader.c render_walls.c render_sprites.c \
				render_floor_ceil.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ				= $(SRCS:.c=.o)

RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBFT			= libft.a
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
CC				= gcc
LIBS			= -framework OpenGL -framework AppKit libmlx.dylib libft.a gnl.a -fsanitize=address
MLX				= libmlx.dylib
endif
ifeq ($(UNAME_S),Linux)
CC				= clang
MLX				= libmlx.a
LIBS			= -Lmlx -lm -lXext -lX11 -Llibft $(MLX) $(LIBFT)
endif

NAME			= cube3D.a

%.o:			%.c
				$(CC) -Imlx -Ilibft -Ignl -c -g $< -o $@

all:			$(NAME)


ifeq ($(UNAME_S),Darwin)
$(NAME):		$(MLX) $(LIBFT) $(OBJ)
				$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ) $(LIBS)
$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .
endif
ifeq ($(UNAME_S),Linux)
$(NAME):		$(MLX) $(LIBFT) $(OBJ)
				$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ) $(LIBS)
$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .
endif
$(LIBFT):
				@$(MAKE) -C libft
				@mv libft/$(LIBFT) .

clean:
				@$(MAKE) -C mlx clean
				@$(MAKE) -C libft fclean
				$(RM) $(OBJ) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX) $(LIBFT)

re:				fclean $(NAME)

g:				$(MLX) $(LIBFT) $(OBJS)
				gcc -g -o a.out ${SRCS} ${LIBS} 

.PHONY:			all clean fclean re
