/*
** utils_permission.c for shell in /home/Neferett/PSU_2016_minishell1
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Thu Jan 19 10:40:38 2017 Bonaldi Jordan
** Last update	Mon Mar 13 15:40:46 2017 Jordan Bonaldi
*/

# include "project.h"

boolean		get_permission(char *str)
{
  struct stat	fs;

  if (stat(str, &fs) == -1)
    return (true);
  if (!(fs.st_mode & S_IXUSR) || S_ISDIR(fs.st_mode))
    return (false);
  return (true);
}
