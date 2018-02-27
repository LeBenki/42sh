/*
** get_next_line.c for get_next_line in /home/Neferett/CPE_2016_getnextline
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Jan  2 10:42:31 2017 Bonaldi Jordan
** Last update Fri May 12 10:22:38 2017 Lucas Benkemoun
*/

# include "lib.h"

char    *my_strcatc(char *dest, char src)
{
  int	len;
  char  *arr;

  if (!(arr = malloc(my_strlen(dest) + 2)))
    return (NULL);
  arr = my_strcpy(arr, dest);
  len = my_strlen(dest);
  arr[len] = src;
  arr[++len] = '\0';
  if (*dest)
    free(dest);
  return (arr);
}

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

char		*get_next_line(const int fd)
{
  int		i;
  char		a;
  char		*str;

  i = 0;
  if (!(a = get_next_char(fd))
      || !(str = my_strcatc("", a)))
    return (NULL);
  while (a != '\n' && a)
    if (++i && (a = get_next_char(fd)) != '\n' && !(str = my_strcatc(str, a)))
      return (NULL);
  str[i] = 0;
  return (str);
}
