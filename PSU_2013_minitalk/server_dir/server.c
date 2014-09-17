/*
** main.c for main minitalk in /home/loisel_k/Taff/C/Systeme-Unix/B2/minitalk/PSU_2013_minitalk
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Mar 11 12:51:36 2014 Kevin LOISELEUR
** Last update Fri Mar 21 16:18:35 2014 Kevin LOISELEUR
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "server.h"

void		set_and_write(int value)
{
  static int	bit = 0;
  static char	letter = 0;

  if (value == 1)
    {
      letter |= (1 << bit);
      bit++;
    }
  if (value == 0)
    {
      letter &= ~(1 << bit);
      bit++;
    }
  if (bit == (SIZE_BYTE))
    {
      my_printf("%c", letter);
      bit = 0;
    }
}

void		catch_siguser(int signal)
{
  static char	c;
  static int   	count = 0;
  int		bit;

  if (signal == SIGUSR1)
    set_and_write(1);
  else if (signal == SIGUSR2)
    set_and_write(0);
}

void		recept(void)
{
  if (signal(SIGUSR1, catch_siguser) == SIG_ERR)
    {
      my_rprintf("Fail with SIGUSR1.\n");
      return ;
    }
  if (signal(SIGUSR2, catch_siguser) == SIG_ERR)
    {
      my_rprintf("Fail with SIGUSR1.\n");
      return ;
    }

}

int		main(int ac, char **av)
{
  pid_t		pid;

  pid = getpid();
  my_printf("\033[1;35m|------- MINITALK -------|\033[0m\n");
  usleep(1000);
  my_printf("\033[1;35m|--[\033[1;32mPid server\033[1;35m] : \033[1;31m ");
  my_printf("%d\033[1;35m--|\n|------------------------|\033[0m\n", pid);
  my_printf("\nWaiting for client messages.\n\n");
  recept();
  pause();
  while (BOUCLE_INF);
}
