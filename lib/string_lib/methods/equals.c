/*
** equals.c for lib in /home/neferett/EPITECH/LIB/lib/string_lib/methods
** 
** Made by Jordan Bonaldi
** Login   <neferett@epitech.eu>
** 
** Started on  Sun Jan 29 22:21:13 2017 Jordan Bonaldi
** Last update Sun Jan 29 22:53:40 2017 Jordan Bonaldi
*/

# include "lib.h"

boolean			s_equals(t_string *str, char *str2)
{
  return (!my_strcmp(str->str, str2) ? true : false);
}

boolean			s_equalsn(t_string *str, char *str2, int n)
{
  return (!my_strncmp(str->str, str2, n) ? true : false);
}

boolean			s_equalsig(t_string *str, char *str2)
{
  return (!my_strcmp(my_strlowcase(my_strdup(str->str)),
		     my_strlowcase(my_strdup(str2))) ? true : false);
}

boolean			s_equalsign(t_string *str, char *str2, int n)
{
  return (!my_strncmp(my_strlowcase(my_strdup(str->str)),
		      my_strlowcase(my_strdup(str2)), n) ? true : false);
}

