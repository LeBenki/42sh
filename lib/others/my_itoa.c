/*
** my_itoa.c for my_itoa in /home/Neferett/PSU_2016_my_printf
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Fri Nov 18 11:55:57 2016 Bonaldi Jordan
** Last update Sun Feb 12 12:07:19 2017 Jordan Bonaldi
*/

# include "lib.h"

char		*my_itoa(int nb)
{
  char		*str;
  int		a;
  int		i;

  i = -1;
  a = 0;
  if (!(str = malloc(12)))
    return (NULL);
  *str = 0;
  if (!nb && (str[++i] = '0') && !(str[++i] = 0))
    return (str);
  if (nb < 0 && (a = 1) && (nb *= -1)) {}
  while (nb)
    {
      str[++i] = (nb % 10 > 9) ? (nb % 10 - 10) + 'a' : (nb % 10) + '0';
      nb /= 10;
    }
  str[++i] = a ? '-' : 0;
  str[++i] = 0;
  return (my_revstr(str));
}

void    my_ltoa(long int nb, char *str, int i)
{
  long int   a;

  if (nb >= 10)
    {
      a = nb % 10;
      nb = ((nb - a) / 10);
      my_ltoa(nb, str, i++);
      str[i] = a + 48;
    }
  else
    str[i] = nb + 48;
}

void    my_stoa(short int nb, char *str, int i)
{
  short int   a;

  if (nb >= 10)
    {
      a = nb % 10;
      nb = ((nb - a) / 10);
      my_stoa(nb, str, i++);
      str[i] = a + 48;
    }
  else
    str[i] = nb + 48;
}
