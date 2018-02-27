/*
** utils_free.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Jan  8 12:58:14 2017 Bonaldi Jordan
** Last update	Sat Apr 08 19:23:23 2017 Jordan Bonaldi
*/

# include "project.h"

void		*xmalloc(int n)
{
  void		*x;

  if (!(x = malloc(n)))
    exit(84);
  return (x);
}

void		free_tab(t_shell *shell)
{
  int		i;

  i = -1;
  while (shell->cmd[++i])
    free(shell->cmd[i]);
}
