/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:26:20 by ryagoub           #+#    #+#             */
/*   Updated: 2024/02/09 18:34:09 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverclient.h"

int	ft_putchar(int a)
{
	char	c;

	c = (char)a;
	write(1, &c, 1);
	return (1);
}

int	length(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		numlength;

	numlength = length(n);
	nb = n;
	if (nb < 0)
	{
		ft_putchar ('-');
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
	{
		ft_putchar(nb + '0');
	}
	return (numlength);
}
