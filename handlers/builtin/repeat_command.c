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

boolean		builtin_repeat(t_shell *sh, t_string *str)
{
  int		i;
  int		to;

  i = -1;
  str->recreate(str, str->str + 7);
  to = str->toInt(str);
  str->recreate(str, str->str + mll(to) + 1);
  while (to > 0 && ++i < to)
     good_execution(sh, init_string(str->str));
  return (true);
}
