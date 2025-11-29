/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorun <htorun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:44:01 by htorun            #+#    #+#             */
/*   Updated: 2025/11/22 14:44:03 by htorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_send_signal;

void	send_signal_true(int signal)
{
	if (signal == SIGUSR1)
		g_send_signal = 1;
}

void	ft_send_c(pid_t server_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_send_signal = 0;
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		while (g_send_signal == 0)
			usleep(100);
		bit++;
	}
}

void	ft_send_string(pid_t server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_c(server_pid, str[i]);
		i++;
	}
	ft_send_c(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
		error_exit("Please use a valid PID value");
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 1 || server_pid > 4194304)
		error_exit("Error");
	if (ft_strlen(argv[1]) > 7)
		error_exit("Error valid");
	signal(SIGUSR1, send_signal_true);
	ft_send_string(server_pid, argv[2]);
	return (0);
}
