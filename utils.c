/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:15:32 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/28 09:13:33 by aldiaz-u         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
}

int	get_content(t_list *stack_a)
{
	return (*(int *)stack_a->content);
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

int	find_second_min(t_list *stack)
{
	int	min;
	int	second_min;
	int	val;

	min = find_min(stack);
	while (stack)
	{
		val = get_content(stack);
		if (val != min && val < second_min)
			second_min = val;
		stack = stack -> next;
	}
	return (second_min);
}
