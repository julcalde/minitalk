NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./srcs
INC_DIR = ./include
PRINTF_DIR = $(INC_DIR)/printf
GNL_DIR = $(INC_DIR)/get_next_line

LIBFT_SRCS =	ft_isdigit.c ft_strlen.c ft_atoi.c

PRINTF_SRCS =	ft_charcheck.c ft_numcheck.c ft_printf.c

GNL_SRCS =		get_next_line.c get_next_line_utils.c

SRCS =	$(addprefix $(SRCS_DIR)/, $(LIBFT_SRCS)) \
		$(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS)) \
		$(addprefix $(GNL_DIR)/, $(GNL_SRCS)) \

OBJS =	$(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
