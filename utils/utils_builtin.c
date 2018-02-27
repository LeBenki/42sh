/*
** utils_builtin.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Jan  8 13:37:31 2017 Bonaldi Jordan
** Last update	Sat Apr 22 21:47:16 2017 Jordan Bonaldi
*/

# include "project.h"

char	*my_cut(size_t size, char *str)
{
  return (str += size);
}

char	**get_paths(t_shell *shell)
{
  if (get_env("PATH", shell->lenv))
    return (my_str_to_wordtab(get_env("PATH", shell->lenv), ':'));
  else
    return (my_str_to_wordtab("/bin", ':'));
}

char		*get_env(char *name, t_list *list)
{
  t_list	*tmp;

  tmp = list;
  if (!tmp)
    return (NULL);
  while (tmp->p != list)
    {
      if (!my_strncmp(tmp->p->data, my_strcat(name, "="), my_strlen(name) + 1))
	return (my_cut(my_strlen(name) + 1, tmp->p->data));
      tmp = tmp->p;
    }
  return (NULL);
}

t_builtin	*init_builtin(int i)
{
  t_builtin	*bi;

  bi = xmalloc(sizeof(*bi) * 15);
  if ((bi[++i].cmd = my_strdup("cd")) && (bi[i].builtin = &builtin_cd)) {}
  if ((bi[++i].cmd = my_strdup("setenv")) && (bi[i].builtin = &builtin_set)) {}
  if ((bi[++i].cmd = my_strdup("unsetenv")) &&
      (bi[i].builtin = &builtin_unset)) {}
  if ((bi[++i].cmd = my_strdup("env")) && (bi[i].builtin = &builtin_env)) {}
  if ((bi[++i].cmd = my_strdup("exit")) && (bi[i].builtin = &builtin_exit)) {}
  if ((bi[++i].cmd = my_strdup("alias")) &&
      (bi[i].builtin = &builtin_alias)) {}
  if ((bi[++i].cmd = my_strdup("echo")) && (bi[i].builtin = &builtin_echo)) {}
  if ((bi[++i].cmd = my_strdup("which")) &&
      (bi[i].builtin = &builtin_which)) {}
  if ((bi[++i].cmd = my_strdup("where")) &&
      (bi[i].builtin = &builtin_where)) {}
  if ((bi[++i].cmd = my_strdup("set")) &&
      (bi[i].builtin = &builtin_set_var)) {}
  if ((bi[++i].cmd = my_strdup("foreach")) &&
      (bi[i].builtin = &builtin_foreach)) {}
  if ((bi[++i].cmd = my_strdup("if")) && (bi[i].builtin = &builtin_if)) {}
  if ((bi[++i].cmd = my_strdup("source")) &&
      (bi[i].builtin = &builtin_source)) {}
  if (!(bi[++i].cmd = 0) && (bi[i].builtin = NULL)) {}
  return (bi);
}
