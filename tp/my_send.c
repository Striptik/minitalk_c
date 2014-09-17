/*
** my_send.c for my_send in /home/loisel_k/Taff/C/Systeme-Unix/B2/minitalk/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Mar 12 17:00:45 2014 Kevin LOISELEUR
** Last update Thu Mar 13 12:09:12 2014 Kevin LOISELEUR
*/

#include <stdio.h>
#include <signal.h>

# define END_SIGNAL	100000



int		main(int ac, char **av)
{
  int		nb;
  int		i;

  i = 0;
  if (ac > 1)
    {
      nb = atoi(av[1]);
      while (i < END_SIGNAL)
	{
	  kill(nb, SIGUSR1);
	  i++;
	  usleep(20);
	}
      kill(nb, SIGUSR2);
    }
  return (0);
}
