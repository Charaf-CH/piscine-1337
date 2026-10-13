/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 18:43:01 by chel-bou          #+#    #+#             */
/*   Updated: 2026/08/13 20:20:46 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int	ft_is_alphanumeric(char c)
{
	if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	ft_strlowcase(str);
	while (str[i])
	{
		if (ft_is_alphanumeric(str[i]) && flag == 1)
		{
			flag = 0;
			if ((str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
		}
		if (!(ft_is_alphanumeric(str[i])))
			flag = 1;
		i++;
	}
	return (str);
}
