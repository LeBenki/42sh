/*
** capitalize.c for lib in /home/neferett/EPITECH/LIB/lib/string_lib/methods
** 
** Made by Jordan Bonaldi
** Login   <neferett@epitech.eu>
** 
** Started on  Sun Jan 29 21:35:47 2017 Jordan Bonaldi
** Last update Mon Jan 30 12:03:48 2017 Jordan Bonaldi
*/

# include "lib.h"

void		s_capitalizing(t_string *str)
{
  my_strupcase(str->str);
}

boolean		s_islower(t_string *str)
{
  return (my_str_islower(str->str));
}

boolean		s_isupper(t_string *str)
{
  return (my_str_isupper(str->str));
}

boolean		s_isalpha(t_string *str)
{
  return (my_str_isalpha(str->str));
}

boolean		s_isprint(t_string *str)
{
  return (my_str_isprintable(str->str));
}
