/*
** utils_str_prompt.c for  in /home/scrountchy/PSU_2016_42sh
**
** Made by Sacha PERIN
** Login   <sacha.perin@epitech.eu>
**
** Started on  Fri May 19 16:45:50 2017 Sacha PERIN
** Last update Fri May 19 16:47:47 2017 Sacha PERIN
*/

#include "project.h"

char    *insert_str(char *str, char *ins, int pos)
{
  char  *new;
  int   o;
  int   i;
  int   j;

  if (!(new = malloc(my_strlen(str) + my_strlen(ins) + 1)))
    return (NULL);
  o = 0;
  i = 0;
  j = 0;
  while (str[i] && i < pos)
    new[j++] = str[i++];
  while (ins[o])
    new[j++] = ins[o++];
  while (str[i])
    new[j++] = str[i++];
  new[j] = 0;
  return (new);
}

char    *delchar_atpos(char *str, int pos)
{
  char  *new;
  int   i;

  i = -1;
  if (!(new = malloc(my_strlen(str))))
    return (NULL);
  while (str[++i] && i < pos)
    new[i] = str[i];
  while (str[i])
    {
      new[i] = str[i + 1];
      i++;
    }
  return (new);
}

char    **add_str(char **arr, char *str, int fst)
{
  char  **new;
  int   i;

  i = -1;
  if (!arr)
    {
      if (!str)
	return (NULL);
      if (!(new = malloc(2 * sizeof(char *))))
	return (NULL);
      new[0] = my_strdup(str);
      new[1] = NULL;
      return (new);
    }
  if (!(new = malloc((tab_len(arr) + 2) * sizeof(char *))))
    return (NULL);
  while (arr[++i])
    new[i] = my_strdup(arr[i]);
  new[i] = my_strdup(str);
  new[i + 1] = NULL;
  if (fst)
    my_freetab(arr);
  return (new);
}

int     str_len(char *str)
{
  int   i;

  i = -1;
  if (!str || !*str)
    return (0);
  while (str[++i]) {}
  return (i);
}

char    *str_cat(char *st1, char *st2)
{
  char  *cat;
  int   i;
  int   j;

  j = 0;
  i = 0;
  if (!st1)
    return (st2);
  if (!(cat = malloc(my_strlen(st1) + my_strlen(st2) + 1)))
    return (NULL);
  while (st1[i])
    cat[j++] = st1[i++];
  i = 0;
  while (st2[i])
    cat[j++] = st2[i++];
  cat[j] = '\0';
  return (cat);
}
