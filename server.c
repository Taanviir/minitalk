/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:51:26 by tanas             #+#    #+#             */
/*   Updated: 2023/03/14 18:27:34 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	SIGUSR1 == 1;
	SIGUSR2 == 0;

	Need sigaction for acknowledgment that I received the characters
*/

static void	sigusr_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bits = 0;

	(void) context;
	c |= (signum == SIGUSR1);
	// ft_printf("%c\n", c);
	// if (signum == SIGUSR1)
	// 	printf("1\n");
	// else
	// 	printf("0\n");
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		// ft_printf("%i", c);
		bits = 0;
		c = 0;
		kill(info->si_pid, SIGUSR2);
	}
	c <<= 1;
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
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sigusr_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf(B_CYAN"SERVER PID: %i\n"RESET, getpid());
	while (1)
		pause();
}
