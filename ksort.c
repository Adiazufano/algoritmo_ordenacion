/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:19:20 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/05/28 10:01:22 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_chunk(int *chunk, int *pushed, int chunk_size, int chunk_count)
{
	(*pushed)++;
	if (*pushed >= chunk_size && *chunk < chunk_count -1)
	{
		(*chunk)++;
		*pushed = 0;
	}
}

void	push_chunks(t_list **stack_a, t_list **stack_b, t_chunk_data *data)
{
	int	chunk;
	int	chunk_size;
	int	index;
	int	pushed;

	chunk = 0;
	pushed = 0;
	chunk_size = data -> size / data -> chunk_count;
	while (*stack_a)
	{
		index = get_index(data -> arr, data->size, get_content(*stack_a));
		if (index >= chunk * chunk_size
			&& (chunk == data->chunk_count - 1
				|| index < (chunk + 1) * chunk_size))
		{
			push(stack_a, stack_b, "pb");
			update_chunk(&chunk, &pushed, chunk_size, data->chunk_count);
		}
		else
			rotate(stack_a, "ra");
	}
}

void	ksort(t_list **stack_a, t_list **stack_b, int chunk_count)
{
	t_chunk_data	data;

	data.size = list_size(*stack_a);
	if (chunk_count <= 0 || chunk_count > data.size)
		chunk_count = 1;
	data.chunk_count = chunk_count;
	data.arr = stack_to_array(*stack_a, data.size);
	sort_array(data.arr, data.size);
	push_chunks(stack_a, stack_b, &data);
	push_back_sorted(stack_a, stack_b);
	free(data.arr);
}
