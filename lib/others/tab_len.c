/*
** tab_len.c for shell in /home/Neferett/PSU_2016_minishell1
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Jan  8 13:39:07 2017 Bonaldi Jordan
** Last update Sun Jan  8 13:39:40 2017 Bonaldi Jordan
*/

# include "lib.h"

int	tab_len(char **tab)
{
  return (*tab ? tab_len(++tab) + 1 : 0);
}
