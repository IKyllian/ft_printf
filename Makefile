NAME = libftprintf.a
HEADER = ft_printf.h
SRCS = ft_printf.c ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_itoh.c \
		utils_conversions.c operands_flags.c operands_string_flags.c
OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wextra -Werror -Wall
RM = rm -f

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS) $(HEADER)
	ar cr $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean re all