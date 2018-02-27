/*
** utils_arr_prompt.c for  in /home/scrountchy/PSU_2016_42sh
**
** Made by Sacha PERIN
** Login   <sacha.perin@epitech.eu>
**
** Started on  Fri May 19 16:48:30 2017 Sacha PERIN
** Last update Fri May 19 16:49:07 2017 Sacha PERIN
*/

#include "project.h"

int     arr_len(char **arr)
{
  int   i;

  i = -1;
  if (!arr || !*arr)

    return (0);
  while (arr[++i]) {}
  return (i);
}

int     put_arr(char **arr)
{
  int   i;

  i = -1;
  while (arr && arr[++i])
    {
      my_putstr(arr[i]);
      my_putchar('\n');
    }
  return (1);
}
