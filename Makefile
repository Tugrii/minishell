# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/20 19:03:59 by tgeler            #+#    #+#              #
#    Updated: 2026/07/21 04:59:48 by tgeler           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft
LIBFT_ARC = $(LIBFT_DIR)/libft.a

SRCS =	main.c\
		main_utils.c\
		expand.c\
		src/executor/builtins/builtins_controllers.c\
		src/executor/builtins/cd.c\
		src/executor/builtins/cd_utils_1.c\
		src/executor/builtins/cd_utils_2.c\
		src/executor/builtins/echo.c\
		src/executor/builtins/run_builtin.c\
		src/executor/builtins/pwd.c\
		src/executor/builtins/export.c\
		src/executor/builtins/export_utils1.c\
		src/executor/builtins/export_utils2.c\
		src/executor/builtins/export_utils3.c\
		src/executor/builtins/export_utils4.c\
		src/executor/builtins/export_utils5.c\
		src/executor/builtins/export_utils6.c\
		src/executor/builtins/exit.c\
		src/executor/builtins/unset.c\
		src/executor/builtins/env.c\
		src/executor/builtins/print_error_msg.c\
		src/executor/external/run_external.c\
		src/executor/external/path_process/path_creater.c\
		src/executor/external/path_process/path_finder.c\
		src/executor/free_functions/free_all_then_exit.c\
		src/executor/free_functions/free_all_then_exit_utils.c\
		src/executor/free_functions/free_functions_external.c\
		src/executor/executor_error.c\
		src/executor/executor_utils.c\
		src/executor/executor.c\
		src/executor/executor_pipe.c\
		src/executor/executor_check.c\
		src/executor/redirections/print_error_then_exit.c\
		src/executor/redirections/heredoc.c\
		src/executor/redirections/heredoc_utils.c\
		src/executor/redirections/heredoc_create_temp_file.c\
		src/executor/redirections/heredoc_create_temp_file_utils.c\
		src/executor/redirections/redirections.c\
		src/executor/redirections/redirections_utils.c\
		src/lexer/lexer_token.c\
		src/lexer/lexer_utils_1.c\
		src/lexer/lexer_utils_2.c\
		src/lexer/lexer_word.c\
		src/lexer/lexer_word_utils.c\
		src/lexer/lexer.c\
		src/parser/parser_arg.c\
		src/parser/parser_cmd.c\
		src/parser/parser_core.c\
		src/parser/parser_redir.c\
		src/parser/parser_redir_utils.c\
		src/parser/parser.c\
		src/parser/syntax.c\
		src/signals/signals.c\
		src/utils/utils_1.c\
		src/utils/utils_2.c\
		src/utils/utils_3.c\
		src/utils/utils_4.c\
		src/utils/utils_5.c\
		src/utils/utils_6.c\
		src/utils/utils_7.c\
		src/utils/utils_8.c\

OBJS =	$(SRCS:.c=.o)

all:	$(LIBFT_ARC) $(NAME)

$(LIBFT_ARC):
	@$(MAKE) -C $(LIBFT_DIR) all

$(NAME): $(OBJS) $(LIBFT_ARC)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) -lreadline -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
	
.PHONY: all clean fclean re