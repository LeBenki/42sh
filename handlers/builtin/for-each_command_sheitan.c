/*
** for-each_command_sheitan.c for 42sh in /home/benki/Images/PSU_2016_42sh
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Thu May 18 16:22:48 2017 Lucas Benkemoun
** Last update Thu May 18 16:24:47 2017 Lucas Benkemoun
*/

#include "project.h"

int             test_if_foreach(char *str)
{
  char          *s1;
  char          *s2;
  char          *sep;
  char          **arr;

  arr = my_str_to_wordtab(str, ' ');
  if (arr[1] && arr[1][1])
    {
      s1 = &arr[1][1];
      sep = arr[2];
      s2 = arr[3];
    }
  else
    {
      s1 = arr[2];
      sep = arr[3];
      s2 = arr[3];
    }
  if (s2[strlen(s2) - 1] == ')')
    s2[strlen(s2) - 1] = 0;
  if (sep[0] == '=' && !strcmp(s1, s2))
    return (0);
  else if (sep[0] == '!' && strcmp(s1, s2))
    return (0);
  return (1);
}

int             if_for_handle(t_shell *shell, t_string **cmd, int j)
{
  t_string      *buff;

  if (!strncmp(my_epur_all_str(cmd[j]->str), "if", 2))
    {
      buff = search_in_command_line(init_string(cmd[j]->str), shell);
      if (!(test_if_foreach(buff->str)))
	{
	  buff = search_in_command_line(init_string(cmd[j + 1]->str), shell);
	  good_execution(shell, buff);
	}
      else
	{
	  buff = search_in_command_line(init_string(cmd[j + 3]->str), shell);
	  good_execution(shell, buff);
	}
      return (1);
    }
  return (0);
}
