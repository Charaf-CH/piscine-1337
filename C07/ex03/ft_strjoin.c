/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <chel-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 12:05:26 by chel-bou          #+#    #+#             */
/*   Updated: 2026/08/25 12:05:30 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	word_copy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

int	total_len(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += ft_strlen(sep);
		i++;
	}
	return (len);
}

char	*empty_join(void)
{
	char	*join;

	join = malloc(1);
	if (!join)
		return (NULL);
	join[0] = '\0';
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*join;

	if (size == 0)
		return (empty_join());
	join = malloc(total_len(size, strs, sep) + 1);
	if (!join)
		return (NULL);
	j = 0;
	i = 0;
	while (i < size)
	{
		j += word_copy(&join[j], strs[i]);
		if (i < size - 1)
			j += word_copy(&join[j], sep);
		i++;
	}
	join[j] = '\0';
	return (join);
}
