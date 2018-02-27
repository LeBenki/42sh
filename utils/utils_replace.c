/*
** utils_replace.c for PSU_2016_minishell2
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sat Apr 22 01:01:42 2017 Jordan Bonaldi
** Last update	Sun Apr 23 00:10:39 2017 Jordan Bonaldi
*/

# include "project.h"

char			*hse(char *el)
{
  char			*ret;

  if (!(ret = malloc(1)))
    return (NULL);
  *ret = 0;
  while (*el != '=')
    {
      ret = my_strcatc(ret, *el);
      el++;
    }
  return (ret);
}

t_string	*replace_that_env(char *initial, char *replace, t_shell *shell)
{
  char		*tmp;
  char		*str;
  char		*lol;

  if (!(str = malloc(sizeof(my_strlen(initial) + my_strlen(replace) + 100))))
    exit(84);
  strcpy(str, initial);
  if (!(tmp = strstr(str, replace)))
    return (NULL);
  lol = get_env(++replace, shell->lenv);
  my_strncpy(tmp, lol, my_strlen(lol));
  return (init_string(str));
}

t_string	*replace_that_str(char *initial, char *replace, char *toreplace)
{
  int		tmp;
  int		tmp2;
  int		i;

  if (nb_of(initial, '{') && nb_of(initial, '}'))
    {
      replace = insert_str(replace, "{", 0);
      replace = insert_str(replace, "}", my_strlen(replace));
    }
  tmp2 = placeof(init_string(initial), '$');
  tmp = placeof(init_string(initial), '$') + my_strlen(replace) + 1;
  i = placeof(init_string(initial), '$');
  while (--tmp > i)
    initial = delchar_atpos(initial, tmp - 1);
  return (init_string(insert_str(initial, toreplace, tmp2)));
}

static int	test_tild_return(t_shell *shell, t_string *line,
				 int *ok, boolean ret)
{
  if (!ret && line->contains(line, '~'))
    {
      if (!get_env("HOME", shell->lenv) && (*ok = 2))
	my_printf("No $HOME variable set.\n");
      else
	line = replace_that_str(line->str, "~", get_env("HOME", shell->lenv));
    }
  else if (ret)
    {
      return (!*ok && line->contains(line, '$') &&
	      line->str[line->placeof(line, '$') + 1] &&
	      line->str[line->placeof(line, '$') + 1] != 27 && is_valid(line) ?
	      my_printf("%s: Undefined variable\n", strstr(line->str, "$") + 1) :
	      *ok == 2 ? 0 : 1);
    }
  return (0);
}

t_string	*search_in_command_line(t_string *line, t_shell *shell)
{
  int		ok;
  t_list	*tmp;
  t_set		*tmp2;

  1 ? ok = false, tmp = shell->lenv, tmp2 = shell->set : 0;
  test_tild_return(shell, line, &ok, false);
  if (line->contains(line, '$') && is_valid(line) &&
      line->str[line->placeof(line, '$') + 1] &&
      line->str[line->placeof(line, '$') + 1] != 27 &&
      tmp && tmp->n != shell->lenv)
    {
      while (tmp->p != shell->lenv)
	1 ? (strstr(line->str, hse(tmp->p->data)) ?
	     line = replace_that_env(line->str,
			      my_strcat("$", hse(tmp->p->data)), shell),
	     (ok = true) : 0), tmp = tmp->p : 0;
      if (!ok && tmp2 && tmp2->n != shell->set){
	while (tmp2->p != shell->set)
	  1 ? (strstr(line->str, tmp2->p->var->str) ?
	  line = replace_that_str(line->str, my_strcat("$", tmp2->p->var->str),
	  tmp2->p->data->str), ok = true : 0), tmp2 = tmp2->p : 0;
	}
    }
  return (!test_tild_return(shell, line, &ok, true) ? NULL : line);
}
