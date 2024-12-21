/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:14:55 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/21 13:33:06 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/include/printf/ft_printf.h"
#include "./libft.h"

void	send_bit(int pid, char *str)
{
	size_t	byte_arr_i;
	int		i;

	i = 0;
	while (i < ft_strlen(str))
	{
		byte_arr_i = 0;
		while (byte_arr_i <= 7)
		{
			if ((str[i] >> byte_arr_i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			byte_arr_i++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_bit(pid, argv[2]);
	}
	else
	{
		ft_printf("Please enter only one word");
	}
	return (0);
}
