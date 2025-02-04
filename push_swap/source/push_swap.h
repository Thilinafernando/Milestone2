/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:09:02 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/04 18:34:37 by tkurukul         ###   ########.fr       */
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

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>

t_swap	*fft_lstnew(int	content);
int	sa(t_swap *swap);
void	free_list(t_swap *swap);
void	print_lst(t_swap *swap);

#endif
