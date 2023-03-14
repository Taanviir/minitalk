/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:43:39 by tanas             #+#    #+#             */
/*   Updated: 2023/03/14 17:00:17 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_strlen;

static void	sigusr1_handler(int signum)
{
	static int	char_count;

	char_count = 0;
	if (signum == SIGUSR1)
		char_count++;
	if (char_count == g_strlen)
	{
		ft_printf(B_GREEN"Success!\nCharacters Received: %i\n"RESET, char_count);
		exit(3);
	}
}

static void	send_signal(int pid, char *message)
{
	int	i;
	int	bitshift;

	i = -1;
	while (message[++i])
	{
		bitshift = 8;
		while (--bitshift >= 0)
		{
			if (message[i] & (1 << bitshift))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep (100);
		}
	}
}

// client
int	main(int argc, char **argv)
{
	pid_t				pid;

	if (argc != 3)
	{
		ft_printf(BI_RED"\nError! Invalid number of arguments entered.\n\n"RESET);
		exit(0);
	}
	if (!argv[2])
	{
		ft_printf(BI_RED"Error! Empty string entered.\n"RESET);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	g_strlen = ft_strlen(argv[2]);
	send_signal(pid, argv[2]);
	send_signal(pid, "\n");
	signal(SIGUSR1, sigusr1_handler);
}
