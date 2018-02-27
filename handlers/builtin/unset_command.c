/*
** unset_command.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Thu Jan 12 13:54:56 2017 Bonaldi Jordan
** Last update	Mon Mar 13 15:41:49 2017 Jordan Bonaldi
*/

# include "project.h"

boolean		clear_all_list(t_shell *shell)
{
  t_list	*tmp;
  t_list	*l;

  tmp = NULL;
  l = shell->lenv;
  while (l->n != shell->lenv && l->n != NULL)
    {
      tmp = l->n;
      free(l);
      l = tmp;
    }
  shell->lenv = NULL;
  return (true);
}

void	builtin_unset(t_shell *shell)
{
  int	i;

  i = 0;
  if (!my_strcmp(shell->cmd[1], "*") && clear_all_list(shell))
      return;
  while (shell->cmd[++i])
    {
      shell->done = 0;
      if (shell->cmd[i] && get_env(shell->cmd[i], shell->lenv))
	my_rm_list(&shell->lenv, shell->cmd[i], &my_strncmp, &my_strlen);
      else if (shell->cmd[i] &&
	       !get_env(shell->cmd[i], shell->lenv) && (shell->done = 1))
	my_printf("%s: Doesn't exist in the environment\n", shell->cmd[i]);
      else if ((shell->done = 1))
	my_printf("%s: Too few agruments\n", *shell->cmd);
    }
}
