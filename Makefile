NAME		=	bataille_navale
CC			=	gcc -g
RED			=	\033[0;31m
CYAN		=	\033[0;36m
COLOR_OFF	=	\033[0m\0
YELLOW		=	\033[0;33m
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address -pedantic -ansi
SRCS_DIR	=	./
OBJS_DIR	=	objs
SRCS		=	main.c prof/stdprof.c \
				parsing/parsing.c parsing/utils.c \
				game/interactive.c game/position.c game/error.c game/board.c game/free.c game/boats.c \
				game/command.c game/save.c game/check.c game/shoot.c game/file_read.c game/ia.c \


OBJS		=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

all:	$(NAME)

$(NAME): $(OBJS)
			$(CC) $(FLAGS) -o  $@ $^ $(LIB) $(LDFLAGS)

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			@mkdir -p $(@D)
			@printf "$(RED)[**] Compiling $< [**] $(COLOR_OFF)\n"
			@printf "$(COLOR_OFF)\n"
			@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<

clean:
			@rm -rf $(OBJS_DIR)
			@printf "$(YELLOW)Objects Files has been removed.\n"

fclean:		clean
			@rm -rf $(NAME)
			@printf "$(YELLOW)Binary file has been removed.\n"

re:			fclean all

.PHONY:		all clean fclean re
