/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:30:58 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/14 23:04:40 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_a(int pos_a)
{
	printf("(%d this is pos_a )\n", pos_a);
	//printf("(%d this is ls) ", ls_size);
	// if (pos_a > (ls_size / 2))
	// 	return(ls_size - pos_a);
	return (pos_a);
}

int	moves_b(int i, int ls_size)
{
	// printf("(%d this is index b) \n", i);
	printf("(%d this is ls) ", ls_size);
	if(i > (ls_size / 2))
		return(ls_size - i);
	return (i);
}

int	total_moves(t_swap *a, t_swap *b, int pos, int size_a, int size_b)
{
	int	count_a;
	int	count_b;
	int	pos_a;

	pos_a = index_a(a, b->content);
	count_a = pos_a;
	printf("%d count a\n", count_a);
	count_b = moves_b(pos, size_b);
	if (((pos < (size_b / 2)) && (pos_a < (size_a / 2))) || ((pos >= (size_b / 2)) && (pos_a >= (size_a / 2))))
	{
		if(count_a > count_b)
			return (count_a);
		return (count_b);
	}
	else
		return (count_a + count_b);
}

int	best_element(t_swap *a, t_swap *b)
{
	int	i;
	int	min_move;
	int	moves;
	int	index;
	t_swap	*tmp;
	int size_a = fft_lstsize(a);
	int size_b = fft_lstsize(b);

	tmp = b;
	min_move = INT_MAX;
	index = 0;
	i = 0;
	while(tmp)
	{
		moves = total_moves(a, tmp, i, size_a, size_b);
		printf("%d moves\n", moves);
		if(moves < min_move)
		{
			min_move = moves;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	printf("last moves selected %d\n", min_move);
	printf("%d\n", index);
	return (index);
}
void	movement_b(t_swap **b, int index)
{
	int size;

	ft_printf("index moveb %d\n", index);
	size = fft_lstsize(*b);
	if (index == 0)
		return;
	if (index >= (size / 2))
	{
		while(index < size)
		{
			rrb(b);
			index++;
		}
	}
	else
		{
			while(index > 0)
			{
				rb(b);
				index--;
			}
		}
	return ;
}
void	movement_a(t_swap **a, int pos_a)
{
	int size;

	size = fft_lstsize(*a);
	if(pos_a == 0)
		return ;
	if (pos_a >= size/ 2)
	{
		while(pos_a <= size)
		{
			rra(a);
			pos_a++;
		}
	}
	else
	{
		while(pos_a > 0)
		{
			ra(a);
			pos_a--;
		}
	}
		return ;
}
void	rr_movement(t_swap **a, t_swap ** b, t_data *d)
{
	while ((d->pos_a > 0 && d->index > 0) && ((d->pos_a < d->size_a / 2) && (d->index < d->size_b / 2)))
	{
		rr(a, b);
		d->pos_a--;
		d->index--;
	}
}
void rrr_movement(t_swap **a, t_swap **b, t_data *d)
{
	while ((d->pos_a > 0 && d->index > 0) && ((d->pos_a > d->size_a / 2) && (d->index > d->size_b / 2)))
	{
		rrr(a, b);
		d->pos_a--;
		d->index--;
	}
}


void	movement(t_swap **a, t_swap **b, t_data *d)
{
	t_swap	*tem;
	int	tmp;

	tmp = d->index;
	tem = *b;
	while(tmp > 0 && tem)
	{
		tem = tem->next;
		tmp--;
	}
	d->pos_a = index_a(*a, tem->content);
	if (((d->index < (d->size_b / 2)) && (d->pos_a < (d->size_a / 2))))
	rr_movement(a, b, d);
	else if (((d->index > (d->size_b / 2)) && (d->pos_a > (d->size_a / 2))))
	rrr_movement(a, b, d);
	movement_b(b, d->index);
	movement_a(a, d->pos_a);
	pa(a, b);
}
void	push_all(t_swap **a, t_swap **b)
{
	t_data	d;
	d.size_a = fft_lstsize(*a);
	d.size_b = fft_lstsize(*b);

	while(*b)
	{
		d.index = best_element(*a, *b);
		ft_printf("Before movement:\nA: ");
		print_lst(*a);
		ft_printf("\nB: ");
		print_lst(*b);
		ft_printf("\n");
		movement(a, b, &d);
		ft_printf("After movement:\nA: ");
		print_lst(*a);
		ft_printf("\nB: ");
		print_lst(*b);
		ft_printf("\n");
	}
}
void pb_only_two_a(t_swap **a, t_swap **b)
{
    while (*a && (*a)->next && (*a)->next->next)
    {
        pb(a, b);
    }
}
void	order_a(t_swap *a)
{
	t_swap	*tmp;

	tmp = a;
	if(tmp->content > tmp->next->content)
		sa(a);
	return;
}

int	main(void)
{
	t_swap *head = fft_lstnew(89);
	t_swap *h2 = fft_lstnew(104);
	t_swap *h3 = fft_lstnew(94);
	t_swap *h4 = fft_lstnew(52);
	t_swap *h5 = fft_lstnew(105);
	t_swap *h6 = fft_lstnew(90);
	t_swap *h7 = fft_lstnew(60);
	t_swap *h8 = fft_lstnew(123);
	t_swap *h9 = fft_lstnew(211);
	t_swap *h10 = fft_lstnew(315);
	t_swap *h11 = fft_lstnew(400);
	t_swap *h12 = fft_lstnew(5);
	t_swap *h13 = fft_lstnew(15);
	t_swap *h14 = fft_lstnew(2);
	t_swap *h15 = fft_lstnew(199);
	t_swap *h16 = fft_lstnew(278);
	t_swap *h17 = fft_lstnew(120);
	t_swap *h18 = fft_lstnew(7);
	t_swap *h19 = fft_lstnew(99);
	t_swap *h20 = fft_lstnew(56);

	t_swap *head2 = fft_lstnew(4);

	head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    h7->next = h8;
    h8->next = h9;
    h9->next = h10;
    h10->next = h11;
    h11->next = h12;
    h12->next = h13;
    h13->next = h14;
    h14->next = h15;
    h15->next = h16;
    h16->next = h17;
    h17->next = h18;
    h18->next = h19;
    h19->next = h20;

	// sa(head);
	//sb(head2);
	//ss(head, head2);
	//pa(&head, &head2);
	//pb(&head, &head2);
	//ra(&head);
	//rb(&head2);
	//rr(&head, &head2);
	//rra(&head);
	//rrr(&head, &head2);
	ft_printf("Before\n");
	print_lst(head);
	ft_printf("\n");
	print_lst(head2);
	ft_printf("After\n");
	pb_only_two_a(&head, &head2);
	order_a(head);
	push_all(&head, &head2);
	print_lst(head);
	ft_printf("\n");
	print_lst(head2);
	free_list(head2);
	free_list(head);
}
