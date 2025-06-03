/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:01:12 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/30 23:00:21 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (first > second && second > third)
			(swap(stack_a, "sa"), rerotate(stack_a, "rra"));
		else if (first > second && second < third && third < first)
			(rerotate(stack_a, "rra"), rerotate(stack_a, "rra"));
		else if (first > second && second < third && third > first)
			swap(stack_a, "sa");
		else if (first < second && second > third && third < first)
			rerotate(stack_a, "rra");
		else if (first < second && second > third && third > first)
			(rerotate(stack_a, "rra"), swap(stack_a, "sa"));
	}
}

void	sort_size_5(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	i;

	i = 0;
	min = find_min((*stack_a));
	while (i < 2)
	{
		min = find_min(*stack_a);
		while (get_content(*stack_a) != min)
			rotate(stack_a, "ra");
		push(stack_a, stack_b, "pb");
		i++;
	}
	if (ft_lstsize(*stack_a) == 3)
		sort_size_3(stack_a);
	else
		sort_size_2(stack_a, "sa");
	push(stack_b, stack_a, "pa");
	push(stack_b, stack_a, "pa");
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (!isordered(*stack_a))
	{
		if (size == 2)
		sort_size_2(stack_a, "sa");
	else if (size == 3)
		sort_size_3(stack_a);
	else if (size > 3 && size <= 5)
		sort_size_5(stack_a, stack_b);
	else
		ksort(stack_a, stack_b);
	}
}
