/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:18:30 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/30 20:03:57 by aldiaz-u         ###   ########.fr       */
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

int	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	isordered(t_list *stack)
{
	while (stack && stack -> next)
	{
		if ((*(int *) stack->content > *(int *) stack->next->content))
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void	print_stack(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current)
	{
		ft_printf("Contenido: %i, Index: %i\n",
			*(int *)current -> content, current -> index);
		current = current -> next;
	}
}

int	main(int argc, char *argv[])
{
	int		index;
	t_list	*stack_a;
	t_list	*stack_b;
	char	**splited;

	index = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	while (index < argc)
	{
		splited = ft_split(argv[index], ' ');
		check_args(splited, &stack_a);
		parser(&stack_a, argv, splited);
		free_resources(NULL, NULL, splited);
		index++;
	}
	/* sort(&stack_a, &stack_b); */
	sort(&stack_a, &stack_b);
	//print_stack(&stack_a); 
	//print_stack(&stack_a);
	free_resources(&stack_a, NULL, NULL);
	return (0);
}
