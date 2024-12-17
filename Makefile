NAME = minitalk
CLIENT_NAME = client
SERVER_NAME = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
COMMON_SRCS = common.c \
			  ft_atoi.c \
			  ft_strlen.c \
			  ft_isdigit.c \
			  ft_putnbr_fd.c \
			  ft_putchar_fd.c \
			  ft_putendl_fd.c
OBJS_DIR = obj/
CLIENT_OBJ = $(CLIENT_SRCS:.c=.o)
SERVER_OBJ = $(SERVER_SRCS:.c=.o)
COMMON_OBJ = $(COMMON_SRCS:.c=.o)
CLIENT_OBJS = $(addprefix $(OBJS_DIR), $(CLIENT_OBJ))
SERVER_OBJS = $(addprefix $(OBJS_DIR), $(SERVER_OBJ))
COMMON_OBJS = $(addprefix $(OBJS_DIR), $(COMMON_OBJ))
RM = rm -rf

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(COMMON_OBJS)

$(SERVER_NAME) : $(SERVER_OBJS) $(COMMON_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) $(COMMON_OBJS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re : fclean all

.PHONY: all clean fclean re bonus
