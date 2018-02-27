/*
** condition_handler.c for 42sh in /Users/neferett/EPITECH/PSU_2016_42sh/scripting/
**
** Made by Jordan Bonaldi
** Login   <Neferett@epitech.eu@epitech.eu>
**
** Started on  Fri Apr 28 13:30:08 2017 Jordan Bonaldi
** Last update Sat Apr 29 15:07:21 2017 Lucas Benkemoun
*/

# include "project.h"

boolean		try_execute_cond(char *cmd, t_shell *shell)
{
  int		pid;

  if (!(pid = fork()) && (execve(cmd,
		   &cmd, shell->tenv)) < 0)
    exit(84);
  else
    {
      wait(&shell->list->n->delay);
      if (WEXITSTATUS(shell->list->n->delay) == 84 ||
	  !WEXITSTATUS(shell->list->n->delay))
	return (false);
      else if (WEXITSTATUS(shell->list->n->delay) == 1)
	return (true);
    }
  return (false);
}
