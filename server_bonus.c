/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:45:25 by damachad          #+#    #+#             */
/*   Updated: 2023/06/29 15:21:07 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/*Build the character to be printed from the received bits, based on the signal.
When the whole message is received, send a signal to client.*/

void	handler(int signo, siginfo_t *info, void *context)
{
	static int	bit;
	static char	character;

	(void)context;
	if (signo == SIGUSR1)
		character += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		if (character == '\0')
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_printf("Error. Failed to send SIGUSR1\n");
		}
		if (character != '\0')
		{	
			ft_putchar_fd(character, 1);
			kill(info->si_pid, SIGUSR2);
		}
		bit = 0;
		character = 0;
	}
}

/*Print the process ID and wait for signals indefinitely*/

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error. Failed to set up signal handling for SIGUSR1\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error. Failed to set up signal handling for SIGUSR2\n");
		return (2);
	}
	while (1)
		pause();
	return (0);
}
