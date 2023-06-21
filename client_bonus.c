/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:45:15 by damachad          #+#    #+#             */
/*   Updated: 2023/06/21 15:52:20 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/*Send specific character, bit by bit.
Iterate through each bit of the current character and uses the bitwise AND 
operator to check its value. If the current bit is 1, send SIGUSR1, else 
(bit is 0) send SIGUSR2. Sleep for 400 miliseconds between each signal.*/

void	send_char(int server_pid, char c)
{
	int	bit;
	int	z;

	bit = 0;
	z = 128;
	while (bit++ < 8)
	{
		if (c & z)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_printf("Error: Unable to send SIGUSR1.\n");
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_printf("Error: Unable to send SIGUSR2.\n");
		}
		z >>= 1;
		usleep(400);
	}
}

/*Send message, character by character, bit by bit.
Iterate through each bit of the current character and uses the bitwise AND 
operator to check its value. If the current bit is 1, send SIGUSR1, else 
(bit is 0) send SIGUSR2. Sleep for 400 miliseconds between each signal.*/

void	send_bits(int server_pid, char *msg)
{
	int	bit;
	int	z;

	while (*msg)
	{
		bit = 0;
		z = 128;
		while (bit++ < 8)
		{
			if (*msg & z)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			z >>= 1;
			usleep(400);
		}
		msg++;
	}
	if (!*msg)
	{
		send_char(server_pid, '\n');
		send_char(server_pid, '\0');
	}
}

/*Create a counter for every character printed and, when 
full message is received by the server, print the counter*/

void	handler(int sign)
{
	static int	count;

	if (sign == SIGUSR1)
	{
		ft_printf("Message received.\n%d characters printed.\n", (count - 1));
		exit(0);
	}
	else
		count++;
}

/*Validate number of arguments and send the message to the send_bits function*/

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					server_pid;

	if (argc == 3)
	{
		sa.sa_handler = &handler;
		sa.sa_flags = SA_SIGINFO;
		server_pid = ft_atoi(argv[1]);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_bits(server_pid, argv[2]);
	}
	else
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Usage: ./client [server PID] [message]\n");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
