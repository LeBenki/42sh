/*
** my_cut.c for shell in /home/Neferett/PSU_2016_minishell1
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Jan  8 14:51:32 2017 Bonaldi Jordan
** Last update Sun Jan  8 14:54:37 2017 Bonaldi Jordan
*/

# include "project.h"

char		*my_cut(int i, char *str)
{
  return (str += i);
}
