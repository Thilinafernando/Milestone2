/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:57:58 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/17 18:52:17 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_swap **a)
{
	t_swap *tmp;

	tmp = *a;
	while(tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return(0);
		tmp = tmp->next;
	}
	return (1);
}

void	radix_sort(t_swap **a, t_swap **b, t_data *d)
{
	int	i;
	int	j;
	int	negative;

	i = 0;
	negative = 0;
	if(d->min < 0)
		negative = -d->min;
	while(!is_sorted(a))
	{
		j = 0;
		while (j <= d->size_a)
		{
			if ((((*a)->content + negative) >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
