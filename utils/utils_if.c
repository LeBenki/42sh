/*
** utils_if.c for 42sh in /Users/neferett/EPITECH/PSU_2016_42sh/utils/
**
** Made by Jordan Bonaldi
** Login   <Neferett@epitech.eu@epitech.eu>
**
** Started on  Mon May  8 16:18:26 2017 Jordan Bonaldi
** Last update Mon May  8 16:18:26 2017 Jordan Bonaldi
*/

# include "project.h"

boolean		in_if(t_string *line, char c)
{
  boolean		in;
  int			i;

  in = false;
  i = -1;
  if (!strstr(line->str, "if"))
    return (false);
  while (line->str[++i])
    {
      if (!in && line->str[i] == '(')
	in = true;
      else if (in && line->str[i] == ')')
	in = false;
      if (line->str[i] == c && in)
      	return (true);
    }
  return (false);
}
