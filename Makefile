NAME		=	bataille_navale
CC			=	gcc -g
RED			=	\033[0;31m
CYAN		=	\033[0;36m
COLOR_OFF	=	\033[0m\0
YELLOW		=	\033[0;33m
FLAGS		=	-Wall -Wextra -Werror
SRCS_DIR	=	./
OBJS_DIR	=	objs
SRCS		=
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)/%.o)

all:	$(NAME)

$(NAME):	$(LFT) $(OBJS)
			$(CC) $(FLAGS) -o  $@ $^ $(LIB) $(LDFLAGS)

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			@mkdir -p $(@D)
			@echo "$(RED)[**] Compiling $< [**] $(COLOR_OFF)"
#			@echo "$(COLOR_OFF)"
			@$(CC) $(FLAGS) $(HEADER) -o $@ -c $<

clean:
			@rm -rf $(OBJS_DIR)
			@echo "$(YELLOW)Objects Files has been removed."

fclean:		clean
			@rm -rf $(NAME)
			@echo "$(YELLOW)Binary file has been removed."

re:			fclean all

.PHONY:		all clean fclean r