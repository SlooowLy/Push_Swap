NAME = push_swap

BON = checker

CC = cc

FLAGS = -Wall -Wextra -Werror -g

SRC = atoi_.c check_1_2.c get_i.c lsts.c utils_8.c push_swap.c push_swap_fonctions.c utils_6.c utils_7.c ft_split.c push_swap_fonctions_2.c utils_5.c swap_b_a.c swap_b_a_2.c utils_2.c utils_3.c utils_4.c utis_1.c

BONUS = checker.c get_next_line.c get_next_line_utils.c bonus_utils.c bonus_utils2.c bonus_lsts.c bonus_atoi.c bonus_utils3.c bonus_utils4.c bonus_utils5.c

OBJS = $(SRC:.c=.o)
OBJBS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) push_swap_lib.h
	$(CC) $(FLAGS) $(OBJS) -o $@

bonus:  $(NAME) $(BON)

$(BON): $(OBJBS) push_swap_bonus_lib.h
	$(CC) $(FLAGS) $(OBJBS) -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJBS)

fclean: clean
	rm -f $(OBJS) $(OBJBS) $(NAME) $(BON)

re: fclean all