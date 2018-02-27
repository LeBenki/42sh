/*
** utils_alias.c for PSU_2016_minishell2
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sat Apr 22 00:16:00 2017 Jordan Bonaldi
** Last update	Sun Apr 23 00:07:14 2017 Jordan Bonaldi
*/

# include "project.h"

t_set		*init_list_set()
{
  t_set	*set;

  if (!(set = malloc(sizeof(t_set))))
    exit(84);
  set->var = NULL;
  set->data = NULL;
  set->n = set;
  set->p = set;
  return (set);
}

t_string	*set_exists(char *cmd, t_set *s)
{
  t_set		*tmp;

  tmp = s;
  while (tmp->p != s)
    {
      if (tmp->p->var->equalsIgnoreCase(tmp->p->var, cmd))
	return (tmp->p->data);
      tmp = tmp->p;
    }
  return (NULL);
}

void	add_set(t_string *var, t_string *data, t_set *s)
{
  t_set	*set;

  if (!(set = malloc(sizeof(t_set))))
    exit(84);
  set->var = var;
  set->data = data;
  set->p = s;
  set->n = s->n;
  s->n->p = set;
  s->n = set;
}
