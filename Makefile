FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

NAME = push_swap

BONUS = checker

SRC = ft_itoa.c ft_atoi.c push.c check_errors.c utils.c operations.c utils1.c utils2.c utils3.c utils4.c updates.c updates1.c

SRC_B = ./my_checker/check_errors.c ./my_checker/ft_atoi.c ./my_checker/ft_itoa.c ./my_checker/my_checker.c ./my_checker/my_checker2.c ./my_checker/my_checker3.c ./my_checker/operations1.c ./my_checker/operations2.c ./my_checker/operations3.c ./my_checker/utils1.c ./my_checker/utils2.c ./my_checker/utils3.c ./my_checker/get_next_line/get_next_line.c ./my_checker/get_next_line/get_next_line_utils.c

all : $(NAME)

$(NAME) : $(NAMELIB)
	gcc $(FLAGS) $(SRC) -o $(NAME)

bonus :
	gcc $(FLAGS) $(SRC_B) -o $(BONUS)

clean:
	rm -f $(NAME) $(BONUS)

fclean :
	rm -f $(NAME)
	rm -f $(BONUS)

re : fclean all