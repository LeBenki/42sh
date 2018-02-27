/*
** set_command.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Thu Jan 12 13:58:31 2017 Bonaldi Jordan
** Last update	Sun Apr 09 22:16:29 2017 Jordan Bonaldi
*/
# include "project.h"

static boolean	can_continue(char *str)
{
  while (*str)
    {
      if (!(*str >= 'a' && *str <= 'z') &&
	       !(*str >= 'A' && *str <= 'Z') && !(*str == '_'))
	        return (false);
      str++;
    }
  return (true);
}

void		builtin_set(t_shell *shell)
{
  char		*add;

  if (shell->cmd[1] && *shell->cmd[1] &&
		((*shell->cmd[1] >= 'a' && *shell->cmd[1] <= 'z') ||
			(*shell->cmd[1] >= 'A' && *shell->cmd[1] <= 'Z'))
      && can_continue(shell->cmd[1]))
    {
      if (get_env(shell->cmd[1], shell->lenv))
	my_rm_list(&shell->lenv, shell->cmd[1], &my_strncmp, &my_strlen);
      add = my_strcat(shell->cmd[1], "=");
      if (shell->cmd[2])
	add = my_strcat(add, shell->cmd[2]);
      add_end_env(add, shell->lenv);
    }
  else if (shell->cmd[1] && *shell->cmd[1] &&
	   !((*shell->cmd[1] >= 'a' && *shell->cmd[1] <= 'z') ||
	     (*shell->cmd[1] >= 'A' && *shell->cmd[1] <= 'Z'))
	   && (shell->done = 1))
    my_printf("setenv: Variable name must begin with a letter.\n");
  else if (shell->cmd[1] && !can_continue(shell->cmd[1]) &&
      (shell->done = 1))
    my_printf("setenv: Variable name must contain alphanumeric characters.\n");
  else
    show_env(shell->lenv);
}
