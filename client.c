/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:45:15 by damachad          #+#    #+#             */
/*   Updated: 2023/06/20 12:49:41 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*Send message, character by character, bit by bit.
Iterate through each bit of the current character. 
If the current bit is 1, send SIGUSR1, else (bit is 0) send SIGUSR2.
Sleep for 100 miliseconds between each signal.*/

void	send_bits(char c, int server_pid)
{
	int	bit;
	int	z;

	bit = 0;
	z = 128;
	while (bit < 8)
	{
		if (c & z)
		{	
			if (kill(server_pid, SIGUSR1) == -1)
				ft_printf("Error. Failed to send SIGUSR1.\n");
		}
		else
		{	
			if (kill(server_pid, SIGUSR2) == -1)
				ft_printf("Error. Failed to send SIGUSR2.\n");
		}
		z >>= 1;
		bit++;
		usleep(100);
	}	
}

/*Process and validate number of arguments and send the message to the
send_bits function*/

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_bits(argv[2][i], server_pid);
			i++;
		}
		send_bits('\n', server_pid);
	}
	else
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Usage: ./client [server PID] [message]\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
