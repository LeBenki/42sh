/*
** utils_prompt.c for  in /home/scrountchy/PSU_2016_42sh
**
** Made by Sacha PERIN
** Login   <sacha.perin@epitech.eu>
**
** Started on  Tue May  9 16:12:21 2017 Sacha PERIN
** Last update Sun May 21 03:20:54 2017 Sacha PERIN
*/

#include "project.h"

char		*get_folder_content(char *path, char *cmp)
{
  struct dirent *directory;
  DIR           *dir;
  char		*name;

  name = NULL;
  if (!(dir = opendir(path)))
    return (NULL);
  while ((directory = readdir(dir)))
    {
      if (!my_strncmp(directory->d_name, cmp, my_strlen(cmp)) &&
	  my_strcmp(directory->d_name, ".") &&
	  my_strcmp(directory->d_name, "..") &&
	  my_strlen(directory->d_name) >= my_strlen(cmp))
	{
	  if (name)
	    name = insert_str(name, directory->d_name, name ? my_strlen(name) : 0);
	  else
	    name = my_strdup(directory->d_name);
	  name = insert_str(name, "\n", my_strlen(name));
	}
    }
  closedir(dir);
  return (name);
}

int		prompt_loop(t_shell *sh)
{
  int		ret;

  if ((ret = ctrld_handler(sh)))
    return (ret);
  if (sh->read->str && *sh->read->str == '\t' && tab_handler(sh)) {}
  if (sh->read->error < 0 && handle_events(sh)) {}
  else if (sh->read->str && *sh->read->str && *sh->read->str != 4 &&
	   *sh->read->str != 12 && *sh->read->str != '\t')
    {
      if (sh->read->i && *sh->read->str != '\n')
	my_printf("%s", tparm(tigetstr("ich"), 1));
      my_printf("%s", sh->read->str);
      if (*sh->read->str != '\n')
	sh->read->buff = insert_str(sh->read->buff, sh->read->str,
				    my_strlen(sh->read->buff) + sh->read->i);
    }
  if (sh->read->str && *sh->read->str && nb_of(sh->read->str, '\n'))
    return (1);
  1 ? (sh->read->str = NULL), (sh->read->error = 0) : 0;
  return (0);
}

char            *get_input(t_shell *sh)
{
  int		i;

  sh->read->hst = 0;
  sh->read->h = arr_len(sh->read->hist);
  if (!isatty(STDIN_FILENO))
    return (get_next_line(0));
  if (!(sh->read->buff= malloc(1)))
    exit(84);
  1 ? *sh->read->buff = 0, sh->read->i = 0 : 0;
  while (get_read(sh))
    {
      i = prompt_loop(sh);
      if (i == 1)
	break;
      else if (i == 2)
	return ("exit");
      else if (i == 3)
	return ("clear");
    }
  if ((!sh->read->hist ||
       my_strcmp(sh->read->hist[arr_len(sh->read->hist) - 1],
		 sh->read->buff)) && sh->read->buff && *sh->read->buff)
    sh->read->hist = add_str(sh->read->hist, sh->read->buff, 1);
  sh->read->h = sh->read->hist ? arr_len(sh->read->hist) : 0;
  return (sh->read->buff);
}

int		prompt(t_shell *shell)
{
  t_string	*str;

  if (isatty(STDIN_FILENO))
    {
      if ((str = set_exists("prompt", shell->set)))
	my_printf("%s", str->str);
      else
	my_printf("$> ");
    }
  return (1);
}
