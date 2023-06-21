/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:45:25 by damachad          #+#    #+#             */
/*   Updated: 2023/06/21 15:11:13 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*Builds the character to be printed from the received bits*/

static void	handler(int sign)
{
	static int	bit;
	static int	character;

	if (sign == SIGUSR1)
		character += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(character, 1);
		bit = 0;
		character = 0;
	}
}

/*Print the process ID and wait for signals indefinitely*/

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
