# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhemakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/15 17:35:39 by mkhemakh          #+#    #+#              #
#    Updated: 2020/04/19 11:48:12 by mkhemakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
HEADER	= .
SRCS	= 	ft_printf.c\
			convert_di.c\
			convert_c.c\
			convert_p.c\
			convert_s.c\
			convert_u.c\
			convert_x.c\
			parser.c\
			parser_2.c\
			utils.c\
			utils1.c\
			utils2.c\
			
OBJS		= ${SRCS:.c=.o}
OPTION		= -I${HEADER}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rc

.c.o:
			${CC} ${CFLAGS} ${OPTION} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re