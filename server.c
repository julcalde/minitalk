/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:57 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/21 13:39:39 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/include/printf/ft_printf.h"
#include "./libft.h"

void	bits_to_char(int bit)
{
	static unsigned char	c;
	static int				i;

	c = 0;
	i = 0;
	if (bit == SIGUSR1)
		c |= (0 << i);
	else if (bit == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write (1, &c, 1);
		if (c == '\0')
			write (1, '\n', 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Login to Server %d was successful.\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bits_to_char);
		signal(SIGUSR1, bits_to_char);
		pause();
	}
	return (0);
}
