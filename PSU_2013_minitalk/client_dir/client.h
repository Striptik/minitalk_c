/*
** client.h for client header in /home/loisel_k/Taff/C/Systeme-Unix/B2/minitalk/PSU_2013_minitalk/client_dir
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Mar 19 12:16:54 2014 Kevin LOISELEUR
** Last update Fri Mar 21 16:11:31 2014 Kevin LOISELEUR
*/

#ifndef _CLIENT_H_
# define _CLIENT_H_

# define SIZE_BYTE	8
# define KILL_ERROR	-1
# define PAUSE		550

void		send_sig_bin(char c, int pid);
void		translate_msg(char **av, int pid);

#endif /* _CLIENT_H_ */
