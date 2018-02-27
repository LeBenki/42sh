/*
** if_command_sup.c for 42sh in /home/benki/Epitech/PSU_2016_42sh/handlers/
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Mon May 15 17:12:40 2017 Lucas Benkemoun
** Last update Mon May 15 17:16:58 2017 Lucas Benkemoun
*/

#include "project.h"

int	check_equal(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    {
      if (str[i] == '=')
	return (1);
    }
  return (0);
}

int			tab_loop(t_shell *shell, char **arr, int *i, int *j)
{
  if (*j < 3 && ((shell->cmd[*i][0] == '(' || shell->cmd[*i][0] == ')')) &&
      !shell->cmd[*i][1])
    return (1);
  else if (*j < 3 && shell->cmd[*i][0] == '(')
    {
      arr[++(*j)] = &shell->cmd[*i][1];
      return (1);
    }
  if (*j > 0 && (arr[*j][0] == '>' || arr[*j][0] == '<') &&
      shell->cmd[*i][0] == '=' && !shell->cmd[*i][1])
    {
      arr[*j] = my_strcat(arr[*j], shell->cmd[*i]);
      return (1);
    }
  arr[++(*j)] = shell->cmd[*i];
  if (*j < 3 && arr[*j][my_strlen(arr[*j]) - 1] == ')')
    arr[*j][my_strlen(arr[*j]) - 1] = 0;
  return (0);
}
