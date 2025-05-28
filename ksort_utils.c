/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:24:35 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/28 10:05:19 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_list *stack, int size)
{
	int	*array;
	int	index;

	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	index = 0;
	while (index < size)
	{
		array[index] = get_content(stack);
		stack = stack -> next;
		index++;
	}
	return (array);
}

void	sort_array(int	*arr, int size)
{
	int	index;
	int	j;
	int	temp;

	index = 0;
	while (index < size - 1)
	{
		j = index + 1;
		while (j < size)
		{
			if (arr[index] > arr[j])
			{
				temp = arr[index];
				arr[index] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		index++;
	}
}

int	get_index(int *arr, int size, int value)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (arr[index] == value)
			return (index);
		index++;
	}
	return (-1);
}

int	find_max(t_list *stack)
{
	int	max;

	max = get_content(stack);
	while (stack)
	{
		if (get_content(stack) > max)
			max = get_content(stack);
		stack = stack->next;
	}
	return (max);
}

void	push_back_sorted(t_list **stack_a, t_list **stack_b)
{
	int		max;
	int		pos;
	t_list	*tmp;

	while (*stack_b)
	{
		max = find_max(*stack_b);
		pos = 0;
		tmp = *stack_b;
		while (get_content(tmp) != max)
		{
			pos++;
			tmp = tmp->next;
		}
		if (pos <= list_size(*stack_b) / 2)
			while (get_content(*stack_b) != max)
				rotate(stack_b, "rb");
		else
			while (get_content(*stack_b) != max)
				rerotate(stack_b, "rrb");
		push(stack_b, stack_a, "pa");
	}
}
