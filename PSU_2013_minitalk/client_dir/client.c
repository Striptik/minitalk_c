/*
** client.c for client for minitalk in /home/loisel_k/Taff/C/Systeme-Unix/B2/minitalk/PSU_2013_minitalk/client
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Thu Mar 13 15:34:17 2014 Kevin LOISELEUR
** Last update Fri Mar 21 13:27:42 2014 Kevin LOISELEUR
*/

#include <signal.h>
#include <stdlib.h>
#include "../include/my.h"
#include "client.h"

void		catch_siguser(int sig)
{
  if (sig != SIGUSR1)
    {
      my_printf("Error on signal.\n");
      exit(-1);
    }
}

void		send_sig_bin(char letter, int pid)
{
  int		bit;

  bit = 0;
  while (bit < (SIZE_BYTE))
    {
      if ((letter >> bit) & 1)
	{
	  if (kill(pid, SIGUSR1) == KILL_ERROR)
	    {
	      my_rprintf("Error on kill SIGUSR1.\n");
	      exit(1);
	    }
	}
      else
	{
	  if (kill(pid, SIGUSR2) == KILL_ERROR)
	    {
	      my_rprintf("Error on kill SIGUSR2.\n");
	      exit(1);
	    }
	}
      bit++;
      usleep(PAUSE);
    }
}

void		translate_msg(char **av, int pid)
{
  int		i;
  int		j;
  int		bin;

  i = 2;
  while (av && av[i])
    {
      j = 0;
      while (av[i] && av[i][j])
	send_sig_bin(av[i][j++], pid);
      i++;
      send_sig_bin('\n', pid);
    }
}

int		main(int ac, char **av)
{
  int		pid;

  if (ac >= 3)
    {
      if (signal(SIGUSR1, catch_siguser) == SIG_ERR)
	{
	  my_rprintf("Error on SIGUSR1");
	  return (-1);
	}
      if ((pid = my_getnbr(av[1])) <= 0)
	{
	  my_rprintf("Bad Pid server");
	  return (2);
	}
      translate_msg(av, pid);
    }
  else
    {
      my_rprintf("Bad number of argument.\n");
      my_rprintf("Using client like this : ./client [pid server] ");
      my_rprintf("([translation] | or 'cat file').\n");
    }
  return (0);
}
