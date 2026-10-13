/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <chel-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 20:14:04 by chel-bou          #+#    #+#             */
/*   Updated: 2026/09/02 21:08:04 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include <unistd.h>

char	ft_get_operator(char *str)
{
	if (str[0] && str[1] == '\0')
	{
		if (str[0] == '+')
			return ('+');
		if (str[0] == '-')
			return ('-');
		if (str[0] == '*')
			return ('*');
		if (str[0] == '/')
			return ('/');
		if (str[0] == '%')
			return ('%');
	}
	return (0);
}

int	ft_solve(int a, int b, char c)
{
	if (c == '+')
		return (ft_add(a, b));
	if (c == '-')
		return (ft_sub(a, b));
	if (c == '*')
		return (ft_mul(a, b));
	if (c == '/')
		return (ft_div(a, b));
	if (c == '%')
		return (ft_mod(a, b));
	return (0);
}

int	ft_check_error(char op, int b)
{
	if (op == '/' && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	if (op == '%' && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	int		result;
	char	op;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	op = ft_get_operator(argv[2]);
	if (op == 0)
	{
		ft_putnbr(0);
		write(1, "\n", 1);
		return (0);
	}
	if (ft_check_error(op, b))
		return (0);
	result = ft_solve(a, b, op);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
