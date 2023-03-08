/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:51:26 by tanas             #+#    #+#             */
/*   Updated: 2023/03/08 19:03:55 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr1_handler(int signum)
{
	(void) signum;
	ft_printf("1");
}

void	sigusr2_handler(int signum)
{
	(void) signum;
	ft_printf("0");
}

// server
int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("SERVER PID: %i\n", pid);
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);
	while (1)
		pause();
}
