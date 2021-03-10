SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

BSRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c answer.c convert_c.c convert_d_i.c convert_d_i2.c convert_p.c convert_percent.c convert_s.c convert_u_xx.c convert_u_xx2.c ft_printf.c get_next_line_utils.c get_next_line.c parsing.c parsing2.c utils.c utils_2.c utils_3.c

HEADER	= includes

OBJS	= ${SRCS:.c=.o}

BOBJS	= ${SRCS:.c=.o} ${BSRCS:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I${HEADER}

all:	${NAME}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

clean:	
	${RM}	${OBJS} ${BOBJS}

fclean:	clean
	${RM} ${NAME}

bonus:	${BOBJS}
	ar rc ${NAME} ${BOBJS}

re:	fclean all