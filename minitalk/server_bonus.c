/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:45:08 by ryagoub           #+#    #+#             */
/*   Updated: 2024/02/15 12:44:53 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverclient.h"

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int				i;

	i = 8;
	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	c;
	static int	bits;
	pid_t		pid;

	pid = info ->si_pid;
	context = NULL;
	if (sig == SIGUSR1 && bits <= 7)
	{
		c = c |(0x01 << bits);
	}
	bits++;
	if (bits == 8)
	{
		c = reverse_bits((unsigned char)c);
		ft_putchar(c);
		if (c == 0)
		{
			ft_putchar('\n');
			kill(pid, SIGUSR1);
		}
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = &handle_signal;
	action.sa_flags = SA_SIGINFO;
	write (1, "this is the server process id: ", 32);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		sleep(1);
	}
}
