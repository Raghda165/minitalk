/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverclient.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:18:04 by ryagoub           #+#    #+#             */
/*   Updated: 2024/02/15 14:44:33 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERCLIENT_H
# define SERVERCLIENT_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <signal.h>
# include <limits.h>

int		ft_putnbr(int n);
int		ft_atoi(const char *str);
int		ft_putchar(int a);
size_t	ft_strlen(const char *s);

#endif
