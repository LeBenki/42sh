/*
** init_string.c for lib in /home/Neferett/LIB/lib/string_lib
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Thu Jan 26 15:04:23 2017 Bonaldi Jordan
** Last update	Mon Mar 13 16:38:27 2017 Jordan Bonaldi
*/

# include "lib.h"

void		init_string_part(t_string *str)
{
  str->toString = &s_tostring;
  str->contains = &s_contains;
  str->cat = &s_cat;
  str->rev = &s_rev;
  str->cut = &s_cut;
  str->reset = &s_reset;
  str->equals = &s_equals;
  str->equalsn = &s_equalsn;
  str->equalsIgnoreCase = &s_equalsig;
  str->equalsIgnoreCasen = &s_equalsign;
  str->recreate = &s_recreate;
  str->towordtab = &s_tab;
  str->placeof = &placeof;
}

t_string	*init_string(char *string)
{
  t_string	*str;

  if (!(str = malloc(sizeof(*str))))
    return (str);
  str->str = my_strdup(string);
  str->print = &string_print;
  str->length = &get_length;
  str->length(str);
  str->capitalize = &s_capitalizing;
  str->lower = &s_islower;
  str->upper = &s_isupper;
  str->alpha = &s_isalpha;
  str->printable = &s_isprint;
  str->num = &s_isnum;
  str->toInt = &s_toint;
  str->toInt_base = &s_tointbase;
  init_string_part(str);
  str->first = *str->str;
  if (str->length(str) > 2)
    str->end = str->str[str->size - 1];
  else
    str->end = str->str[0];
  return (str);
}
