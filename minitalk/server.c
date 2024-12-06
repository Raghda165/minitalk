/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:16:02 by ryagoub           #+#    #+#             */
/*   Updated: 2024/02/15 14:53:23 by ryagoub          ###   ########.fr       */
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

void	handle_signal(int sig)
{
	static int	c;
	static int	bits;

	if (sig == SIGUSR1 && bits <= 7)
	{
		c = c |(1 << bits);
	}
	bits++;
	if (bits == 8)
	{
		c = reverse_bits((unsigned char)c);
		ft_putchar(c);
		if (c == 0)
		{
			ft_putchar('\n');
		}
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	write (1, "this is the server process id: ", 32);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		sleep(1);
	}
}
