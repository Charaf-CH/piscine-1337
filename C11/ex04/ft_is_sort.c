/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <chel-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 18:15:01 by chel-bou          #+#    #+#             */
/*   Updated: 2026/09/02 21:03:59 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	decr;
	int	incr;

	i = 0;
	decr = 1;
	incr = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			decr = 0;
		i++;
	}
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			incr = 0;
		i++;
	}
	if (decr || incr)
		return (1);
	return (0);
}
