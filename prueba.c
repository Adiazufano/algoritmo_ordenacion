#include "push_swap.h"

void	free_stacl(t_list *stack)
{
	t_list *temp;
	while (stack)
	{
		temp = stack -> next;
		free(stack -> content);
		free(stack);
		stack = temp;
	}
	
}

t_list	*parse_args(char *arg)
{
	int	*value;
	t_list	*new_node;

	value = malloc(sizeof(int));
	if (!value)
		return (NULL);
	*value = ft_atoi(arg);
	new_node = ft_lstnew(value);
	if (!new_node)
	{
		free(value);
		return (NULL);
	}
	return (new_node);
}

void	assign_indexes(t_list *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		stack -> index = index;
		stack = stack -> next;
		index++;
	}
}

void	print_satck(t_list *stack)
{
	while (stack)
	{
		ft_printf("Contenido: %i Indice: %i\n", *(int *)stack -> content, stack -> index);
		stack = stack -> next;
	}
}
void	sa_and_sb (t_list **stack_a, char *operation)
{
	t_list	*second;
	t_list	*first_node;

	first_node = *stack_a;
	if (!stack_a || !(*stack_a) -> next || !(*stack_a))
	return ;
	second = (*stack_a) -> next;
	first_node -> next = second -> next;
	second -> next = first_node;
	*stack_a = second;
	ft_printf("%s\n", operation);
}

void	ra_and_rb(t_list **stack_a, char *operation)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = *stack_a;
	last_node = *stack_a;
	if (!stack_a || !(*stack_a) -> next || !(*stack_a))
		return;
	while (last_node -> next)
		last_node = last_node -> next;
	last_node -> next = first_node;
	*stack_a = first_node -> next;
	first_node -> next = NULL;
	if (operation)
		ft_printf("%s\n",operation);
}

void	rra_and_rrb(t_list **stack_a, char *operation)
{
	t_list	*first_node;
	t_list	*last_node;
	t_list	*temp;

	first_node = *stack_a;
	last_node = *stack_a;
	temp = NULL;
	if (!stack_a || !(*stack_a)->next || !(*stack_a))
		return;
	while (last_node -> next)
	{
		temp = last_node;
		last_node = last_node -> next;
	}
	temp -> next = NULL;
	last_node -> next = first_node;
	*stack_a = last_node;
	if (operation)
		ft_printf("%s\n", operation);
}

void	pb_and_pa(t_list **stack_a, t_list **stack_b, char *operation)
{
	t_list *firts_node_a;

	if (!stack_a || !(*stack_a)->next || !(*stack_a))
		return;
	firts_node_a = *stack_a;
	*stack_a = firts_node_a -> next;
	firts_node_a -> next = NULL;
	ft_lstadd_front(&(*stack_b), firts_node_a);
	ft_printf("%s\n", operation);
}

/* void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*fist_node_b;

	fist_node_b = *stack_b;
	*stack_b = fist_node_b -> next;
	fist_node_b -> next = NULL;
	ft_lstadd_front(&(*stack_a), fist_node_b);
}

void	sb(t_list **stack_b)
{
	t_list	*second_node;

	second_node = (*stack_b) -> next;
	(*stack_b) -> next = second_node -> next;
	second_node -> next = *stack_b;
	*stack_b = second_node;
} */

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra_and_rb(stack_a, NULL);
	ra_and_rb(stack_b, NULL);
	ft_printf("rr\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra_and_rrb(stack_a, NULL);
	rra_and_rrb(stack_b, NULL);
	ft_printf("rrr\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa_and_sb(stack_a, NULL);
	sa_and_sb(stack_b, NULL);
	ft_printf("ss");
}

int	main(int argc, char *argv[])
{
	int	index;
	t_list *stack_a;
	t_list *stack_b;
	t_list *new_node;
	char **splited;
	int	*value;
	int i;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	index = 1;
	if (argc == 2)
	{
		splited = ft_split(argv[1], 32);
		if (!splited)
			return (1);
		i = 0;
		while (splited[i])
		{
			new_node = parse_args(splited[i]);
			if (!new_node)
			{
				free_stacl(stack_a);
				i = 0;
				while (splited[i])
					free(splited[i++]);
				free(splited);
				return (1);
			}
			ft_lstadd_back(&stack_a, new_node);
			i++;
		}

		// Liberar splited
		i = 0;
		while (splited[i])
			free(splited[i++]);
		free(splited);
	}
	else
	{
		while (index < argc)
		{
			new_node = parse_args(argv[index]);
			if (!new_node)
			{
				free_stacl(stack_a);
				return (1);
			}
			ft_lstadd_back(&stack_a, new_node);
			index++;
		}
	}
	
	assign_indexes(stack_a);
	// sa_and_sb(&stack_a, "sa");
	// pb_and_pa(&stack_a, &stack_b, "pb");
	// pb_and_pa(&stack_a, &stack_b, "pb");
	// rr(&stack_a, &stack_b);
	// rrr(&stack_a, &stack_b);
	//sb(&stack_b);
	print_satck(stack_a);
	ft_printf("\n");
	print_satck(stack_b);
	free_stacl(stack_a);
	free_stacl(stack_b);
	return(0);
}