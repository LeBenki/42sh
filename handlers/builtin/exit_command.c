/*
** exit_command.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Jan  8 13:55:31 2017 Bonaldi Jordan
** Last update	Sat Apr 08 18:49:36 2017 Jordan Bonaldi
*/

# include "project.h"

void		builtin_exit(t_shell *shell)
{
  if (!shell->cmd[1])
    {
      if (isatty(STDIN_FILENO))
	my_printf("exit\n");
      exit(shell->done == -1 ? shell->ret : shell->done == 1 ? 1 :
          shell->list->n->delay);
    }
  else if ((shell->done = 1))
    my_printf("%s: Expression Syntax.\n", *shell->cmd);
}
