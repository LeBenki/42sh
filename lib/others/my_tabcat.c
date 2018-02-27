/*
** my_tabcat.c for 42sh in /home/benki/Epitech/test/lib/others/
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Thu Apr 27 17:07:05 2017 Lucas Benkemoun
** Last update Mon May 15 17:41:46 2017 Lucas Benkemoun
*/

#include "project.h"

char		**my_tabcat(char **t1, char **t2, int ind)
{
  char		**new;
  int		i;
  int		len;
  int		j;

  i = j = -1;
  len = tab_len(t1) + tab_len(t2) + 1;
  if (!(new = malloc(sizeof(char *) * len)))
    return (NULL);
  while (++i < ind)
    new[i] = t1[i];
  while (t2[++j])
    new[i + j] = t2[j];
  while (t1[++i])
    new[i + j - 1] = t1[i];
  new[i + j - 1] = NULL;
  return (new);
}
