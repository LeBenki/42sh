/*
** good_execution.c for PSU_2016_minishell2
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Mon Mar 13 16:20:01 2017 Jordan Bonaldi
** Last update	Sat Apr 22 22:50:05 2017 Jordan Bonaldi
*/

# include "project.h"

static void	try_execute(t_shell *shell, char c, t_string **string)
{
  int		i;

  i = -1;
  while (string[++i] && *string[i]->str)
    {
      if (shell->r_d && c == '&' &&
	  (shell->done || shell->list->n->delay != 0))
	break;
      while (string[i]->str[--string[i]->size] == ' ')
	string[i]->str[string[i]->size] = 0;
      if (c == 'r' && builtin_repeat(shell, string[i]))
	continue;
      else if (string[i]->contains(string[i], '&') && is_ok(string[i], '&') &&
	  good_execution(shell, string[i]))
	continue;
      else if ((good_char(string[i], shell) == '>' ||
		good_char(string[i], shell) == '<') &&
	       good_execution(shell, string[i]))
	continue;
      else if (string[i]->contains(string[i], '|') && is_ok(string[i], '|') &&
	       exec_pipe(stw_string(string[i], shell, &c), shell))
	continue;
      if (shell_up(shell, string[i]))
	search_command(shell);
    }
}

t_string	*try_handle(t_string *line)
{
  int		i;
  int		pos;

  1 ? pos = 0, i = -1 : 0;
  if (line->str[0] == ' ')
    line->str++;
  if (line->str[0] == '`' && line->str[my_strlen(line->str) - 1] == '`')
    {
      pos = line->placeof(line , ' ');
      line->str++;
      line = init_string(insert_str(line->str, "`", pos));
    }
  else if (line->str[0] == '`' && line->str[my_strlen(line->str) - 1] == ' ')
      line = init_string(my_strcat(line->str, "`"));
  else
    while (line->str[++i])
	if (line->str[i] == '`')
	    {
	      pos = line->placeof(line , ' ');
	      line->str[i] = ' ';
	      line = init_string(insert_str(line->str, " `", pos));
	      line = init_string(delchar_atpos(line->str, pos + 2));
	      break;
	    }
  return (line);
}

t_string	*try_handle_inhib(t_string *line)
{
  int		pos;
  int		i;
  int		j;

  i = -1;
  pos = 0;
  while (line->str[++i])
    {
      if (line->str[i] == ' ')
	pos = i;
      if (line->str[i] == '\\')
	{
	  line = init_string(insert_str(line->str, "\"", pos + 1));
	  j = i + 1;
	  line = init_string(delchar_atpos(line->str, i + 1));
	  while (line->str[++j])
	    if (line->str[j] == ' ' && (pos = j))
		break;
	  pos = j - 1;
	  line = init_string(insert_str(line->str, "\"", pos + 1));
	}
    }
  return (line);
}

boolean		good_execution(t_shell *shell, t_string *line)
{
  char		c;
  t_string	**string;

  c = 0;
  string = NULL;
  shell->done = 0;
  shell->list->n->delay = 0;
  line = try_handle(line);
  line = try_handle_inhib(line);
  if (!(string = stw_string(line, shell, &c)) || shell->ret)
    return (false);
  if (c == '|')
    {
      string[1] = try_handle(string[1]);
      return (exec_pipe(string, shell));
    }
  if (!(string = handle_manip(shell, line, &c, string)))
    return (false);
  try_execute(shell, c, string);
  end_handle_manip(shell, line, c);
  return (true);
}
