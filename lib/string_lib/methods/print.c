/*
** print.c for lib in /home/Neferett/LIB/lib/string_lib/methods
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Thu Jan 26 15:07:59 2017 Bonaldi Jordan
** Last update Mon Feb 13 17:35:15 2017 Jordan Bonaldi
*/

# include "lib.h"

void		string_print(t_string *str, char *msg)
{
  if (!nb_of(msg, '%') &&
      !my_printf("No %%s in your print message !\n"))
    return;
  my_printf(msg, str->str);
}
