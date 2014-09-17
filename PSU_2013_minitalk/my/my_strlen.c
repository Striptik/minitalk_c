/*
** my_strlen.c for my_strlen in /home/loisel_k/rendu/Piscine-C-lib/my
** 
** Made by loisel_k
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Oct  9 10:11:13 2013 loisel_k
** Last update Thu Mar 20 15:43:44 2014 Kevin LOISELEUR
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}
