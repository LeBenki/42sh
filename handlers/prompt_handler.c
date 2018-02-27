/*
** prompt_handler.c for  in /home/scrountchy/PSU_2016_42sh
**
** Made by Sacha PERIN
** Login   <sacha.perin@epitech.eu>
**
** Started on  Thu May 18 14:17:15 2017 Sacha PERIN
** Last update Sun May 21 16:14:45 2017 Sacha PERIN
*/

#include "project.h"

void            handle_history(t_shell *sh)
{
  if (sh->read->error == -6 && sh->read->h > 0)
    {
      if (!sh->read->hst)
	{
	  sh->read->save = my_strdup(sh->read->buff);
	  sh->read->hst = 1;
	}
      sh->read->buff = my_strdup(sh->read->hist[--sh->read->h]);
      my_printf("%s", tparm(tigetstr("dl"), 1));
      prompt(sh);
      my_printf("%s", sh->read->buff);
    }
  if (sh->read->error == -7)
    {
      my_printf("%s", tparm(tigetstr("dl"), 1));
      prompt(sh);
      if (sh->read->h < arr_len(sh->read->hist) - 1)
	sh->read->buff = my_strdup(sh->read->hist[++sh->read->h]);
      else if (sh->read->h < arr_len(sh->read->hist))
	{
	  1 ? (sh->read->hst = 0), sh->read->h++ : 0;
	  sh->read->buff = sh->read->save;
	}
      my_printf("%s", sh->read->buff);
    }
}

int             handle_events(t_shell *sh)
{
  while (sh->read->error == -4 && sh->read->i > -str_len(sh->read->buff))
    1 ? my_printf("%s", tparm(tigetstr("cub"), 1, 1)), sh->read->i-- : 0;
  while (sh->read->error == -5 && sh->read->i < 0)
    1 ? my_printf("%s", tparm(tigetstr("cuf"), 1, 1)), sh->read->i++ : 0;
  if (sh->read->error == -1)
    1 ? my_printf("%s", tparm(tigetstr("cub"), 1, 1)), sh->read->i-- : 0;
  if (sh->read->error == -2)
    1 ? my_printf("%s", tparm(tigetstr("cuf"), 1, 1)), sh->read->i++ : 0;
  if (sh->read->error == -3 && -sh->read->i < str_len(sh->read->buff))
    {
      my_printf("%s", tparm(tigetstr("cub"), 1, 1));
      my_printf("%s", tparm(tigetstr("dch"), 1));
      if (sh->read->buff && *sh->read->buff)
	        sh->read->buff =
		  delchar_atpos(sh->read->buff,
				str_len(sh->read->buff) + sh->read->i - 1);
    }
  while (sh->read->i < -str_len(sh->read->buff))
    1 ? my_printf("%s", tparm(tigetstr("cuf"), 1, 1)), sh->read->i++ : 0;
  while (sh->read->i > 0 && sh->read->i--)
    my_printf("%s", tparm(tigetstr("cub"), 1, 1));
  handle_history(sh);
  return (1);
}

int             ctrld_handler(t_shell *sh)
{
  if (sh->read->str && sh->read->str[0] == 4)
    {
      if (!sh->read->buff || !*sh->read->buff)
	return (2);
      else
	{
	  my_printf("\n");
	  prompt(sh);
	  my_printf("%s", sh->read->buff);
	}
    }
  if (sh->read->str && sh->read->str[0] == 12)
    return (3);
  return (0);
}

int             tab_handler(t_shell *sh)
{
  char		*fldr;
  char		*cont;
  char		**paths;
  int		i;

  if (sh->read->str && sh->read->str[0] == '\t' && (i = -1) && !(fldr = NULL))
    {
      paths = my_str_to_wordtab(get_env("PATH", sh->lenv), ':');
      while (paths[++i])
	if ((cont = get_folder_content(paths[i], sh->read->buff)))
	  fldr = str_cat(fldr, cont);
      if (!fldr || !*fldr)
	return (1);
      if (nb_of(fldr, '\n') > 1)
	my_printf("\n%s", fldr);
      else
	{
	  sh->read->buff = fldr;
	  fldr[str_len(fldr) - 1] = '\0';
	  my_printf("%s", tparm(tigetstr("dl"), 1));
	}
      prompt(sh);
      my_printf("%s", sh->read->buff);
    }
  return (1);
}
