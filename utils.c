/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:15:32 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/30 22:50:52 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *nptr)
{
	long	resultado;
	long	sign;

	resultado = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		resultado = resultado * 10 + (*nptr - '0');
		nptr++;
	}
	return (resultado * sign);
}

int	get_content(t_list *stack_a)
{
	return (*(int *)stack_a->content);
}

int	*stack_to_array(t_list *stack, int size)
{
	int	*array;
	int	index;

	if (!stack || size <= 0)
		return (NULL);
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	index = 0;
	while (index < size && stack)
	{
		array[index] = get_content(stack);
		stack = stack->next;
		index++;
	}
	return (array);
}

// Ordena el array de enteros (burbuja)
void	sort_array(int *arr, int size)
{
	int	index;
	int	j;
	int	temp;

	if (!arr || size <= 0)
		return ;
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

int	find_min(t_list *stack)
{
	int	min;

	min = get_content(stack);
	while (stack)
	{
		if (get_content(stack) < min)
			min = get_content(stack);
		stack = stack -> next;
	}
	return (min);
}
