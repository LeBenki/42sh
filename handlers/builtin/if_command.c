/*
** if_command.c for 42sh in /home/benki/Epitech/PSU_2016_42sh/handlers/builtin/
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Fri May  5 16:49:20 2017 Lucas Benkemoun
** Last update Mon May 15 17:13:22 2017 Lucas Benkemoun
*/

#include "project.h"

static void		test_nb(t_shell *shell, char **arr)
{
  if ((!strcmp(arr[1], ">=")) &&
      (my_getnbr(arr[0]) >= my_getnbr(arr[2])))
    good_execution(shell, init_string(arr[3]));
  if ((!strcmp(arr[1], "<=")) &&
      (my_getnbr(arr[0]) <= my_getnbr(arr[2])))
    good_execution(shell, init_string(arr[3]));
  if (arr[1][0] == '>' && !arr[1][1] &&
      (my_getnbr(arr[0]) > my_getnbr(arr[2])))
    good_execution(shell, init_string(arr[3]));
  if (arr[1][0] == '<' && !arr[1][1] &&
      (my_getnbr(arr[0]) < my_getnbr(arr[2])))
    good_execution(shell, init_string(arr[3]));
}

static void		test_equality(t_shell *shell, char **arr)
{
  boolean		b;

  if (!my_strcmp(arr[1], "=="))
    b = 0;
  else
    b = 1;
  if (!b)
    {
      if (!my_strcmp(arr[0], arr[2]))
	good_execution(shell, init_string(arr[3]));
    }
  else if (my_strcmp(arr[0], arr[2]))
    good_execution(shell, init_string(arr[3]));
}

static int		my_er(char **arr)
{
  int			i;
  int			j;
  int			l;
  int			r;

  l = r = i = -1;
  while (arr[++i])
    {
      j = -1;
      while (arr[i][++j])
	{
	  if (arr[i][j] == '(')
	    l++;
	  else if (arr[i][j] == ')')
	    r++;
	}
    }
  if (l == r)
    return (0);
  (l > r) ? dprintf(2, "Too many ('s.\n") : dprintf(2, "Too many )'s.\n");
  return (1);
}

char			**init_tab(t_shell *shell)
{
  char			**arr;
  int			i;
  int			j;

  i = 0;
  j = -1;
  if (my_er(shell->cmd) && (shell->done = 1))
    return (NULL);
  arr = malloc(sizeof(char *) * (tab_len(shell->cmd) + 1));
  while (shell->cmd[++i])
    if (tab_loop(shell, arr, &i, &j))
      continue;
  arr[++j] = NULL;
  j = 0;
  if (!arr[3])
    {
      if ((shell->idif == 2) && dprintf(2, "if: Empty if.\n") &&
	  (shell->done = 1) && (shell->idif = 1)) {}
      return (NULL);
    }
  else
    while (arr[++j + 3])
      arr[3] = my_strcat(my_strcat(arr[3], " "), arr[3 + j]);
  return (arr);
}

void			builtin_if(t_shell *sh)
{
  char			**arr;

  if (!sh->cmd[1] && dprintf(2, "if: Too few arguments.\n") && (sh->done = 1))
    return ;
  if (!(arr = init_tab(sh)))
    return;
  if (!my_strcmp("then", arr[3]) || !my_strcmp("then", arr[2]))
    {
      builtin_if_sheitan(sh, arr);
      return;
    }
  if (!my_strcmp(arr[1], "==") || !my_strcmp(arr[1], "!="))
    test_equality(sh, arr);
  else if ((arr[1][0] == '<' || arr[1][0] == '>') &&
	   my_str_isnum(arr[0]) && my_str_isnum(arr[2]))
    test_nb(sh, arr);
  else
    {
      1 ? dprintf(2, "if: Expression Syntax.\n"), sh->done = 1 : 0;
      return;
    }
  if ((!arr[3]) && (sh->idif == 2) &&
      dprintf(2, "if: Empty if.\n") && (sh->done = 1) && (sh->idif = 1))
    return;
}
