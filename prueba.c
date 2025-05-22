#include "push_swap.h"

void	free_resources(t_list **stack_a, t_list **stack_b, char **argv, int need_free)
{
    int	index;

    index = 0;
    if (stack_a && stack_b)
    {
        ft_lstclear(stack_a, free);
        ft_lstclear(stack_b, free);
    }
    if (need_free && argv)
    {
        while (argv[index])
        {
            free(argv[index]);
            index++;
        }
        free(argv);
    }
}

t_list	*parse_args(char *arg)
{
    int		*value;
    t_list	*new_node;

    value = malloc(sizeof(int));
    if (!value)
        return (NULL);
    *value = ft_atoi(arg);
    ft_printf("Valor convertido: %d\n", *value); // Depuración
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
        stack->index = index;
        stack = stack->next;
        index++;
    }
}

void	print_satck(t_list *stack)
{
    while (stack)
    {
        ft_printf("Contenido: %d Indice: %d\n", *(int *)stack->content, stack->index);
        stack = stack->next;
    }
}

void	sa_and_sb(t_list **stack_a, char *operation)
{
    t_list	*second;
    t_list	*first_node;

    first_node = *stack_a;
    if (!stack_a || !(*stack_a)->next || !(*stack_a))
        return;
    second = (*stack_a)->next;
    first_node->next = second->next;
    second->next = first_node;
    *stack_a = second;
    ft_printf("%s\n", operation);
}

void	ra_and_rb(t_list **stack_a, char *operation)
{
    t_list	*first_node;
    t_list	*last_node;

    first_node = *stack_a;
    last_node = *stack_a;
    if (!stack_a || !(*stack_a)->next || !(*stack_a))
        return;
    while (last_node->next)
        last_node = last_node->next;
    last_node->next = first_node;
    *stack_a = first_node->next;
    first_node->next = NULL;
    if (operation)
        ft_printf("%s\n", operation);
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
    while (last_node->next)
    {
        temp = last_node;
        last_node = last_node->next;
    }
    temp->next = NULL;
    last_node->next = first_node;
    *stack_a = last_node;
    if (operation)
        ft_printf("%s\n", operation);
}

void	pb_and_pa(t_list **stack_a, t_list **stack_b, char *operation)
{
    t_list	*firts_node_a;

    if (!stack_a || !(*stack_a)->next || !(*stack_a))
        return;
    firts_node_a = *stack_a;
    *stack_a = firts_node_a->next;
    firts_node_a->next = NULL;
    ft_lstadd_front(&(*stack_b), firts_node_a);
    ft_printf("%s\n", operation);
}

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

int	ft_isnumber(char *str)
{
    int	index;

    if (!str || !*str)
        return (0);
    index = 0;
    if (str[index] == '-' || str[index] == '+')
        index++;
    if (!str[index])
        return (0);
    while (str[index])
    {
        if (!ft_isdigit(str[index]))
            return (0);
        index++;
    }
    return (1);
}

int	ft_duplicate_args(char **argv)
{
    int	i;
    int	j;

    i = 0;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int	procces_args(char **argv, t_list **stack_a, int need_free)
{
    int		index;
    t_list	*new_node;

    index = 0;
    if (ft_duplicate_args(argv))
    {
        ft_printf("Error\n");
        return (0);
    }
    while (argv[index])
    {
        if (!ft_isnumber(argv[index]))
        {
            ft_printf("Error\n");
            return (0);
        }
        new_node = parse_args(argv[index]);
        if (!new_node || *(int *)new_node->content > INT_MAX || *(int *)new_node->content < INT_MIN)
        {
            if (new_node)
            {
                free(new_node->content);
                free(new_node);
            }
            ft_printf("Error\n");
            return (0);
        }
        ft_lstadd_back(stack_a, new_node);
        index++;
    }
    return (1);
}

int	main(int argc, char *argv[])
{
    int		index;
    t_list	*stack_a;
    t_list	*stack_b;
    int		need_free;

    if (argc < 2)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    need_free = 0;
    if (argc == 2)
    {
        argv = ft_split(argv[1], 32);
        need_free = 1;
    }	
	else
		argv++;
    if (!procces_args(argv, &stack_a, need_free))
    {
        free_resources(&stack_a, &stack_b, argv, need_free);
        return (1);
    }
    if (need_free)
        free_resources(NULL, NULL, argv, need_free);
    assign_indexes(stack_a);
    print_satck(stack_a);
    ft_printf("\n");
    print_satck(stack_b);
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
    return (0);
}