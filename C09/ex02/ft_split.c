/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <chel-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 11:41:25 by chel-bou          #+#    #+#             */
/*   Updated: 2026/08/31 12:33:40 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_sep(str[i], charset))
			i++;
	}
	return (count);
}

int	word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	return (len);
}

char	*word_copy(char *str, char *charset)
{
	char	*word;
	int		i;
	int		len;

	len = word_len(str, charset);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		wc;
	int		len;
	int		i;

	wc = count_words(str, charset);
	split = malloc(sizeof(char *) * (wc + 1));
	if (!split)
		return (NULL);
	i = 0;
	len = 0;
	while (str[len] && is_sep(str[len], charset))
		len++;
	while (str[len])
	{
		split[i] = word_copy(&str[len], charset);
		if (!split[i])
			return (NULL);
		len += word_len(&str[len], charset);
		while (str[len] && is_sep(str[len], charset))
			len++;
		i++;
	}
	split[i] = NULL;
	return (split);
}
