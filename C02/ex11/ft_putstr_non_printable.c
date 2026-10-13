/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:16:20 by chel-bou          #+#    #+#             */
/*   Updated: 2026/08/13 22:13:48 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_non_printable(char c)
{
	if (!(c >= 32 && c <= 126))
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		ascii;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (ft_str_is_non_printable(str[i]))
		{
			write(1, "\\", 1);
			ascii = str[i];
			ft_putchar(hex[ascii / 16]);
			ft_putchar(hex[ascii % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
