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
		printf("Contenido: %i Indice: %i\n", *(int *)stack -> content, stack -> index);
		stack = stack -> next;
	}
}

int	main(int argc, char *argv[])
{
	int	index;
	t_list *stack_a;
	t_list *new_node;
	int	*value;
	t_list *cur;

	stack_a = NULL;
	index = 1;
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
	
	assign_indexes(stack_a);
	print_satck(stack_a);
	free_stacl(stack_a);
	return(0);
}