/*
** utils_env.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Jan 11 14:46:25 2017 Bonaldi Jordan
** Last update	Sat Apr 22 21:53:18 2017 Jordan Bonaldi
*/

# include "project.h"

t_list	*init_list()
{
  t_list	*list;

  if (!(list = malloc(sizeof(*list))))
    exit(84);
  list->n = list;
  list->p = list;
  return (list);
}

void		add_env(char *data, t_list *list)
{
  t_list	*e;

  if (!(e = malloc(sizeof(*e))))
    exit(84);
  e->data = data;
  e->p = list;
  e->n = list->n;
  list->n->p = e;
  list->n = e;
}

void		add_end_env(char *data, t_list *list)
{
  t_list	*e;

  if (!(e = malloc(sizeof(*e))))
    exit(84);
  e->data = data;
  e->p = list;
  e->n = list->n;
  list->n->p = e;
  list->n = e;
}

void		show_env(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  if (!tmp || tmp->n == list)
    return;
  while (tmp->p != list)
    {
      my_printf("%s\n", tmp->p->data);
      tmp = tmp->p;
    }
}

t_list		*env_to_list(char **env)
{
  t_list	*list;
  int   i;

  i = -1;
  list = init_list();
  while (env[++i])
    add_env(env[i], list);
  return (list);
}
