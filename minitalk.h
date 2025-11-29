/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorun <htorun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:44:27 by htorun            #+#    #+#             */
/*   Updated: 2025/11/22 14:44:29 by htorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <asm-generic/signal-defs.h>
# include <sched.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	error_exit(char *error);
int		ft_strlen(char *str);

#endif
