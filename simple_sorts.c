/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:39:05 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/17 18:39:05 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	bubble_sort(int *a, int len)
{
	int flag;

	for (int i = 0; i < len - 1; i++)
	{
		flag = 0;
		for (int j = 0; j < len - i - 1; j++)
			if (*(a + j) > *(a + j + 1))
			{
				ft_swap(a + j, a + j + 1);
				flag = 1;
			}
		if (!flag)
			break ;
	}
}

void	shaker_sort(int *a, int len)
{
	int flag;

	for (int i = 0; i < len - 1; i++)
	{
		flag = 0;
		for (int j = i; j < len - i - 1; j++)
			if (*(a + j) > *(a + j + 1))
			{
				ft_swap(a + j, a + j + 1);
				flag = 1;
			}
		if (!flag)
			break ;
		for (int k = len - i - 1; k > i; k--)
			if (*(a + k) < *(a + k - 1))
				ft_swap(a + k, a + k - 1);
	}
}

void	comb_sort(int *a, int len)
{
	int flag;
	const float coef = 1.247;
	float step;

	step = len - 1;
	while ((int)step > 1)
	{
		for (int i = 0; i + (int)step < len; i++)
			if (*(a + i) < *(a + (int)step))
				ft_swap(a + i, a + (int)step);
		step /= coef;
	}
	for (int i = 0; i < len - 1; i++)
	{
		flag = 0;
		for (int j = 0; j < len - i - 1; j++)
			if (*(a + j) > *(a + j + 1))
			{
				ft_swap(a + j, a + j + 1);
				flag = 1;
			}
		if (!flag)
			break ;
	}
}

void	insert_sort(int *a, int len)
{
	int key;
	int j;

	for (int i = 1; i < len; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = key;
	}
}

/*
**   gaps[7] = {701, 301, 132, 57, 23, 10, 4, 1} marcin curo gap sequence
*/

void	shell_sort(int *a, int len)
{
	int gaps[8] = {701, 301, 132, 57, 23, 10, 4, 1};
	int key;
	int index;

	for (int i = 0; i < 8; i++)
	{
		for (int j = gaps[i]; j < len; j++)
		{
			key = a[j];
			index = j;
			while (index >= gaps[i] && a[index - gaps[i]] > key)
			{
				a[index] = a[index - gaps[i]];
				index -= gaps[i];
			}
			a[index] = key;
		}
	}
}

void	gnome_sort(int *a, int len)
{
	int i = 1;
	int j = 2;

	while (i < len)
	{
		if (a[i - 1] < a[i])
		{
			i = j;
			j++;
		}
		else
		{
			ft_swap(a + i - 1, a + i);
			i--;
			if (!i)
			{
				i = j;
				j++;
			}
		}
	}
}

void	selection_sort(int *a, int len)
{
	int min_index;
	int min;

	for (int i = 0; i < len ; i++)
	{
		min = a[i];
		min_index = i;
		for (int j = i + 1; j < len; j++)
			if (min > a[j])
			{
				min = a[j];
				min_index = j;
			}
		ft_swap(a + i, a + min_index);
	}

}

int 	partition(int *a, int left, int right)
{
	int pivot = a[(right + left) / 2];
	int i = left;
	int j = right;

	while (i <= j)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i >= j)
			break ;
		ft_swap(a + i++, a + j++);
	}
	return (j);
}

void	quicksort(int *a, int left, int right)
{
	if (left < right)
	{
		int part = partition(a, left, right);
		quicksort(a, left, part);
		quicksort(a, part + 1, right);
	}
}

void	quick_sort(int *a, int len)
{
	quicksort(a, 0, len - 1);
}