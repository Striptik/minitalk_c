/*
** my_kill.c for tp kill in /home/loisel_k/Taff/C/Systeme-Unix/B2/minitalk/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Mar 12 10:56:54 2014 Kevin LOISELEUR
** Last update Wed Mar 12 14:34:53 2014 Kevin LOISELEUR
*/

//#include <sys/types.h>
//#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int		my_kill(char *s)
{
  int		nb;

  nb = atoi(s);
  if (nb <= 0)
    return (-1);
  kill(nb, SIGHUP);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac >= 2)
    {
      (!my_kill(av[1])) ? (printf("Le processus a bien envoye  sighup\n")) : printf("Impossible de trouver le processus");
    }			   
}
