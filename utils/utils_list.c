/*
** utils_list.c for PSU_2016_minishell2
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Mon Mar 13 15:43:47 2017 Jordan Bonaldi
** Last update	Sat Apr 22 22:37:40 2017 Jordan Bonaldi
*/

# include "project.h"

void	my_rm_list(t_list **l, void *data,
		   int (*cmp)(), int (*len)())
{
  boolean	delete;
  t_list	*list;
  t_list	*tmp;

  if ((list = *l) && !(delete = false) && (tmp = list->n)) {}
  while (tmp != *l)
    if (tmp->data && !cmp(tmp->data, data, len(data)) &&
	tmp->data[len(data)] == '=' && (delete = true) && (list->n = tmp->n))
      {
	free(tmp);
	if ((tmp = list->n) && (tmp->p = list)) {}
      }
    else if ((list = tmp) && (tmp = tmp->n)) {}
  if (delete)
    return;
  if ((*l = list) && (tmp = list->n)) {}
  while (tmp != *l)
    if (tmp->data && !cmp(tmp->data, data, len(data)) &&
	tmp->data[len(data)] == '=' && (list->n = tmp->n))
      {
	free(tmp);
	if ((tmp = list->n) && (tmp->p = list)) {}
      }
    else if ((list = tmp) && (tmp = tmp->n)) {}
}

void	my_rm_alias(t_alias **l, void *data,
		   int (*cmp)(), int (*len)())
{
  boolean	delete;
  t_alias	*list;
  t_alias	*tmp;

  if ((list = *l) && !(delete = false) && (tmp = list->n)) {}
  while (tmp != *l)
    if (tmp->alias && !cmp(tmp->alias->str, data, len(data))
	&& (delete = true) && (list->n = tmp->n))
    {
	  free(tmp);
	if ((tmp = list->n) && (tmp->p = list)) {}
    }
    else if ((list = tmp) && (tmp = tmp->n)) {}
  if (delete)
    return;
  if ((*l = list) && (tmp = list->n)) {}
  while (tmp != *l)
    if (tmp->alias && !cmp(tmp->alias->str, data, len(data))
	&& (list->n = tmp->n))
    {
	  free(tmp);
	if ((tmp = list->n) && (tmp->p = list)) {}
    }
    else if ((list = tmp) && (tmp = tmp->n)) {}
}

void	my_rm_set(t_set **l, void *data,
		   int (*cmp)(), int (*len)())
{
  boolean	delete;
  t_set	*list;
  t_set	*tmp;

  if ((list = *l) && !(delete = false) && (tmp = list->n)) {}
  while (tmp != *l)
    if (tmp->var && !cmp(tmp->var->str, data, len(data))
	&& (delete = true) && (list->n = tmp->n))
    {
	  free(tmp);
	if ((tmp = list->n) && (tmp->p = list)) {}
    }
    else if ((list = tmp) && (tmp = tmp->n)) {}
  	if (delete)
    	return;
  if ((*l = list) && (tmp = list->n)) {}
  while (tmp != *l)
    if (tmp->var && !cmp(tmp->var->str, data, len(data))
	&& (list->n = tmp->n))
    {
	  free(tmp);
	if ((tmp = list->n) && (tmp->p = list)) {}
    }
    else if ((list = tmp) && (tmp = tmp->n)) {}
}
