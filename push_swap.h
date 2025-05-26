/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:31:06 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/26 11:45:16 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf/libft/libft.h"
# include "printf/ft_printf.h"

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
void	parser(t_list **stack_a, char **args,
			char **splited, int *global_index);
void	free_resources(t_list **stack_a, t_list **stack_b, char **splited);
void	ss(t_list **stack1, t_list **stack2);
#endif