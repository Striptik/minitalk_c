/*
** my_strncpy.c for my_strncpy in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 11:24:08 2013 loisel_k
** Last update Thu Mar 20 15:43:00 2014 Kevin LOISELEUR
*/

#include <stdio.h>

char		*my_strncpy(char *dest, char *src, int nb)
{
  int		i;

  i = 0;
  if (src == NULL || dest == NULL)
    return (NULL);
  while (i < nb && src != '\0')
    dest[i] = src[i++];
  while (i < nb)
    dest[i++] = '\0';
  return (dest);
}
