/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:30:58 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/10 22:09:59 by tkurukul         ###   ########.fr       */
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

int	best_element(t_swap *a, t_swap *b)
{
	int	i;
	int	min_move;
	int	moves;
	int	index;
	t_swap	*tmp;

	tmp = b;
	min_move = total_moves(a, b, 0);
	index = 0;
	i = 0;
	while(tmp)
	{
		moves = total_moves(a, b, i);
		if(moves < min_move)
		{
			min_move = moves;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (index);
}
void	movement_b(t_swap *b, int index)
{
	if (index != 0)
	{
		if (index > (fft_lstsize(b) / 2))
		{
			index = (fft_lstsize(b) - index);
			while(index > 0)
			{
				rrb(&b);
				index--;
			}
		}
		else
		{
			while(index > 0)
			{
				rb(&b);
				index--;
			}
		}
	}
	else if (index == 1)
		sb(b);
	return ;
}
void	movement_a(t_swap *a, int pos_a)
{
	if (pos_a != 0)
	{
		if (pos_a > (fft_lstsize(a) / 2))
		{
			while(pos_a > 0)
			{
				rra(&a);
				pos_a--;
			}
		}
		else
		{
			while(pos_a > 0)
			{
				ra(&a);
				pos_a--;
			}
		}
	}
	else if (pos_a == 1)
		sa(a);
	return ;
}

void	movement(t_swap *a, t_swap *b, int index)
{
	int	pos_a;
	t_swap	*tem;
	int	tmp;

	tmp = index;
	tem = b;
	while(tmp > 0 && tem)
	{
		tem = tem->next;
		tmp--;
	}
	pos_a = index_a(a, tem->content);
	movement_b(b, index);
	movement_a(a, pos_a);
	pb(&a, &b);
}

int	main(void)
{
	t_swap	*head = fft_lstnew(89);
	t_swap	*h2 = fft_lstnew(74);
	t_swap	*h3 = fft_lstnew(88);
	t_swap	*h4 = fft_lstnew(52);
	t_swap	*h5 = fft_lstnew(104);
	t_swap	*h6 = fft_lstnew(90);
	t_swap	*h7 = fft_lstnew(60);
	t_swap	*h8 = fft_lstnew(82);

	t_swap	*head2 = fft_lstnew(0);
	t_swap	*h12 = fft_lstnew(69);
	t_swap	*h13 = fft_lstnew(85);
	t_swap	*h14 = fft_lstnew(100);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = h7;
	h7->next = h8;

	head2->next = h12;
	h12->next = h13;
	h13->next = h14;

	t_swap *tmp1 = head;
	t_swap *tmp2 = head2;
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
	int	index = best_element(head, head2);
	movement(tmp1, tmp2, index);
	print_lst(head);
	ft_printf("\n");
	print_lst(head2);
	//free_list(head2);
	free_list(head);
}
