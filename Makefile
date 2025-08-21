NAME = philo

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = srcs/main.c\
	srcs/parsing.c\
	srcs/utils.c\
	srcs/errors_n_frees.c

$(NAME) :
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all

