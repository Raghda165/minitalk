/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:41:54 by ryagoub           #+#    #+#             */
/*   Updated: 2024/02/15 15:00:48 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serverclient.h"

void	do_action(int sig)
{
	if (sig == SIGUSR1)
		write(1, "The message had been recived\n", 30);
}

void	convert_to_bits(int pid, char *str)
{
	size_t	i;
	int		b;
	int		bit;
	size_t	len;

	i = 0;
	b = 7;
	len = ft_strlen(str);
	signal(SIGUSR1, do_action);
	while (i <= len)
	{
		b = 7;
		while (b >= 0)
		{
			bit = (str[i] >> b & 1);
			if (bit == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			b--;
			usleep(500);
		}
		i++;
	}
}

int	check_for_errors(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if ((!check_for_errors(av[1])) || (ft_atoi(av[1]) == 0))
		{
			write(1, "invalid process id\n", 20);
			return (0);
		}
		if (av[2][0] == '\0')
		{
			write(1, "there is no message to be sent\n", 31);
			return (0);
		}
		if (check_for_errors(av[1]) && av[2])
			convert_to_bits(ft_atoi(av[1]), av[2]);
	}
	else
		write(1, "number of arguments is not two\n", 32);
	return (0);
}
