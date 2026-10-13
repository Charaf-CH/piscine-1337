/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <chel-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 18:44:00 by chel-bou          #+#    #+#             */
/*   Updated: 2026/08/23 18:44:16 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	if (*str >= '1' && *str <= '4')
		return (*str - '0');
	return (-1);
}

int	parse_input(char *str, int clues[16])
{
	int	i;
	int	count;
	int	value;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (count == 16)
			return (0);
		value = ft_atoi(&str[i]);
		if (value == -1)
			return (0);
		clues[count] = value;
		count++;
		i++;
		if (str[i] == '\0')
			break ;
		if (str[i] != ' ')
			return (0);
		i++;
	}
	if (count != 16)
		return (0);
	return (1);
}

void	get_col(int grid[4][4], int col, int line[4])
{
	int	row;

	row = 0;
	while (row < 4)
	{
		line[row] = grid[row][col];
		row++;
	}
}

void	get_row(int grid[4][4], int row, int line[4])
{
	int	col;

	col = 0;
	while (col < 4)
	{
		line[col] = grid[row][col];
		col++;
	}
}

void	init_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}
