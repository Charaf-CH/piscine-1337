/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 20:26:51 by chel-bou          #+#    #+#             */
/*   Updated: 2026/08/16 20:05:22 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*cp_str;
	char	*cp_to_find;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			cp_str = str;
			cp_to_find = to_find;
			while (*cp_str && *cp_to_find && *cp_str == *cp_to_find)
			{
				cp_str++;
				cp_to_find++;
			}
			if (*cp_to_find == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
