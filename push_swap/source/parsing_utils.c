/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:47:34 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/26 17:39:47 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char **matrix, int f)
{
	int	i;
	int	j;

	j = 0;
	while (matrix[j])
	{
		i = 0;
		if (matrix[j][i] == '+' || matrix[j][i] == '-')
			i++;
		while (matrix[j][i])
		{
			if (matrix[j][i] >= '0' && matrix[j][i] <= '9')
				i++;
			else
			{
				if (f == 1)
					write(2, "ERROR\n", 6);
				return (0);
			}
		}
		j++;
	}
	return (1);
}

int	duplicates(char **matrix, int f)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = i + 1;
		while (matrix[j])
		{
			if (ft_atoi(matrix[i]) == ft_atoi(matrix[j]))
			{
				if (f == 1)
					write(2, "ERROR\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	**two_args(char *argv, int i)
{
	char	**matrix;

	matrix = ft_split(argv, 32);
	if (check_arg(matrix, i) == 0 || duplicates(matrix, i) == 0)
		return (free_mat(matrix), NULL);
	return (matrix);
}

char	**more_args(int argc, char **av, int f)
{
	int		j;
	int		i;
	char	**matrix;

	i = 1;
	j = 0;
	matrix = malloc((argc) * sizeof(char *));
	if (!matrix)
		return (NULL);
	while (i < argc)
	{
		matrix[j] = ft_strdup(av[i]);
		if (!matrix[j])
			return (free_mat(matrix), NULL);
		i++;
		j++;
	}
	matrix[j] = NULL;
	if (check_arg(matrix, f) == 0 || duplicates(matrix, f) == 0)
		return (free_mat(matrix), NULL);
	return (matrix);
}

t_swap	*lstcreation(char **matrix)
{
	int		i;
	long	check;
	t_swap	*new_node;
	t_swap	*head;

	i = 0;
	new_node = NULL;
	while (matrix[i])
	{
		check = ft_atoi(matrix[i]);
		if (check > INT_MAX || check < INT_MIN)
			return (free_mat(matrix), free_list(head),
				ft_printf("ERROR\n"), NULL);
		new_node = fft_lstnew((int)check);
		if (!new_node)
			return (free_mat(matrix), free_list(head), NULL);
		if (i == 0)
			head = new_node;
		else
			fft_lstadd_back(&head, new_node);
		i++;
	}
	free_mat(matrix);
	return (head);
}
