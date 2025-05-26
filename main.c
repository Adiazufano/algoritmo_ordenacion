/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:18:30 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/23 18:57:17 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_resources(t_list **stack_a, t_list **stack_b, char **splited)
{
	int	index;

	index = 0;
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	if (splited)
	{
		while (splited[index])
			free(splited[index++]);
		free(splited);
	}
}

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

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}
void	duplicated_splited(char **splited)
{
	int	index;
	int	j;

	index = 0;
	while (splited[index])
	{
		j = index + 1;
		while (splited[j])
		{
			if (!ft_strcmp(splited[index], splited[j]))
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
		if (!ft_is_valid_number(splited[index]) || !ft_duplicate_args(stack_a, num))
		{
			free_resources(stack_a, NULL, splited);
			error();
		}
		index++;
	}
}

void	parser(t_list **stack_a, char **args, char **splited, int *global_index)
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
		new_node -> index = (*global_index)++;
		ft_lstadd_back(stack_a, new_node);
		index++;
	}
}

void	print_stack(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current)
	{
		ft_printf("Contenido: %d, Indice: %d\n", *(long *)current -> content, current -> index);
		current = current -> next;
	}
	
}

int	main(int argc, char *argv[])
{
	int		index;
	int		global_index;
	t_list	*stack_a;
	t_list	*stack_b;
	char	**splited;

	index = 1;
	stack_a = NULL;
	stack_b = NULL;
	global_index = 0;
	if (argc < 2)
		return (0);
	while (index < argc)
	{
		splited = ft_split(argv[index], ' ');
		check_args(splited, &stack_a);
		parser(&stack_a, argv, splited, &global_index);
		free_resources(NULL, NULL, splited);
		index++;
	}
	push(&stack_a, &stack_b, "pa");
	push(&stack_a, &stack_b, "pa");
	//rr(&stack_a, &stack_b);
	//rrr(&stack_a, &stack_b);
	print_stack(&stack_a);
	ft_printf("\n");
	print_stack(&stack_b);
	free_resources(&stack_a, NULL, NULL);
	return (0);
}
