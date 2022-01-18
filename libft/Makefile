# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrender <yrender@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/31 21:53:40 by yrender           #+#    #+#              #
#    Updated: 2021/10/31 21:53:47 by yrender          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
		ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c\
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
		ft_tolower.c ft_toupper.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_split.c
SRCB	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c
OBJS	= ${SRCS:.c=.o}
OBJB	= ${SRCB:.c=.o}
D_FILES	= ${SRCS:.c=.d} ${SRCB:.c=.d}
NAME	= libft.a
HEAD	= libft.h
CC 		= gcc
AR		= ar rcs
RM 		= rm -f
CFLAGS	= -Wall -Werror -Wextra

${NAME}:	${OBJS} ${HEAD}

			${AR} ${NAME} $?

.c.o:
			${CC} ${CFLAGS} -c $< -o $@ -MD

include 	$(wildcard $(D_FILES))

so:
			$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(SRCB)
			gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJB)

all:		${NAME}

bonus:
			@make OBJS="$(OBJB)" all


clean:
			${RM} ${OBJS} ${OBJB} ${D_FILES}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re bonus
