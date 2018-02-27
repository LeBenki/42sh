/*
** set_command.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Thu Jan 12 13:58:31 2017 Bonaldi Jordan
** Last update	Sun Apr 23 00:08:38 2017 Jordan Bonaldi
*/

#include "project.h"

static int	check_er(char *name)
{
  if (name && name[0] && ((name[0] < 'a' || name[0] > 'z') &&
			  (name[0] < 'A' || name[0] > 'Z') &&
			  (name[0] != '_')))
    {
      write(2, "set: Variable name must begin with a letter.\n", 47);
      return (1);
    }
  if (my_str_isnum(name))
    {
      write(2, "set: Variable name must contain alphanumeric characters.\n",
            57);
      return (1);
    }
  return (0);
}

static void	disp_set(t_shell *shell)
{
  t_set		*set;

  set = shell->set;
  if ((!set || set->n == shell->set) &&
      !my_printf("No alias created\n"))
    return;
  while (set->p != shell->set)
    {
      my_printf("$%s\t->\t%s\n", set->p->var->str,
		set->p->data->str);
      set = set->p;
    }
}

static void	set_var(t_shell *shell, char *s1, char *s2)
{
  if (set_exists(s1, shell->set))
    my_rm_set(&shell->set, s1, &my_strcmp, &my_strlen);
  add_set(init_string(s1), init_string(s2), shell->set);
}

static char	**init_arr(t_shell *shell)
{
  char		**arr;
  int		i;
  int		j;
  int		k;
  int		l;

  if (!(arr = malloc(sizeof(char *) * (arr_len(shell->cmd) * 4))))
    return (NULL);
  i = j = k = l =  -1;
  while (shell->cmd[++i] && (l = j = -1))
    if (!check_equal(shell->cmd[i]) || shell->cmd[i][0] == '=')
      arr[++k] = strdup(shell->cmd[i]);
    else
      {
	if (!(arr[++k] = malloc(strlen(shell->cmd[i]) + 1)))
	  return (NULL);
	while ((shell->cmd[i][++j] != '=') && (arr[k][j] = shell->cmd[i][j])) {}
	arr[k][j] = 0;
	if (!(arr[++k] = malloc(strlen(shell->cmd[i]) + 1)))
	  return (NULL);
	while ((shell->cmd[i][j]) && (arr[k][++l] = shell->cmd[i][j++])) {}
	arr[k][++l] = 0;
      }
  arr[++k] = NULL;
  return (arr);
}

void		builtin_set_var(t_shell *shell)
{
  int		i;
  char		**arr;

  if (!(i = 0) && *shell->cmd && !shell->cmd[1])
    disp_set(shell);
  arr = init_arr(shell);
  while (arr[++i])
    {
      if (check_er(arr[i]) && (shell->done = 1))
	return ;
      if (arr[i + 1] && arr[i + 1][0] == '=' &&
	  !arr[i + 1][1] && arr[i + 2])
	{
	  set_var(shell, arr[i], arr[i + 2]);
	  i += 2;
	}
      else if (arr[i + 1] && arr[i + 1][0] == '='
	       && arr[i + 1][1])
	{
	  set_var(shell, arr[i], &arr[i + 1][1]);
	  i += 1;
	}
      else
	set_var(shell, arr[i], "");
    }
}
