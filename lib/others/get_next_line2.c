/*
** get_next_line.c for get_next_line in /home/Neferett/CPE_2016_getnextline
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Jan  2 10:42:31 2017 Bonaldi Jordan
** Last update Wed Feb  1 13:30:31 2017 Jordan Bonaldi
*/

# include "lib.h"

static char		get_next_char(int fd)
{
  static char	buff[READ_SIZE];
  static int	count;
  static int	i;

  if (!i && (count = -1) &&
      (i = read(fd, buff, READ_SIZE)) <= 0)
    return (0);
  i--;
  return (buff[++count]);
}

char		*get_next_line2(const int fd)
{
  int		i;
  char		a;
  char		*str;

  i = 0;
  if (!(str = malloc(1)) || !(a = get_next_char(fd))
      || (!(*str = 0) && !(str = my_strcatc(str, a))))
    return (NULL);
  while (a != '\n' && a)
    if (++i && (a = get_next_char(fd)) != '\n' && !(str = my_strcatc(str, a)))
      return (NULL);
  str[i] = 0;
  return (str);
}
