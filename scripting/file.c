/*
** file.c for 42sh in /home/benki/Epitech/PSU_2016_42sh/scripting/
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Sat Apr 22 00:30:06 2017 Lucas Benkemoun
** Last update Sat Apr 29 14:00:35 2017 Lucas Benkemoun
*/

#include "project.h"

char	**read_file(char *name)
{
  char	**arr;
  int	i;
  int	fd;

  i = -1;
  arr = malloc(1024);
  if ((fd = open(name, O_RDONLY)) < 0)
    {
      return (NULL);
    }
  while ((arr[++i] = get_next_line2(fd)));
  return (arr);
}
