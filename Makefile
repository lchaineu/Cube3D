NAME			= cub3D

SRCS_LIST	   = \
					main.c \
					parse_data.c \
					check_data.c \
					cub_utils.c \
					check_args.c \
					get_map.c \
					get_map2.c \
					get_map_utils.c \
					manage_errors.c \
					destroyers.c \
					settings.c \
					raycasting.c \
					raycasting2.c \
					draw_cub.c \
					get_moves.c \
					move.c \
					point_head.c \
					organise_sprites.c \
					raycast_sprites.c \
					draw_sprites.c \
					save_img.c \
					libft_modified.c \


SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

FOLDER		  = srcs

LIBFT			= Lib19
MLX			 	= minilibx_metal

CC			  = gcc

CFLAGS		  	= -Wall -Wextra -Werror
LFLAGS			= -L Lib19 -lft

METAL_MLX	   	= libmlx.dylib -framework Metal -framework AppKit

RM			  = rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -s -C $(MLX)
				@mv $(MLX)/libmlx.dylib .
				@make bonus -s -C $(LIBFT)
				@$(CC) $(CFLAGS) $(LFLAGS) $(METAL_MLX) $(OBJS) -o $(NAME)

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
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY:			all fclean clean re
