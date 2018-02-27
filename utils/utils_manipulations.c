/*
** utils_manipulations.c for PSU_2016_minishell2
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Apr 09 10:49:14 2017 Jordan Bonaldi
** Last update	Mon Apr 10 10:14:07 2017 Jordan Bonaldi
*/

# include "project.h"

static boolean		is_valid_char(char c)
{
	return (c == ';' || c == '&');
}

static boolean		before_valid(char c)
{
	return (c == ';' || c == '&');
}

static char				get_single_op(char c)
{
	return (c == '>' || c == '<' || c == '|');
}

static char			*tmp_epur(t_string *line)
{
  int						i;
  char					*arr;

  i = -1;
  if (!(arr = malloc(1)))
    return (NULL);
  *arr = 0;
  while (line->str[++i] == ' ');
  i--;
  while (line->str[++i])
    {
      while (line->str[i] == ' ' && line->str[i + 1] == ' ' && ++i);
    if (line->str[i] == ' ' && (arr = my_strcatc(arr, ' '))) {}
      else if ((line->str[i] == '>' || line->str[i] == '<') &&
	       line->str[i + 1] != ' ' &&
	       line->str[i + 1] != '>' && line->str[i + 1] != '<')
	line->str[i] == '>' ? (arr = my_strcat(arr, "> "))
	  : (arr = my_strcat(arr, "< "));
    else if ((arr = my_strcatc(arr, line->str[i]))) {}
    }
  return (arr);
}

boolean		look_at_line(t_string *line)
{
  char		*arr;
  int			i;

  if ((i = -1) && !(arr = tmp_epur(line)))
    return (0);
  line->recreate(line, arr);
  while (line->str[++i])
    if (i > 1 && (!line->str[i - 1] || (line->str[i - 1] &&
					before_valid(line->str[i - 1]))) &&
	line->str[i] == '|')
	return (0);
      else if (i > 2 && line->str[i - 2] && before_valid(line->str[i - 2])
	       && line->str[i - 1] == ' ' && line->str[i] == '|')
	return (0);
      else if (get_single_op(line->str[i]) &&
	       (!line->str[i + 1] ||
		((line->str[i + 1] && is_valid_char(line->str[i + 1])) ||
		 (line->str[i + 2] && is_valid_char(line->str[i + 2])))))
	return (0);
      else if (line->str[i] == '&' && line->str[i + 1] == '&' &&
	       (!line->str[i + 2] || ((line->str[i + 2] &&
				       line->str[i + 2] == ';') || (line->str[i + 3] &&
				       line->str[i + 3] == ';'))))
	return (0);
      return (1);
}
