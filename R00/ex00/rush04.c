/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 15:59:45 by chel-bou          #+#    #+#             */
/*   Updated: 2026/08/16 16:00:49 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	row_printer(int size, char first, char middle, char last)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0)
			ft_putchar(first);
		else if (i == size - 1)
			ft_putchar(last);
		else
			ft_putchar(middle);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x > 0 && y > 0)
	{
		i = 0;
		while (i < y)
		{
			if (i == 0)
				row_printer(x, 'A', 'B', 'C');
			else if (i == y - 1)
				row_printer(x, 'C', 'B', 'A');
			else
				row_printer(x, 'B', ' ', 'B');
			i++;
		}
	}
	else
		write(1, "ensure your inputs are correct\n", 31);
}
