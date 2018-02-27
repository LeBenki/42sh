/*
** command_handler.c for 42sh in /Users/neferett/EPITECH/PSU_2016_42sh/handlers/
**
** Made by Jordan Bonaldi
** Login   <Neferett@epitech.eu@epitech.eu>
**
** Started on  Sat Apr 22 22:49:09 2017 Jordan Bonaldi
** Last update	Sat Apr 22 23:17:51 2017 Jordan Bonaldi
*/

# include "project.h"

static void	handle_historic_searching(t_shell *shell)
{
  boolean	sucess;
  t_list_cmd	*tmp;
  char		**array;
  int		i;
  int		j;

  if ((tmp = shell->list) && !(i = 0) && (j = -1) && !(sucess = false)) {}
  while (tmp->n != shell->list)
    {
      if (!my_strncmp(*shell->cmd + 1, *tmp->n->cmd,
		      my_strlen(*shell->cmd + 1)))
	{
	  array = malloc(sizeof(tmp->n->cmd) + sizeof(shell->cmd + 1));
	  1 ? array = tmp->n->cmd, j = tab_len(tmp->n->cmd) - 1 : 0;
	  while (shell->cmd[++i])
	    array[++j] = shell->cmd[i];
	  1 ? array[++j] = NULL, shell->cmd = array,
	      my_show_wordtab(shell->cmd, ' '), my_printf("\n") : 0;
	  sucess = true;
	  break;
	}
      tmp = tmp->n;
    }
  if (!sucess && !my_printf("%s: Event not found\n", *shell->cmd + 1) &&
      (shell->done = 1)) {}
}

static void	handle_historic_prev(t_shell *shell)
{
  char		**array;
  int		i;
  int		j;

  if (!(i = 0) && (j = -1)) {}
  array = malloc(sizeof(shell->list->n->cmd) + sizeof(shell->cmd + 1));
  1 ? array = shell->list->n->cmd, j = tab_len(shell->list->n->cmd) - 1 : 0;
  while (shell->cmd[++i])
    array[++j] = shell->cmd[i];
  1 ? array[++j] = NULL, shell->cmd = array,
      my_show_wordtab(shell->cmd, ' '), my_printf("\n") : 0;
}

static	void	check_and_replace(t_string *alias, t_shell *shell)
{
  int		i;
  int		j;
  char		**cmd;
  char		**alias_tab;

  i = -1;
  j = -1;
  alias_tab = alias->towordtab(alias, ' ');
  if (!(cmd = malloc(sizeof(char *) * (tab_len(shell->cmd)
		      + tab_len(alias_tab) + 1))))
    exit(84);
  while (alias_tab[++i])
    cmd[++j] = alias_tab[i];
  i = 0;
  while (shell->cmd[++i])
    cmd[++j] = shell->cmd[i];
  1 ? cmd[++j] = 0, shell->cmd = cmd : 0;
}

void		handle_response(t_shell *shell)
{
  int		i;

  i = -1;
  while (shell->cmd[++i])
    {
      if (i > 0 && nb_of(shell->cmd[i], '`') == 2 && *shell->cmd[i] == '`'
	  && my_strcmp(shell->cmd[0], "echo"))
	{
	  stock_response(shell, init_string(shell->cmd[i]));
	  get_response(shell, i);
	  break;
	}
    }
}

boolean		shell_up(t_shell *shell, t_string *str)
{
  int		i;
  t_string	*alias;

  1 ? i = -1, shell->cmd = str->towordtab(str, ' ') : 0;
  handle_response(shell);
  if (**shell->cmd == '!' && shell->cmd[0][1] && shell->cmd[0][1] != '!')
    handle_historic_searching(shell);
  else if (**shell->cmd == '!' && shell->cmd[0][1] && shell->cmd[0][1] == '!')
    handle_historic_prev(shell);
  is_globbing(shell);
  while (shell->cmd[++i])
    if ((alias = alias_exists(*shell->cmd, shell->alias)))
	check_and_replace(alias, shell);
  return (true);
}
