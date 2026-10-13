/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <chel-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 18:08:00 by chel-bou          #+#    #+#             */
/*   Updated: 2026/08/23 18:08:03 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int grid[4][4], int row, int col, int num);
int	is_complete(int grid[4][4]);
int	check_all_clues(int grid[4][4], int clues[16]);
int	solve(int grid[4][4], int clues[16]);

int	try_numbers(int grid[4][4], int clues[16], int row, int col)
{
	int	num;

	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, clues))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	solve(int grid[4][4], int clues[16])
{
	int	row;
	int	col;

	if (is_complete(grid))
		return (check_all_clues(grid, clues));
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (grid[row][col] == 0)
				return (try_numbers(grid, clues, row, col));
			col++;
		}
		row++;
	}
	return (0);
}
