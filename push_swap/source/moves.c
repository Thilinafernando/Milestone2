/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:30:58 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/09 21:31:31 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_a(t_swap *a, int pos_a)
{
	int	ls_size;

	ls_size = fft_lstsize(a);
	if (pos_a > (ls_size / 2))
		return(ls_size - pos_a);
	return (pos_a);
}

int	moves_b(t_swap *b, int i)
{
	int	ls_size;

	ls_size = fft_lstsize(b);
	if(i > (ls_size / 2))
		return(ls_size - i);
	return (i);
}

int	total_moves(t_swap *a, t_swap *b, int pos)
{
	int	count_a;
	int	count_b;
	int	pos_a;
	int	size_a;
	int	size_b;

	size_a = fft_lstsize(a);
	size_b = fft_lstsize(b);
	pos_a = index_a(a, b->content);
	count_a = moves_a(a, pos_a);
	count_b = moves_b(b, pos);
	if (((pos < (size_b / 2)) && (pos_a < (size_a / 2))) || ((pos >= (size_b / 2)) && (pos_a >= (size_a / 2))))
	{
		if(count_a > count_b)
			return (count_a);
		return (count_b);
	}
	return (count_a + count_b);
}
