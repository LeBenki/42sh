/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/Neferett/CPool_Day08/task04
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Wed Oct 12 10:53:16 2016 Bonaldi Jordan
** Last update	Sun Apr 09 22:12:08 2017 Jordan Bonaldi
*/

# include "project.h"
# include "lib.h"

static boolean	get_ini(char c, boolean ok, char *str, char l)
{
  int	i;

  i = 0;
  if (ok)
    {
      while (str[++i] && str[i] != '"')
	{
	  if (l != 0 && str[i] == l)
	    return (true);
	  else if (l == 0 && (str[i] == '&' || str[i] == '>' || str[i] == '<' ||
	      str[i] == '|' || str[i] == ' '))
	    return (true);
	}
      return (false);
    }
  else
    return (c == '"' || c == '\'' || c == '`');
}

static char	*fill_up(char *str, char c)
{
  int	i;
  char	*arr;

  i = -1;
  if (!(arr = malloc(my_strlen(str) * 10)))
    exit(84);
  while (str[++i] && (c != 0 ? str[i] != c : !get_ini(str[i], false, NULL, c)))
    arr[i] = str[i];
  arr[i] = 0;
  return (arr);
}

boolean		handle_me(t_tab *ta, char c)
{
  if (!ta->in && ((get_ini(*ta->str, false, NULL, 0) &&
		   get_ini(*ta->str, true, ta->str, 0)) ||
		  *ta->str == '`') && ++ta->str)
    {
      ta->ini = *(ta->str - 1) == '\'' ? '\'' :
	  *(ta->str - 1) == '"' ? '"' : '`';
      if (c != ' ' || ta->ini == '`')
	ta->arr = my_strcat(ta->arr, my_strcat(my_strcatc("", ta->ini),
					       my_strdup(fill_up(ta->str, ta->ini))));
      else
	ta->arr = my_strcat(ta->arr, my_strdup(fill_up(ta->str, ta->ini)));
      while (*ta->str && *ta->str != ta->ini && (ta->str++) && ++ta->i);
      ++ta->str;
      if (c != ' ' && (ta->arr = insert_str(ta->arr, "`",
					    my_strlen(ta->arr) + 1)) && ++ta->i)
	return (true);
      else if (ta->ini == '`' && (ta->arr = insert_str(ta->arr, "`",
						       my_strlen(ta->arr) + 1)) && ++ta->i)
	return (true);
    }
  return (false);
}

char		**tab_complete(char **arr, t_tab *ta, char c)
{
  if ((ta->j = -1) && !(ta->in = false) &&
      !(ta->arr = malloc(my_strlen(ta->str) * 10)))
    return (NULL);
  while (*ta->str && !(ta->i = 0))
    {
      while (*ta->str && *ta->str == c && (ta->str++)) {}
      while (*ta->str && *ta->str != c)
	{
	  if (handle_me(ta, c))
	    continue;
	  else if (get_ini(*ta->str, false, NULL, 0) && !ta->in &&
		   (ta->in = true) && ++ta->str) {}
	  else if (get_ini(*ta->str, false, NULL, 0) && ta->in &&
		   !(ta->in = false) && ++ta->str) {}
	  if ((ta->arr[ta->i] = *ta->str) && (++ta->i) &&
	      !(ta->arr[ta->i] = 0) && (ta->str++)) {}
	}
      if (*ta->arr && (arr[++ta->j] = my_strdup(ta->arr)) && (ta->i = -1))
	{
	  while (ta->arr[++ta->i])
	    ta->arr[ta->i] = 0;
	}
    }
  arr[++ta->j] = NULL;
  return (arr);
}

char	**my_str_to_wordtab(char *str, char c)
{
  char	**arr;
  t_tab	*ta;

  if (!(ta = malloc(sizeof(t_tab))))
    exit(84);
  if (!(arr = malloc(sizeof(char *) * my_strlen(str) * 10)))
    return (NULL);
  ta->str = str;
  arr = tab_complete(arr, ta, c);
  return (arr);
}
