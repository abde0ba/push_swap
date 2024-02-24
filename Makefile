NAME= push_swap

SRCS= mandatory/actions.c mandatory/actions1.c mandatory/actions2.c mandatory/best_move.c \
		mandatory/longest.c mandatory/longest1.c mandatory/main.c mandatory/sort.c \
		mandatory/sort1.c mandatory/utils1.c mandatory/utils2.c mandatory/utils3.c mandatory/utils4.c
OBJS=$(SRCS:.c=.o)

HEADER= mandatory/push_swap.h

CC= cc

CFLAGS= -Wall -Wextra 

RM= rm -rf

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
		$(RM) $(OBJS)
fclean : clean
			$(RM) $(NAME)
re : fclean all