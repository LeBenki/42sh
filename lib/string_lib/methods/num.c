/*
** num.c for lib in /home/neferett/EPITECH/LIB/lib/string_lib/methods
**
** Made by Jordan Bonaldi
** Login   <neferett@epitech.eu>
**
** Started on  Sun Jan 29 21:48:30 2017 Jordan Bonaldi
** Last update Sun Jan 29 22:51:17 2017 Jordan Bonaldi
*/

# include "lib.h"

boolean		s_isnum(t_string *str)
{
  return (my_str_isnum(str->str));
}

int		s_toint(t_string *str)
{
  return (my_getnbr(str->str));
}

int		s_tointbase(t_string *str, char *base)
{
  return (my_getnbr_base(str->str, base));
}

void		s_tostring(t_string *str, int i)
{
  str->str = my_strdup(my_itoa(i));
  str->length(str);
  str->first = *str->str;
  str->end = str->str[str->size - 1];
}

int		s_contains(t_string *str, char c)
{
  return (nb_of(str->str, c));
}
