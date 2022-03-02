NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = atoi_.c check_1_2.c get_i.c lsts.c push_swap.c push_swap_fonctions.c ft_split.c push_swap_fonctions_2.c swap_b_a.c swap_b_a_2.c utils_2.c utils_3.c utils_4.c utis_1.c

BONUS = checker.c get_next_line.c get_next_line_utils.c bonus_utils.c bonus_utils2.c lsts.c atoi_.c

OBJS = $(SRC:.c=.o)
OBJBS = $(BONUS:.c=.o)

%.o: %.c lib.h
	$(CC) -c $< -o $@

all: $(NAME) 

bonus: $(NAME) $(BON)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o push_swap

$(BON): $(OBJBS)
	$(CC) $(FLAGS) $(OBJBS) -o checker

clean:
	rm -f $(OBJS) $(OBJBS)

fclean: clean
	rm -f $(OBJS) $(OBJBS)
	rm -f $(NAME)
	rm -f checker

re: fclean all