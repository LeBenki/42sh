/*
** cat_and_cut.c for lib in /home/neferett/EPITECH/LIB/lib/string_lib/methods
** 
** Made by Jordan Bonaldi
** Login   <neferett@epitech.eu>
** 
** Started on  Sun Jan 29 22:25:54 2017 Jordan Bonaldi
** Last update Sun Jan 29 23:00:47 2017 Jordan Bonaldi
*/

# include "lib.h"

void			s_cat(t_string *str, char *str2)
{
  str->str = my_strcat(str->str, str2);
  str->length(str);
  str->first = *str->str;
  str->end = str->str[str->size - 1];
}

void			s_rev(t_string *str)
{
  my_revstr(str->str);
  str->first = *str->str;
  str->end = str->str[str->size - 1];
}

void			s_cut(t_string *str, int i)
{
  str->str += i;
  str->length(str);
  str->first = *str->str;
  str->end = str->str[str->size - 1];
}

void			s_reset(t_string *str)
{
  int	i;

  i = -1;
  while (str->str[++i])
    str->str[i] = 0;
  str->first = 0;
  str->end = 0;
}
