/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:31:06 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/28 10:06:42 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf/libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_chunk_data
{
	int	*arr;
	int	size;
	int	chunk_count;
}				t_chunk_data;
int		main(int argc, char *argv[]);
void	swap(t_list	**stack, char *op);
void	rotate(t_list	**stack, char *op);
void	rerotate(t_list **stack, char *op);
void	push(t_list **stack1, t_list **stack2, char *op);
void	rr(t_list **stack1, t_list **stack2);
void	rrr(t_list **stack1, t_list **stack2);
long	ft_atol(char *nptr);
int		ft_strcmp(char *s1, char *s2);
int		ft_duplicate_args(t_list **stack_a, int num);
int		ft_is_valid_number(char *num);
void	error(void);
void	duplicated_splited(char **splited);
void	check_args(char **splited, t_list **stack_a);
void	parser(t_list **stack_a, char **args, char **splited);
void	free_resources(t_list **stack_a, t_list **stack_b, char **splited);
void	ss(t_list **stack1, t_list **stack2);
int		list_size(t_list *stack);
void	sort_size_2(t_list **stack_a, char *op);
void	sort(t_list **stack_a, t_list **satck_b);
int		isordered(t_list *stack);
void	sort_size_3(t_list **stack_a);
void	print_stack(t_list **stack);
int		get_content(t_list *stack_a);
int		*stack_to_array(t_list *stack, int size);
void	sort_array(int	*arr, int size);
int		get_index(int *arr, int size, int value);
void	ksort(t_list **stack_a, t_list **stack_b, int chunk_size);
int		find_min(t_list *stack);
int		find_second_min(t_list *stack);
void	push_back_sorted(t_list **stack_a, t_list **stack_b);
int		find_max(t_list *stack);
int		get_index(int *arr, int size, int value);
void	sort_array(int	*arr, int size);
int		*stack_to_array(t_list *stack, int size);
#endif