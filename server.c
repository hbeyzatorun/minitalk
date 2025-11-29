/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorun <htorun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:44:40 by htorun            #+#    #+#             */
/*   Updated: 2025/11/22 14:44:42 by htorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_counter;

void	go_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	character;

	(void)context;
	if (signal == SIGUSR2)
		character |= (1 << g_counter);
	g_counter++;
	if (g_counter == 8)
	{
		if (character == '\0')
			ft_putchar('\n');
		else
			ft_putchar(character);
		character = 0;
		g_counter = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	server_pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(server_pid);
	ft_putchar('\n');
	sa.sa_sigaction = go_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
