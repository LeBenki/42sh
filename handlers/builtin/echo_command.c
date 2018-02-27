/*
** cd_command.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Jan  8 13:53:08 2017 Bonaldi Jordan
** Last update	Sat Apr 22 23:27:50 2017 Jordan Bonaldi
*/

# include "project.h"

static boolean			exec_cmd_if_one(t_shell *sh)
{
  if (sh->cmd[1] && sh->cmd[1][0] && sh->cmd[1][0] == '`')
    {
      sh->cmd[1]++;
      if (sh->cmd[1][my_strlen(sh->cmd[1]) - 1] == '`')
	sh->cmd[1][my_strlen(sh->cmd[1]) - 1] = 0;
      good_execution(sh, init_string(sh->cmd[1]));
      return (true);
    }
  return (false);
}

void			builtin_echo(t_shell *sh)
{
  if (sh->cmd[1] && !my_strcmp(sh->cmd[1], "-n"))
    {
      if (exec_cmd_if_one(sh))
	return;
      my_show_wordtab(sh->cmd + 2, ' ');
    }
  else
    {
      if (exec_cmd_if_one((sh)))
	return;
      my_show_wordtab(sh->cmd + 1, ' ');
      my_printf("\n");
    }
}
