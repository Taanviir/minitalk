/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:43:39 by tanas             #+#    #+#             */
/*   Updated: 2023/03/15 20:10:53 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_strlen;

static pid_t	check_pid(char *pid_c)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (pid_c[++i])
	{
		if (! ((pid_c[i] >= '0') && (pid_c[i] <= '9')))
		{
			ft_printf(BI_RED"\nError! Invalid PID entered.\n\n"RESET);
			exit(1);
		}
	}
	pid = ft_atoi(pid_c);
	if (pid <= 0 || pid >= 100000)
	{
		ft_printf(BI_RED"\nError! Invalid PID entered.\n\n"RESET);
		exit(2);
	}
	return (pid);
}

static void	sigusr1_handler(int signum, siginfo_t *info, void *context)
{
	static int	char_count;

	(void) context;
	(void) info;
	if (signum == SIGUSR1)
		char_count++;
	if (char_count == g_strlen)
	{
		ft_printf(B_GREEN \
			"Message sent successfully!\nTotal Characters Received: %i\n" \
				RESET, char_count);
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
	struct sigaction	act;

	if (argc != 3)
	{
		ft_printf(BI_RED"\nError! Invalid number of arguments entered.\n\n"RESET);
		exit(0);
	}
	if (!argv[2][0])
	{
		ft_printf(BI_RED"\nError! Empty string entered.\n\n"RESET);
		exit(0);
	}
	pid = check_pid(argv[1]);
	g_strlen = ft_strlen(argv[2]);
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sigusr1_handler;
	sigaction(SIGUSR1, &act, NULL);
	send_signal(pid, argv[2]);
}
