NAME	= philo 

SRCS	= main.c routine.c utils.c \
		  init.c check.c exit.c

OBJS	= ${SRCS:.c=.o}

RM	= rm -f

CC	= gcc

FLAGS	= -Wall -Wextra -Werror -g3

all:		${NAME}

.c.o:
		@${CC} ${FLAGS} -c $< -o ${<:.c=.o} 


${NAME}:	${OBJS} ${LIBFT} ${MLX}
			@echo "\033[34m----Compiling----"
			@${CC} ${FLAGS} -pthread ${OBJS} -o ${NAME} 
			@echo "OK"

clean:
			@echo "\033[31m----Cleaning objects----"
			@${RM} ${OBJS}
			@echo "OK"

fclean:		clean
			@echo "\033[33m----Cleaning all----"
			@${RM} ${NAME}
			@echo "OK"

re:			fclean all

.PHONY:		all clean fclean re


