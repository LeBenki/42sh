/*
** cd_command.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Sun Jan  8 13:53:08 2017 Bonaldi Jordan
** Last update	Mon Mar 13 15:42:00 2017 Jordan Bonaldi
*/

# include "project.h"

static char			*get_home(t_shell *shell)
{
  return (!get_env("HOME", shell->lenv) ? my_strdup("/home/") :
	  my_strdup(get_env("HOME", shell->lenv)));
}

static boolean		try_m(t_shell *shell)
{
  if (shell->cmd[1] && *shell->cmd[1] == '-' &&
      !shell->cmd[1][1] && !shell->cmd[2])
    {
      if (get_env("OLDPWD", shell->lenv))
	shell->cmd[1] = my_strdup(get_env("OLDPWD", shell->lenv));
      else
	shell->cmd[1] = get_home(shell);
      builtin_cd(shell);
      return (true);
    }
  return (false);
}

void			builtin_cd(t_shell *sh)
{
  int			m;
  char			*b;

  if ((m = 1) && (!(b = malloc(512)) || try_m(sh) || !getcwd(b, 512)))
    return;
  if (sh->cmd[1] && *sh->cmd[1])
    {
      if (*sh->cmd[1] == '-' && sh->cmd[1][1] == '-' && sh->cmd[2]
	  && *sh->cmd[2] == '-' && !sh->cmd[2][1] && (m = 2)) {}
      else if (*sh->cmd[1] == '-' && sh->cmd[1][1] == '-' && !sh->cmd[2]
	       && (sh->cmd[1] = get_home(sh))) {}
      if (get_env("OLDPWD", sh->lenv))
	my_rm_list(&sh->lenv, "OLDPWD", &my_strncmp, &my_strlen);
      if (sh->lenv == NULL && (sh->lenv = init_list())) {}
      add_end_env(my_strcat("OLDPWD=", b), sh->lenv);
      if (access(sh->cmd[m], F_OK) < 0 && (sh->done = 1))
	my_printf("%s: No such file or directory.\n", sh->cmd[m]);
      else if (access(sh->cmd[m], R_OK) < 0 && (sh->done = 1))
	my_printf("%s: Permission denied.\n", sh->cmd[m]);
      else if (chdir(sh->cmd[m]) < 0 && (sh->done = 1))
	my_printf("%s: Not a directory.\n", sh->cmd[m]);
    }
  else if ((sh->cmd[1] = get_home(sh)))
    builtin_cd(sh);
}
