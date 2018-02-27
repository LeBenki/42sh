/*
** env_command.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Jan 11 15:01:51 2017 Bonaldi Jordan
** Last update Tue Jan 17 11:14:01 2017 Bonaldi Jordan
*/

# include "project.h"

void		builtin_env(t_shell *shell)
{
  if (*shell->cmd && !shell->cmd[1])
    show_env(shell->lenv);
  else if (!my_printf("Bad command !\n") &&
	   (shell->done = 1)) {}
}
