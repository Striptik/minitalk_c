/*
** my_receive.c for send signal in /home/loisel_k/Taff/C/Systeme-Unix/B2/minitalk/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Mar 12 17:14:02 2014 Kevin LOISELEUR
** Last update Thu Mar 13 11:33:09 2014 Kevin LOISELEUR
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void		catch_siguser(int sig)
{
  static int	i = 0;
  if (sig == SIGUSR1)
    {
      i++;
    }
  if (sig == SIGUSR2)
    {
      printf("%d\n", i);
      exit(0);
    }
}

int		main(int ac, char **av)
{
  pid_t		pid;

  pid = getpid();
  printf("Mon pid est : %d .\n", pid);
  signal(SIGUSR1, catch_siguser);
  signal(SIGUSR2, catch_siguser);
  while (1);
}
