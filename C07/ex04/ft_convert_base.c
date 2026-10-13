/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <chel-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 13:07:14 by chel-bou          #+#    #+#             */
/*   Updated: 2026/08/26 13:47:25 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		base_checker(char *base);
int		ft_atoi_base(char *str, char *base);
int		count_digits(int nbr, int base_len);

char	*ft_itoa_base(int nbr, char *base)
{
	int		base_len;
	int		len;
	char	*str;
	long	n;

	base_len = ft_strlen(base);
	len = count_digits(nbr, base_len);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	n = nbr;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = base[0];
	while (n > 0)
	{
		str[--len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		value;
	char	*result;

	if (!base_checker(base_from) || !base_checker(base_to))
		return (NULL);
	value = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(value, base_to);
	return (result);
}
