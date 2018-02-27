/*
** inhibitor_utils.c for 42sh in /Users/neferett/EPITECH/PSU_2016_42sh/utils/
**
** Made by Jordan Bonaldi
** Login   <Neferett@epitech.eu@epitech.eu>
**
** Started on  Sat Apr 29 16:42:14 2017 Jordan Bonaldi
** Last update Sat Apr 29 16:42:14 2017 Jordan Bonaldi
*/

# include "project.h"

boolean	is_valid(t_string *line)
{
  boolean		in;
  int			i;

  in = false;
  i = -1;
  while (line->str[++i])
    {
      if (!in && line->str[i] == '\'')
	in = true;
      else if (in && line->str[i] == '\'')
	in = false;
      if (line->str[i] == '$' && !in)
      	return (true);
    }
  return (false);
}
