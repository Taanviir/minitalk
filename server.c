/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:51:26 by tanas             #+#    #+#             */
/*   Updated: 2023/03/06 18:51:36 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	ft_printf("signal %i from client received\n", signum);
}

// server
int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %i\n", pid);
	signal_handler(SIGUSR1);
	for (;;)
		pause();
	return (0);
}
