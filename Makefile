NAME			= cube_3d

SRCS_LIST	   = \
					cub.c \
					parsing.c \
					utils.c \
					checks.c \

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

FOLDER		  = srcs

LIBFT			= Libft
MLX			 	= minilibx_metal

CC			  = gcc

CFLAGS		  	= -Wall -Wextra -Werror
LFLAGS			= -L Libft -lft

METAL_MLX	   	= libmlx.dylib -framework Metal -framework AppKit

RM			  = rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -s -C $(MLX)
				@mv $(MLX)/libmlx.dylib .
				@$(CC) $(CFLAGS) $(METAL_MLX) $(OBJS) -o $(NAME)

%.o: %.c
				@$(CC) $(CFLAGS) -o $@ -c $<

clean:
				@$(RM) $(OBJS)
				@make clean -C $(MLX)
				@make clean -C $(LIBFT)


fclean:		 clean
				@$(RM) $(NAME)
				@$(RM) libmlx.dylib
				@$(RM) img.bmp
				@make fclean -C $ (LIBFT)

re:			 fclean all
