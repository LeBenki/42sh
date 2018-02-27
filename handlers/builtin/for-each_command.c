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

static it_t	*n(char *name)
{
  it_t	*it;
  static int	id = -1;

  if (!(it = malloc(sizeof(it_t))))
    exit(84);
  it->it_id = ++id;
  it->name = name;
  return (it);
}

void		execute_cmds(it_t **t, t_string **cmd,
			     t_string *var, t_shell *shell)
{
  t_string	*buff;
  int		i;
  int		j;

  i = -1;
  while (t[++i] && (j = -1))
    {
      if (set_exists(var->str, shell->set))
	my_rm_set(&shell->set, var->str, &my_strcmp, &my_strlen);
      add_set(var, init_string(t[i]->name), shell->set);
      while (cmd[++j])
	{
	  if (if_for_handle(shell, cmd, j))
	    break;
	  if (!strcmp(my_epur_all_str(cmd[j]->str), "endif") ||
	      !strcmp(my_epur_all_str(cmd[j]->str), "else"))
	    break;
	  buff = init_string(cmd[j]->str);
	  if ((!(buff = search_in_command_line(buff, shell)) ||
	       (!look_at_line(buff) &&
	      !my_printf("Invalid null command.\n"))) && (shell->done = 1))
	    continue;
	  good_execution(shell, buff);
	}
    }
}

void		handle_iteration(it_t **t, t_string *var, t_shell *shell, int j)
{
  int		i;
  t_string	**cmd;
  char		*buff;

  i = -1;
  if (nb_of(t[j]->name, ')'))
      t[j]->name[my_strlen(t[j]->name) - 1] = 0;
  t[++j] = NULL;
  if (!(cmd = malloc(sizeof(t_string *) * 1000)))
    exit(84);
  isatty(STDIN_FILENO) ? my_printf("foreach? ") : 1;
  while ((buff = get_input(shell)))
    {
      if (!my_strcmp(buff, "end"))
	break;
      cmd[++i] = init_string(buff);
      isatty(STDIN_FILENO) ? my_printf("foreach? ") : 1;
    }
  cmd[++i] = NULL;
  execute_cmds(t, cmd, var, shell);
}

static int	count_it(t_shell *sh)
{
  int		j;
  int		i;

  i = -1;
  j = -1;
  while (sh->cmd[++i])
    {
      if (*sh->cmd[i] == '(' && sh->cmd[i][1])
        ++j;
      else if (*sh->cmd[i] == '(' && !sh->cmd[i][1])
        continue;
      else if (sh->cmd[i][0] != ')' && ++j) {}
    }
  return (++j);
}

void		builtin_foreach(t_shell *s)
{
  int		j;
  int		i;
  it_t		**it;
  t_string	*var;

  if ((j = -1) && (i = 1) && !(it = malloc(sizeof(it_t *) * count_it(s))))
    exit(84);
  if ((!s->cmd[1] || !s->cmd[2]) && (s->done = 1) &&
      !my_printf("foreach: Too few arguments.\n"))
    return;
  if (s->cmd[1][0] >= 'a' && s->cmd[1][0] <= 'z')
	  var = init_string(s->cmd[1]);
  else if ((s->done = 1) &&
    !my_printf("%s: Variable name must begin with a letter.\n", *s->cmd))
    return;
  while (s->cmd[++i])
    if (*s->cmd[i] == '(' && s->cmd[i][1] && (it[++j] = n(&s->cmd[i][1]))) {}
    else if (*s->cmd[i] == '(' && !s->cmd[i][1])
      continue;
    else if (s->cmd[i][0] != ')' && (it[++j] = n(s->cmd[i]))) {}
  if (!nb_of(s->cmd[i - 1], ')') && (s->done = 1) &&
	  !my_printf("Too many )'s.\n"))
    return;
  handle_iteration(it, var, s, j);
}
