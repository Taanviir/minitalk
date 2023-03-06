/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:53:48 by tanas             #+#    #+#             */
/*   Updated: 2022/11/16 15:13:45 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*string;

	i = 0;
	string = (const char *) s;
	while (n--)
	{
		if (string[i] == (char) c)
			return ((void *) &s[i]);
		i++;
	}
	return (0);
}
