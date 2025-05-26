/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:31:06 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/23 18:55:34 by aldiaz-u         ###   ########.fr       */
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
#endif