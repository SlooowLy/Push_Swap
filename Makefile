NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = atoi_.c check_1_2.c get_i.c lsts.c push_swap.c push_swap_fonctions.c push_swap_fonctions_2.c swap_b_a.c swap_b_a_2.c utils_2.c utils_3.c utils_4.c utis_1.c

# BONUS = 
OBJS = $(SRC:.c=.o)
# OBJBS = $(BONUS:.c=.o)

%.o: %.c lib.h
	$(CC) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o push_swap

# bonus: $(OBJBS) $(OBJS) lib_bonus.h
# 	$(CC) $(FLAGS) $(OBJBS) -o so_long_bonus
# 	$(CC) $(FLAGS) $(OBJS) -o so_long

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all