/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <chel-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 16:41:31 by chel-bou          #+#    #+#             */
/*   Updated: 2026/08/23 16:41:42 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	get_col(int grid[4][4], int col, int line[4]);
void	get_row(int grid[4][4], int row, int line[4]);

int	count_visible_left(int line[4])
{
	int	max_seen;
	int	visible;
	int	i;

	max_seen = line[0];
	visible = 1;
	i = 1;
	while (i < 4)
	{
		if (line[i] > max_seen)
		{
			max_seen = line[i];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	count_visible_right(int line[4])
{
	int	max_seen;
	int	visible;
	int	i;

	max_seen = line[3];
	visible = 1;
	i = 2;
	while (i >= 0)
	{
		if (line[i] > max_seen)
		{
			max_seen = line[i];
			visible++;
		}
		i--;
	}
	return (visible);
}

int	check_row_clues(int grid[4][4], int row, int clues[16])
{
	int	line[4];
	int	left;
	int	right;

	get_row(grid, row, line);
	left = count_visible_left(line);
	right = count_visible_right(line);
	if (left != clues[8 + row])
		return (0);
	if (right != clues[12 + row])
		return (0);
	return (1);
}

int	check_col_clues(int grid[4][4], int col, int clues[16])
{
	int	line[4];
	int	top;
	int	bottom;

	get_col(grid, col, line);
	top = count_visible_left(line);
	bottom = count_visible_right(line);
	if (top != clues[col])
		return (0);
	if (bottom != clues[4 + col])
		return (0);
	return (1);
}

int	check_all_clues(int grid[4][4], int clues[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_row_clues(grid, i, clues))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (!check_col_clues(grid, i, clues))
			return (0);
		i++;
	}
	return (1);
}
