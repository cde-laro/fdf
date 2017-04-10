NAME = libft.a
SRC_DIR = .
OBJ_DIR = objs
FLAGS = -Wall -Wextra -Werror -g
CC = gcc $(FLAGS) $(INC)
COLOR = \0033[1;35m

SRC_FT = ft_atoi \
		 ft_isalnum \
		 ft_bzero \
		 ft_isalpha \
		 ft_isascii \
		 ft_isdigit \
		 ft_isprint \
		 ft_itoa \
		 ft_memalloc \
		 ft_memccpy \
		 ft_memchr \
		 ft_memcmp \
		 ft_memcpy \
		 ft_memdel \
		 ft_memmove \
		 ft_memset \
		 ft_putchar \
		 ft_putchar_fd \
		 ft_putendl \
		 ft_putendl_fd \
		 ft_putnbr \
		 ft_putstr \
		 ft_strcat \
		 ft_putnbr_fd \
		 ft_putstr_fd \
		 ft_strchr \
		 ft_strclr \
		 ft_strcmp \
		 ft_strcpy \
		 ft_strdel \
		 ft_strdup \
		 ft_strequ \
		 ft_striter \
		 ft_striteri \
		 ft_strjoin \
		 ft_strlcat \
		 ft_strlen \
		 ft_strmap \
		 ft_strmapi \
		 ft_strncat \
		 ft_strncmp \
		 ft_strncpy \
		 ft_strnequ \
		 ft_strnew \
		 ft_strnstr \
		 ft_strrchr \
		 ft_strsplit \
		 ft_strstr \
		 ft_strsub \
		 ft_strtrim \
		 ft_tolower \
		 ft_toupper \
		 ft_lstadd \
		 ft_lstnew \
		 ft_lstdel \
		 ft_lstiter \
		 ft_lstdelone \
		 ft_lstmap \
		 ft_countwords \
		 ft_puttab \
		 ft_puttab_fd \
		 ft_countchar \
		 ft_countelem \
		 ft_strsplit_to_int \
		 ft_strtolower \
		 ft_strtoupper

OBJ = $(SRC_FT:%=$(OBJ_DIR)/%.o)
SRC = $(SRC_FT:%=%.c)

all: $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\t\0033[1;30m[All OK]\0033[0;37m"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: %.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJ_DIR) $(SRC)
	@$(MAKE) $(OBJ)
	@echo "$(COLOR)Objects of $(NAME)\t\0033[0;32m[Created]\0033[0;37m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\t\0033[0;32m[Created]\0033[0;37m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR)Objects of $(NAME)\t\0033[0;31m[Deleted]\0033[0;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\t\0033[0;31m[Deleted]\0033[0;37m"

re: fclean all

.PHONY: all clean fclean re
