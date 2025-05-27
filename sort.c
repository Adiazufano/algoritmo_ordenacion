/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:01:12 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/27 09:29:06 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack -> next;
	}
	return (size);
}

void	sort_size_2(t_list **stack_a, char *op)
{
	if (!isordered((*stack_a)))
		swap(stack_a, op);
}

void	sort_size_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = get_content((*stack_a));
	second = get_content((*stack_a)-> next);
	third = get_content((*stack_a)->next->next);
	if (!isordered((*stack_a)))
	{
		if (first > third && first > second && second > third)
			(rotate(stack_a, "ra"), swap(stack_a, "sa"));
		else if (first > second && first > third)
			rerotate(stack_a, "rra");
		else if (first > third)
			rotate(stack_a, "ra");
		else if (second > third)
			(rerotate(stack_a, "rra"), swap(stack_a, "sa"));
		else
			swap(stack_a, "sa");
	}
}

void	sort_size_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*last;
	temp = *stack_a;
	while (temp -> next)
	{
		last = temp;
		temp = temp -> next;
	}
	if (get_content(*stack_a) > get_content(temp))
		rerotate(stack_a, "rra");
	if (get_content((*stack_a) -> next) > get_content(last))
		rerotate(stack_a, "rra");
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
	if (!isordered((*stack_a)))
		sort_size_3(stack_a);
	ft_printf("%d\n", isordered(*stack_b));
	push(stack_b, stack_a, "pb");
	push(stack_b, stack_a, "pb");
	if (get_content(*stack_a) > get_content((*stack_a) -> next))
		swap(stack_a, "sa");
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (list_size((*stack_a)) == 2 || list_size(*stack_b) == 2)
		sort_size_2(stack_a, "sb");
	else if (list_size(*stack_a) == 3 || list_size(*stack_b) == 3)
		sort_size_3(stack_a);
	else if (list_size(*stack_a) == 5 || list_size(*stack_b) == 5)
		sort_size_5(stack_a, stack_b);
}
