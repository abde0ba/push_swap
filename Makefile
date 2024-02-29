NAME= push_swap

SRCS= mandatory/actions.c mandatory/actions1.c mandatory/actions2.c mandatory/best_move.c \
		mandatory/longest.c mandatory/longest1.c mandatory/main.c mandatory/sort.c \
		mandatory/sort1.c mandatory/utils1.c mandatory/utils2.c mandatory/utils3.c mandatory/utils4.c
OBJS=$(SRCS:.c=.o)

HEADER= mandatory/push_swap.h

B_HEADER= bonus/push_swap_bonus.h

BONUS = checker

B_SRCS= bonus/actions_bonus.c bonus/actions1_bonus.c bonus/actions2_bonus.c \
		bonus/main_bonus.c bonus/utils1_bonus.c bonus/utils2_bonus.c bonus/utils3_bonus.c bonus/utils4_bonus.c \
		bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c

B_OBJS=$(B_SRCS:.c=.o)

CC= cc

CFLAGS= -Wall -Wextra -Werror

RM= rm -rf

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS) : %.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(B_OBJS) : %.o: %.c $(B_HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus : $(B_OBJS)
		$(CC) $(CFLAGS) $(B_OBJS) -o $(BONUS)

clean :
		$(RM) $(OBJS) $(B_OBJS)
fclean : clean
			$(RM) $(NAME) $(BONUS)
re : fclean all