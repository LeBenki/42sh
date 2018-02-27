/*
** util.c for 42sh in /home/benki/Epitech/PSU_2016_42sh/scripting/
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Fri Apr 21 23:40:10 2017 Lucas Benkemoun
** Last update Sat Apr 22 01:04:05 2017 Lucas Benkemoun
*/

#include "project.h"

void	my_freetab(char **arr)
{
  int	i;

  i = -1;
  if (arr)
    {
      while (arr[++i])
	free(arr[i]);
      free(arr);
    }
}

char    **realloc_tab(char **ae)
{
  char  **env;
  int   i;

  i = 0;
  while (ae[i])
    i++;
  i++;
  env = malloc(sizeof(char*) * (i + 2));
  i = 0;
  while (ae[i])
    {
      env[i] = my_strdup(ae[i]);
      i++;
    }
  env[i] = NULL;
  my_freetab(ae);
  return (env);
}

char    **cpy_tab(char **ae)
{
  char  **env;
  int   i;

  env = malloc(sizeof(char*) * (arr_len(ae) + 2));
  i = 0;
  while (ae[i])
    {
      env[i] = my_strdup(ae[i]);
      i++;
    }
  env[i] = NULL;
  return (env);
}

int     my_arrlen(char **arr)
{
  int   i;

  i = 0;
  while (arr[i])
    i++;
  return (i);
}

int     my_strccmp(char *s1, char *s2, char c)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (*(s2 + j) && *(s1 + i) && *(s1 + i) != c)
    {
      if (*(s1 + i) != *(s2 + j))
        return (1);
      i++;
      j++;
    }
  if (i == j && s1[i] == c && !s2[j])
    return (0);
  else
    return (1);
}
