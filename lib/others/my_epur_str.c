/*
** my_epur_str.c for lib in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Jan 18 20:24:26 2017 Bonaldi Jordan
** Last update	Mon Mar 13 16:19:20 2017 Jordan Bonaldi
*/

# include "lib.h"

char		*my_epur_str(char *str)
{
  int	i;

  i = -1;
  if (!str)
    return (NULL);
  if (!*str)
    return (NULL);
  while (str[++i])
    if (str[i] == '\t')
      str[i] = ' ';
  i = my_strlen(str);
  while (str[--i] && str[i] == ' ')
    str[i] = 0;
  return (str);
}
