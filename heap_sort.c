/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:26:52 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/18 18:26:52 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

t_heap 	*create_heap()
{
	t_heap *heap;

	heap = (t_heap*)malloc(sizeof(heap));
	heap->heap = (int*)malloc(sizeof(int));
	heap->len = 0;
	heap->capacity = 1;
	return (heap);
}

void	sift_up(t_heap *heap, int i)
{
	while (i > 0 && heap->heap[i] < heap->heap[(i - 1) / 2])
	{
		ft_swap(heap->heap + i, heap->heap + ((i - 1) / 2));
		i = (i - 1) / 2;
	}
}

void	sift_down(t_heap *heap, int i)
{
	int left;
	int right;
	int j;

	while (2 * i + 1 < heap->len)
	{
		left = 2 * i + 1;
		right = 2 * i + 2;
		j = left;
		if (right < heap->len && heap->heap[left] > heap->heap[right])
			j = right;
		if (heap->heap[j] >= heap->heap[i])
			break;
		ft_swap(heap->heap + j, heap->heap + i);
		i = j;
	}
}

void 	insert(t_heap *heap, int value, int quantity)
{
	if (heap->len + quantity > heap->capacity)
	{
		int *new_heap = (int*)malloc(sizeof(int) * (heap->capacity * 2 + quantity));
		heap->capacity = heap->capacity * 2 + quantity;
		ft_memcpy(new_heap, heap->heap, sizeof(int) * heap->len);
		ft_memdel((void**)&(heap->heap));
		heap->heap = new_heap;
	}
	heap->heap[heap->len++] = value;
	sift_up(heap, heap->len - 1);
}

int		pop_min(t_heap *heap)
{
	int min = heap->heap[0];
	heap->heap[0] = heap->heap[heap->len - 1];
	heap->len--;
	sift_down(heap, 0);
	return (min);
}

void 	clear(t_heap **heap)
{
	(*heap)->len = 0;
	(*heap)->capacity = 0;
	ft_memdel((void**)&((*heap)->heap));
	ft_memdel((void**)heap);
}

void	heap_sort(int *a, int len)
{
	t_heap *heap = create_heap();

	for (int i = 0; i < len; i++)
		insert(heap, a[i], 1);
	for (int i = 0; i < len; i++)
		a[i] = pop_min(heap);
	clear(&heap);
}