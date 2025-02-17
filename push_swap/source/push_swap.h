/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:09:02 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/17 18:45:52 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libprintf/ft_printf.h"

typedef struct s_swap
{
	int				content;
	struct s_swap	*next;
} t_swap;

typedef struct s_data
{
	int				size_a;
	int				min;
} t_data;

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <limits.h>

t_swap	*fft_lstnew(int	content);
void	free_list(t_swap *swap);
void	print_lst(t_swap *swap);
void	free_one(t_swap **swap);
t_swap	*lastnode(t_swap **swap);
t_swap	*lastnode1(t_swap **swap);
int	sa(t_swap *swap);
int	sb(t_swap *swap);
int	ss(t_swap *a, t_swap *b);
int	pa(t_swap **a, t_swap **b);
int	pb(t_swap **a, t_swap **b);
int	ra(t_swap **swap);
int	rb(t_swap **swap);
int	rr(t_swap **a, t_swap **b);
int	rra(t_swap **swap);
int	rrb(t_swap **swap);
int	rrr(t_swap **a, t_swap **b);
int	fft_lstsize(t_swap *lst);
void	swap_conent(int *a, int *b);


#endif
