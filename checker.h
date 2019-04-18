/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:51:32 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/17 18:51:32 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
#define PUSH_SWAP_CHECKER_H

typedef struct s_heap
{
	int *heap;
	int len;
	int capacity;
} t_heap;

void 	bubble_sort(int *a, int len);
void	shaker_sort(int *a, int len);
void	comb_sort(int *a, int len);
void	insert_sort(int *a, int len);
void	shell_sort(int *a, int len);
void	gnome_sort(int *a, int len);
void	selection_sort(int *a, int len);
void	heap_sort(int *a, int len);
void	quick_sort(int *a, int len);
void	merge_sort(int *a, int len);

#endif
