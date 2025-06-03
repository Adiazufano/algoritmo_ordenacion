/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:43:21 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/30 22:55:26 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nbr)
{
	int	i;

	i = 1;
	while (i * i <= nbr)
		i++;
	return (i - 1);
}

void	push_b(t_list **stack_a, t_list **stack_b, int *size_a, int *size_b)
{
	int	range;

	range = ft_sqrt(*size_a) * 133 / 100;
	if (!stack_a || !stack_b || !*stack_a)
		return ;
	while (*size_a > 0 && *stack_a)
	{
		if ((*stack_a)->index <= *size_b)
			(push(stack_a, stack_b, "pb"), (*size_a)--, (*size_b)++);
		else if ((*stack_a)->index <= *size_b + range)
		{
			push(stack_a, stack_b, "pb");
			(*size_a)--;
			(*size_b)++;
			if (*stack_a && (*stack_a)->index > *size_b + range)
				rr(stack_a, stack_b);
			else if (*stack_b)
				rotate(stack_b, "rb");
		}
		else
			rotate(stack_a, "ra");
	}
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	int	max_index;
	int	pos;
	int	size_b;

	while (*stack_b)
	{
		max_index = find_max_index(*stack_b);
		pos = get_pos_index(*stack_b, max_index);
		size_b = ft_lstsize(*stack_b);
		if (max_index == -1 || pos == -1)
			break ;
		if (pos <= size_b / 2)
		{
			while ((*stack_b)->index != max_index)
				rotate(stack_b, "rb");
		}
		else
		{
			while ((*stack_b)->index != max_index)
				rerotate(stack_b, "rrb");
		}
		if ((*stack_b)->index == max_index)
			push(stack_b, stack_a, "pa");
	}
}

void	ksort(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;
	int	*arr;

	if (!stack_a || !*stack_a)
		return ;
	size_a = ft_lstsize(*stack_a);
	size_b = 0;
	arr = stack_to_array(*stack_a, size_a);
	if (!arr)
		return ;
	sort_array(arr, size_a);
	assign_index(*stack_a, arr, size_a);
	free(arr);
	push_b(stack_a, stack_b, &size_a, &size_b);
	push_a(stack_a, stack_b);
}
