/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operaciones.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:21:33 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/26 12:39:26 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list	**stack, char *op)
{
	t_list	*second;

	if (!stack || !(*stack))
		error();
	second = (*stack)-> next;
	(*stack)-> next = second -> next;
	second -> next = *stack;
	*stack = second;
	ft_printf("%s\n", op);
}

void	rotate(t_list **stack, char *op)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack))
		error();
	first = *stack;
	last = *stack;
	while (last -> next)
		last = last -> next;
	*stack = first -> next;
	first -> next = NULL;
	last -> next = first;
	if (op)
		ft_printf("%s\n", op);
}

void	rerotate(t_list **stack, char *op)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !(*stack))
		error();
	last = *stack;
	second_last = NULL;
	while (last -> next)
	{
		second_last = last;
		last = last -> next;
	}
	second_last -> next = NULL;
	last -> next = *stack;
	*stack = last;
	if (op)
		ft_printf("%s\n", op);
}

void	push(t_list **stack1, t_list **stack2, char *op)
{
	t_list	*first_node1;

	if (!stack1 || !(*stack1) || !stack2)
		error();
	first_node1 = *stack1;
	*stack1 = (*stack1)-> next;
	first_node1 -> next = *stack2;
	*stack2 = first_node1;
	ft_printf("%s\n", op);
}
