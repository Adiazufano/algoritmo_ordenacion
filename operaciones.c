/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operaciones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:42:47 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/30 20:42:55 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char *op)
{
	t_list	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = *stack;
	*stack = second;
	if (op)
		ft_printf("%s\n", op);
}

void	rotate(t_list **stack, char *op)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	if (op)
		ft_printf("%s\n", op);
}

void	rerotate(t_list **stack, char *op)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	if (!second_last)
		return ;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (op)
		ft_printf("%s\n", op);
}

void	push(t_list **stack1, t_list **stack2, char *op)
{
	t_list	*first_node1;

	if (!stack1 || !(*stack1) || !stack2)
		return ;
	first_node1 = *stack1;
	*stack1 = (*stack1)->next;
	first_node1->next = *stack2;
	*stack2 = first_node1;
	if (op)
		ft_printf("%s\n", op);
}
