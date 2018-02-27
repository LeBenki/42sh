/*
** init_script.c for 42sh in /home/benki/Epitech/PSU_2016_42sh/scripting/
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Sat Apr 22 01:19:25 2017 Lucas Benkemoun
** Last update Sat Apr 22 01:20:02 2017 Lucas Benkemoun
*/

#include "project.h"

char	*set_value(char *name, char *value)
{
  int	i;
  int	j;
  char	*new;

  new = malloc(strlen(name) + strlen(value) + 2);
  j = i = -1;
  while (name[++i])
    new[i] = name[i];
  new[i++] = '=';
  while (value[++j])
    new[i + j] = value[j];
  new[i + j] = 0;
  return (new);
}

char	**set_variable(char **var, char *name, char *value)
{
  int	i;

  i = -1;
  while (var[++i])
    {
      if (!my_strccmp(var[i], name, '='))
	{
	  free(var[i]);
	  var[i] = set_value(name, value);
	  return (var);
	}
    }
  var = realloc_tab(var);
  free(var[i]);
  var[i] = set_value(name, value);
  var[i + 1] = NULL;
  return (var);
}
