/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_pt1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:08:20 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/04 19:18:02 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*fft_lstnew(int	content)
{
	t_swap	*newnode;

	newnode = (t_swap *)malloc(sizeof(t_swap));
	if (newnode == NULL)
		return (NULL);
	newnode -> content = content;
	newnode -> next = NULL;
	return (newnode);
}
void	free_list(t_swap *swap)
{
	t_swap	*tmp;

	while(swap)
	{
		tmp = swap;
		swap = swap->next;
		free(tmp);
	}
}
void	free_one(t_swap *swap)
{
	t_swap	*tmp;

	tmp = swap;
	swap = swap->next;
	free(tmp);
}

void	print_lst(t_swap *swap)
{
	t_swap	*tmp;
	tmp = swap;
	while (tmp)
	{
		if(tmp->next == NULL)
		{
			ft_printf("%d\n",tmp -> content);
			break;
		}
		ft_printf("%d--",tmp -> content);
		tmp = tmp -> next;
	}
}

int	sa(t_swap *swap)
{
	int	tmp;

	if(!swap || !swap->next)
		return (-1);
	tmp = swap->next->content;
	swap->next->content = swap->content;
	swap->content = tmp;
	return (1);
}
int	sb(t_swap *swap)
{
	int	tmp;

	if(!swap || !swap->next)
		return (-1);
	tmp = swap->next->content;
	swap->next->content = swap->content;
	swap->content = tmp;
	return (1);
}
int	ss(t_swap *a, t_swap *b)
{
	if((sa(a) == 1) && (sb(b) == 1))
		return(1);
	else
		return (-1);
}
int	pa(t_swap *a, t_swap *b)
{
	t_swap	*new;
	// void	*tmp;

	new = fft_lstnew(a->content);
	free_one(a);
	// tmp = new;
	new->next = b;
	b = new;
	return(1);
}

int	main(void)
{
	t_swap	*head = fft_lstnew(1);
	t_swap	*h2 = fft_lstnew(2);
	t_swap	*h3 = fft_lstnew(3);
	t_swap	*h4 = fft_lstnew(4);

	t_swap	*head2 = fft_lstnew(5);
	t_swap	*h12 = fft_lstnew(6);
	t_swap	*h13 = fft_lstnew(7);
	t_swap	*h14 = fft_lstnew(8);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;

	head2->next = h12;
	h12->next = h13;
	h13->next = h14;

	// sa(head);
	// sb(head2);
	//ss(head, head2);
	pa(head, head2);
	print_lst(head);
	ft_printf("\n");
	print_lst(head2);
	free_list(head2);
	// free_list(head);
}
