/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:41:48 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/26 12:39:45 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack1, t_list **stack2)
{
	if (!stack1 || !stack2)
		error();
	swap(stack1, NULL);
	swap(stack2, NULL);
	ft_printf("ss\n");
}

void	rr(t_list **stack1, t_list **stack2)
{
	if (!stack1 || !stack2)
		error();
	rotate(stack1, NULL);
	rotate(stack2, NULL);
	ft_printf("rr\n");
}

void	rrr(t_list **stack1, t_list **stack2)
{
	if (!stack1 || !stack2)
		error();
	rerotate(stack1, NULL);
	rerotate(stack2, NULL);
	ft_printf("rrr\n");
}
