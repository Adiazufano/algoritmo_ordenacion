/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:30:50 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/06/04 11:19:44 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Asigna a cada nodo su índice ordenado (único)
void	assign_index(t_list *stack, int *sorted_arr, int size)
{
	int	index;
	int	*assigned;

	if (!stack || !sorted_arr || size <= 0)
		return ;
	assigned = ft_calloc(size, sizeof(int));
	if (!assigned)
		return ;
	while (stack)
	{
		index = 0;
		while (index < size)
		{
			if (*(int *)stack->content == sorted_arr[index] && !assigned[index])
			{
				stack->index = index;
				assigned[index] = 1;
				break ;
			}
			index++;
		}
		stack = stack->next;
	}
	free(assigned);
}

// Devuelve el índice máximo de la lista
int	find_max_index(t_list *stack)
{
	int	max_index;
	int	first;

	first = 1;
	if (!stack)
		return (-1);
	while (stack)
	{
		if (first || stack->index > max_index)
		{
			max_index = stack->index;
			first = 0;
		}
		stack = stack->next;
	}
	return (max_index);
}

// Devuelve la posición de un índice concreto en la lista
int	get_pos_index(t_list *stack, int target_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
