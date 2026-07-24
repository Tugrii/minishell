/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:44:12 by tgeler            #+#    #+#             */
/*   Updated: 2026/07/18 23:39:19 by tgeler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Libft/libft.h"
#include "../../../include/minishell.h"

#define F_OK 0
#define X_OK 1
#define W_OK 2
#define R_OK 4

typedef struct arg_state
{
	int					state;
	struct arg_state	*next;
}	t_arg_stt;

typedef struct export
{
	t_arg_stt	*state_list;
	t_shell		*shell;

}	t_export;

typedef struct cd
{
	char	*target;
	char	*current_pwd;
	char	*old_pwd;
}	t_cd;

int		check_contain_flag(t_cmd *command);
int		is_builtin_which(char *command);
void	run_echo_with_flag(t_cmd *command_list, t_shell *shell);
void	run_echo_without_flag(t_cmd *command_list, t_shell *shell);
void	run_builtin(t_cmd *command_list, t_shell *shell,
			int builtin_nbr, int is_child);
void	run_cd(t_cmd *command_list, t_shell *shell);
void	run_pwd(t_shell *shell);
void	run_export(t_cmd *command_list, t_shell *shell);
void	run_env(t_shell *shell, t_cmd *command_list);
int		print_error_msg_export(char *msg, int mode);
void	create_state_list_and_fill(t_arg_stt **state, t_cmd *command_list);
int		sign_and_print_err(t_export *export, char *msg, int err_no, int arg_no);
void	run_export_utils(t_cmd *command_list, t_shell *shell, t_arg_stt *arg);
int		fatal_error(char *msg);
int		is_new_key(char *cmd, int key_len, t_shell *shell);
void	change_the_value_of_key(t_shell *shell, char *cmd, int key_len);
void	fill_it(char *src, char *dst, int len);
void	free_them(char **p_1, char **p_2, t_env **p_3, char **p_4);
char	*get_key(char *cmd, int key_len);
int		is_new_key(char *cmd, int key_len, t_shell *shell);
void	print_export(t_shell *shell);
t_env	*clone_the_env(t_env *original, t_env *cloned_env);
int		ft_strlen_specified(char *str);
void	sort_env_list(t_env **env);
void	free_the_env(t_env **env);
void	run_unset(t_cmd *command_list, t_shell *shell);
int		print_error_msg_unset(char *msg, int mode);
int		get_bigger_string_len(char *str1, char *str2);
void	free_state_list(t_arg_stt **list);
void	print_error_msg_exit(char *msg, int mode);
void	run_exit(t_cmd *command_list, t_shell *shell);
void	run_builtin_utils_main(t_cmd *command_list, t_shell *shell,
			int builtin_nbr, int flag);
void	run_builtin_utils_child(t_cmd *command_list, t_shell *shell,
			int builtin_nbr, int flag);
void	change_directory(t_shell *shell, char *old_pwd, char **current_pwd);
char	*set_home(t_shell *shell, t_cmd *command_list, int *alloc_flag);
int		check_getcwd_set_env(char **current_pwd, char *old_pwd,
			t_shell *shell, int mode);
void	flag_triggered(int flag, char *target, char *old_pwd);
void	oldpwd_error(t_shell *shell, char *old_pwd);
char	*set_old_pwd_print_pwd(t_shell *shell, int *flag);
int		parse_exit_number(char *str, long long *result, int i, int sign);
