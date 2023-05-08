NAME				=	push_swap
BONUS_NAME			=	checker
SRCS_DIR			=	srcs/
OBJS_DIR			=	objs/
B_DIR				=	bonus_ps/
B_OBJS_DIR			=	bonus_objs/
INC					=	-Iinclude/
CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra
FSAN				=	-fsanitize=address -g3
FILES				=	ft_check_valid_utils ft_check_valid my_atoi utils\
						ft_sort_infinity ft_sort ft_sort3 ft_sort5 \
						ft_stack ft_stack2 \
						reverse_rotate rotate swap_push \
						cost execute target_position position
MAN_FILES			=	$(FILES) main
SRCS				=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(MAN_FILES)))
OBJS				=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(MAN_FILES)))

BFILES				=	main check_ops do_ops free_everything result $(FILES)
BONUS_SRCS			=	$(addprefix $(B_DIR), $(addsuffix .c, $(BFILES)))
B_OBJS				=	$(addprefix $(B_OBJS_DIR), $(addsuffix .o, $(BFILES)))
LIBFT_DIR			=	Libft/
LIBFT				=	libft.a

all:
	mkdir -p $(OBJS_DIR)
	make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME) : $(LIBFT_DIR)$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(LIBFT_DIR)$(LIBFT) $(OBJS)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

bonus:
	mkdir -p $(B_OBJS_DIR)
	make $(BONUS_NAME)

$(B_OBJS_DIR)%.o: $(B_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(B_OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BONUS_NAME): $(LIBFT_DIR)$(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(BONUS_NAME) $(LIBFT_DIR)$(LIBFT) $(B_OBJS)

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(B_OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)
	cd $(LIBFT_DIR) && $(MAKE) fclean

re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS_DIR) $(B_DIR) include/