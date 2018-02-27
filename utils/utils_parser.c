/*
** utils_parser.c for PSU_2016_minishell2
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Mon Mar 13 15:52:49 2017 Jordan Bonaldi
** Last update	Fri Apr 21 22:36:29 2017 Jordan Bonaldi
*/

# include "project.h"

int	st_len(t_string **string)
{
  return (*string ? st_len(++string) + 1 : 0);
}

t_string	**stw_string(t_string *line, t_shell *shell, char *c)
{
  t_string	**transform;
  char		**arr;
  int		i;

  i = -1;
  arr = NULL;
  *c = good_char(line, shell);
  if (*c != 'r')
    arr = line->towordtab(line, *c);
  if (!(transform = malloc(sizeof(t_string *) * ((*c == 'r' ? 0 :
				  arr_len(arr)) + 1))))
    return (NULL);
  if ((*c == ' ' || *c == 'r') && (*transform = line) &&
      !(transform[1] = NULL))
    return (transform);
  while (++i < arr_len(arr))
    transform[i] = init_string(arr[i]);
  transform[i] = NULL;
  return (transform);
}

static boolean		in_good_place(t_string *line, char c)
{
  int			i;

  i = line->placeof(line, c);
  if (line->str[i] == c && line->str[i + 1] == c &&
      line->str[i + 2] != c)
    return (true);
  else
    return (false);
}

boolean			is_ok(t_string *line, char c)
{
  boolean		in;
  int			i;

  in = false;
  i = -1;
  while (line->str[++i])
    {
      if (!in && (line->str[i] == '"' || line->str[i] == '\''
		  || line->str[i] == '`'))
	in = true;
      else if (in && (line->str[i] == '"' || line->str[i] == '\''
		      || line->str[i] == '`'))
	in = false;
      if (line->str[i] == c && !in)
	return (true);
    }
  return (false);
}

char			good_char(t_string *line, t_shell *s)
{
  s->pipe = false;
  s->ret = false;
  return (line->contains(line, ';') && is_ok(line, ';') ? ';' :
	  strstr(line->str, "repeat") ? 'r' :
	  line->contains(line, '|') && is_ok(line, '|') &&
	  in_good_place(line, '|')
	  && (s->pipe = true) && (s->r_d = true) ? '|' :
	  line->contains(line, '&') && is_ok(line, '&') &&
	  in_good_place(line, '&') && (s->r_d = true) ? '&' :
	  line->contains(line, '>') && !in_if(line, '>') && is_ok(line, '>') &&
	  in_good_place(line, '>') && (s->r_d = true) && (s->right = true) &&
	  !(s->left = false) ? '>' :
          line->contains(line, '<') && !in_if(line, '<') && is_ok(line, '<')
	  && in_good_place(line, '<') && (s->r_d = true) && (s->left = true) &&
          !(s->right = false) ? '<' :
          line->contains(line, '>') && !in_if(line, '>') && is_ok(line, '>')
	  && (s->right = true)
          && !(s->r_d = false) && !(s->left = false) ? '>' :
          line->contains(line, '<') && !in_if(line, '<') && is_ok(line, '<')
	  && (s->left = true) &&
          !(s->r_d = false) && !(s->right = false) ? '<' :
          line->contains(line, '|') && is_ok(line, '|') &&
	  (s->pipe = true) ? '|' : ' ');
}
