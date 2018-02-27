/*
** handler_manip.c for PSU_2016_minishell2
**
** Made by	Jordan Bonaldi
** Login	jordan.bonaldi@epitech.net
**
** Started on	Sun Apr 09 12:02:52 2017 Jordan Bonaldi
** Last update	Thu Apr 13 17:08:31 2017 Jordan Bonaldi
*/

# include "project.h"

static char	*dep_pointer(t_string *line, char c)
{
  int		i;
  char		*out;
  int		pos;
  char		**str;
  char		*tmp;
  char		*tmp2;

  i = pos = -1;
  if (!(out = malloc(1)) || !(str = my_str_to_wordtab(line->str, ' ')))
    exit(84);
  while (str[++pos] && *str[pos] != c);
  --pos;
  while (str[++pos] && str[pos + 1] && str[pos + 2])
    {
      tmp = str[pos];
      tmp2 = str[pos + 1];
      str[pos] = str[pos + 2];
      str[pos + 1] = tmp;
      str[pos + 2] = tmp2;
    }
  if ((i = -1) && !(*out = 0)) {}
  while (str[++i])
    out = my_strcat(out, my_strcat(str[i], " "));
  out[my_strlen(out) - 1] = 0;
  return (out);
}

t_string	**handle_manip(t_shell *shell, t_string *line,
			       char *c, t_string **string)
{
  int		i;

  i = -1;
  if (shell->right || shell->left)
    {
      line = init_string(dep_pointer(line, shell->right ? '>' : '<'));
      while (line->str[++i])
    if (line->str[i] == '"' && (line->str[i] = ' ')) {}
      if (!(string = stw_string(line, shell, c)))
	return (NULL);
    }
  if (shell->r_d && shell->left)
    string = start_d_left(shell, string);
  if (!shell->r_d && shell->left)
    string = start_nd_left(shell, string);
  if (shell->r_d && shell->right)
    string = start_d_right(shell, string);
  if (!shell->r_d && shell->right)
    string = start_nd_right(shell, string);
  return (string);
}

void	end_handle_manip(t_shell *shell, t_string *line, char c)
{
  if (c == '>' && line->contains(line, '<') &&
      (shell->left = true) && (shell->right = true)) {}
  if (shell->r_d && shell->left)
    end_d_left(shell);
  if (!shell->r_d && shell->left)
    end_nd_left(shell);
  if (shell->r_d && shell->right)
    end_d_right(shell);
  if (!shell->r_d && shell->right)
    end_nd_right(shell);
}
