/*
** if_command_sheitan.c for 42sh in /home/benki/Epitech/PSU_2016_42sh/handlers/builtin/
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Wed May 10 14:15:06 2017 Lucas Benkemoun
** Last update Thu May 18 09:31:34 2017 Lucas Benkemoun
*/

# include "project.h"

static int		test_nb(t_shell *sh, char *s1, char *s2, char *sep)
{
  if ((!strcmp(sep, ">=")) && (my_getnbr(s1) >= my_getnbr(s2)))
    return (1);
  if ((!strcmp(sep, "<=")) && (my_getnbr(s1) <= my_getnbr(s2)))
    return (1);
  if (sep[0] == '>' && !sep[1] && (my_getnbr(s1) > my_getnbr(s2)))
    return (1);
  if (sep[0] == '<' && !sep[1] && (my_getnbr(s1) < my_getnbr(s2)))
    return (1);
  return (sh->idif = 0);
}

static int		test_equality(t_shell *sh, char *s1, char *s2, char *sep)
{
  boolean		b;

  if (!my_strcmp(sep, "=="))
    b = 0;
  else
    b = 1;
  if (!b)
    {
      if (!my_strcmp(s1, s2))
	return (1);
    }
  else if (my_strcmp(s1, s2))
    return (1);
  return (sh->idif = 0);
}

char            *my_epur_all_str(char *str)
{
  char          *result;
  int           i;
  int           j;

  i = -1;
  while (str[++i])
    if (str[i] == '\t')
      str[i] = ' ';
  i = my_strlen(str);
  while (str[--i] && str[i] == ' ')
    str[i] = 0;
  i = -1;
  while (str[++i] && str[i] == ' ');
  if (!(result = malloc(sizeof(char) * (my_strlen(str) + 1))))
    return (NULL);
  j = -1;
  while (str[i])
    result[++j] = str[i++];
  result[++j] = 0;
  return (result);
}

int	builtin_if_loop(t_shell *shell, char *str)
{
  if (!my_strcmp(str, "endif"))
    return (1);
  if (!my_strncmp(str, "else", 4))
    {
      if (str[4] && str[5])
	good_execution(shell, init_string(&str[5]));
      return (1);
    }
  if (!my_strncmp(str, "else if", 7))
    {
      shell->idif = 2;
      good_execution(shell, init_string(&str[5]));
    }
  else if (!my_strncmp(str, "if", 2))
    good_execution(shell, init_string(str));
  if (shell->idif)
    return (1);
  if (isatty(STDIN_FILENO))
    my_putstr("if? ");
  return (0);
}

void	builtin_if_sheitan(t_shell *shell, char **arr)
{
  char	*str;

  shell->idif = 1;
  if (((!my_strcmp(arr[1], "==") || !my_strcmp(arr[1], "!=")) &&
       test_equality(shell, arr[0], arr[2], arr[1])) || ((arr[1][0] == '<' ||
		     arr[1][0] == '>') &&
	   my_str_isnum(arr[0]) && my_str_isnum(arr[2]) && test_nb(shell,
			arr[0], arr[2], arr[1])))
    return;
  if (isatty(STDIN_FILENO))
    my_putstr("if? ");
  while ((str = get_input(shell)))
    {
      str = my_epur_all_str(str);
      if (builtin_if_loop(shell, str))
	break;
    }
}
