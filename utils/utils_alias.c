/*
** utils_alias.c for PSU_2016_minishell2
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sat Apr 22 00:16:00 2017 Jordan Bonaldi
** Last update	Sat Apr 22 22:36:12 2017 Jordan Bonaldi
*/

# include "project.h"

t_alias		*init_alias()
{
  t_alias	*alias;

  if (!(alias = malloc(sizeof(t_alias))))
    exit(84);
  alias->n = alias;
  alias->p = alias;
  return (alias);
}

t_string	*alias_exists(char *cmd, t_alias *alias)
{
  t_alias		*tmp;

  tmp = alias;
  while (tmp->p != alias)
    {
      if (tmp->p->alias->equalsIgnoreCase(tmp->p->alias, cmd))
	return (tmp->p->cmd);
      tmp = tmp->p;
    }
  return (NULL);
}

void	add_alias(t_string *cmdalias, t_string *cmd, t_alias *al)
{
  t_alias	*alias;

  if (!(alias = malloc(sizeof(t_alias))))
    exit(84);
  alias->alias = cmdalias;
  alias->cmd = cmd;
  alias->p = al;
  alias->n = al->n;
  al->n->p = alias;
  al->n = alias;
}
