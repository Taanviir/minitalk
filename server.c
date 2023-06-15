/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:51:26 by tanas             #+#    #+#             */
/*   Updated: 2023/06/15 15:58:09 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	SIGUSR1 == 1;
	SIGUSR2 == 0;
*/

static void	sigusr_handler(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	bits;

	(void) context;
	(void) info;
	c |= (signum == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		bits = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	c <<= 1;
	if (signum == SIGINT)
	{
		ft_printf(B_MAGENTA"\nServer shutting down.\n"RESET);
		exit(4);
	}
}

// server
int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void) argv;
	if (argc != 1)
	{
		ft_printf(BI_RED"\nError! Invalid number of arguments entered.\n\n"RESET);
		exit(0);
	}
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sigusr_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGINT, &act, NULL);
	ft_printf(B_CYAN"SERVER PID: %i\n"RESET, getpid());
	while (1)
		pause();
}
