/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:29:16 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/30 20:53:47 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicate_args(t_list **stack_a, int num)
{
	t_list	*current;

	current = *stack_a;
	while (current)
	{
		if (*(int *)current -> content == num)
			return (0);
		current = current -> next;
	}
	return (1);
}

int	ft_is_valid_number(char *num)
{
	int		index;
	long	number;

	index = 0;
	if (num[index] == '-' || num[index] == '+')
		index++;
	while (num[index])
	{
		if (!ft_isdigit(num[index]))
			return (0);
		index++;
	}
	number = ft_atol(num);
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	return (1);
}

void	duplicated_splited(char **splited)
{
	int	index;
	int	j;
	int	num1;
	int	num2;

	index = 0;
	while (splited[index])
	{
		j = index + 1;
		num1 = ft_atol(splited[index]);
		while (splited[j])
		{
			num2 = ft_atol(splited[j]);
			if (num1 == num2)
			{
				free_resources(NULL, NULL, splited);
				error();
			}
			j++;
		}
		index++;
	}
}

void	check_args(char **splited, t_list **stack_a)
{
	int		index;
	int		j;
	long	num;

	duplicated_splited(splited);
	index = 0;
	while (splited[index])
	{
		num = ft_atol(splited[index]);
		if (!ft_is_valid_number(splited[index])
			|| !ft_duplicate_args(stack_a, num))
		{
			free_resources(stack_a, NULL, splited);
			error();
		}
		index++;
	}
}

void	parser(t_list **stack_a, char **args, char **splited)
{
	int		index;
	t_list	*new_node;
	int		*value;

	index = 0;
	while (splited[index])
	{
		value = malloc(sizeof(int));
		if (!value)
			error();
		*value = ft_atoi(splited[index]);
		new_node = ft_lstnew(value);
		if (!new_node)
			error();
		ft_lstadd_back(stack_a, new_node);
		index++;
	}
}
