/*
** my_signal.c for fonction signal in /home/loisel_k/Taff/C/Systeme-Unix/B2/minitalk/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Mar 12 13:42:08 2014 Kevin LOISELEUR
** Last update Wed Mar 12 14:37:51 2014 Kevin LOISELEUR
*/

#include <stdio.h>
#include <signal.h>

typedef void (*t_handler) (int);

t_handler signal(int sig, t_handler func);

void		catch_sighup(int sig)
{
  printf("Prosper youpla boum!!!\n");
}

int		main(int ac, char **av)
{
  pid_t		pid;

  if (signal(SIGHUP, catch_sighup) == SIG_ERR)
    {
      printf("gestionnaire non defini.\n");
      return (-1);
    }
  else
    printf("gestionnaire de signal defini maggle !\n");
  sleep(10);
  pid = getpid();
  printf("Le PID est : %d .\n");
  usleep(10000000);
}
