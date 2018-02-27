/*
** my_rm_all_eq_from_list.c for my_rm_all_eq_from_list in /home/Neferett/CPool_Day11/task08
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Oct 17 13:46:14 2016 Bonaldi Jordan
** Last update Fri Jan 20 12:00:24 2017 Bonaldi Jordan
*/

#include "project.h"

void	my_rm_list(t_list **l, void *data,
		   int (*cmp)(), int (*len)())
{
  Boolean	delete;
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
