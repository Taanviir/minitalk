/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:43:39 by tanas             #+#    #+#             */
/*   Updated: 2023/03/08 19:06:29 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// client
int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_printf("\033[1;3;31m\nError! Invalid number of arguments entered.\n\n");
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	int i = -1;
	while (++i < 8)
	{
		if (argv[2][0] & 0x01 << i)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(3);
	}
}
