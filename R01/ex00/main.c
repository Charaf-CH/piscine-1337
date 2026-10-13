/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chel-bou <chel-bou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 18:08:42 by chel-bou          #+#    #+#             */
/*   Updated: 2026/08/23 18:08:48 by chel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		parse_input(char *str, int clues[16]);
void	init_grid(int grid[4][4]);
int		solve(int grid[4][4], int clues[16]);
void	print_grid(int grid[4][4]);

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	clues[16];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!parse_input(argv[1], clues))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_grid(grid);
	if (solve(grid, clues))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
