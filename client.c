/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:43:39 by tanas             #+#    #+#             */
/*   Updated: 2023/03/06 18:52:12 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// client
int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 2)
	{
		printf("\033[1;3;31m\nError! Invalid number of arguments entered.\n\n");
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
}
