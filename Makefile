# Variables
SERVER = server
CLIENT = client

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

LIBFT = libft
PRINTF = libft/include/printf

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I$(LIBFT) -I$(PRINTF)
LFLAGS = -L$(LIBFT) -lft -L$(PRINTF) -lft

# Rules
all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	@make -C $(LIBFT)
	@gcc $(CFLAGS) $(OBJS_SERVER) $(LFLAGS) -o $(SERVER)
	@echo "Compiled $(SERVER)"

$(CLIENT): $(OBJS_CLIENT)
	@make -C $(LIBFT)
	@gcc $(CFLAGS) $(OBJS_CLIENT) $(LFLAGS) -o $(CLIENT)
	@echo "Compiled $(CLIENT)"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

clean:
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@make -C $(LIBFT) clean
	@echo "Cleaned object files"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@make -C $(LIBFT) fclean
	@echo "Fully cleaned Server, Client and object files"

re: fclean all
