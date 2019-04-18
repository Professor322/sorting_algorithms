/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:27:53 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/18 22:27:53 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	merge(int *a, int left, int mid, int right)
{
	int index1 = 0;
	int index2 = 0;
	int *result = (int*)malloc(sizeof(int) * (right - left));

	while (left + index1 < mid && mid + index2 < right)
		if (a[left + index1] < a[mid + index2])
		{
			result[index1 + index2] = a[left + index1];
			index1++;
		}
		else
		{
			result[index1 + index2] = a[mid + index2];
			index2++;
		}
	while (left + index1 < mid)
	{
		result[index1 + index2] = a[left + index1];
		index1++;
	}
	while (mid + index2 < right)
	{
		result[index1 + index2] = a[mid + index2];
		index2++;
	}
	for (int i = 0; i < index1 + index2; i++)
		a[left + i] = result[i];
	free(result);
}

void	ft_mergesort(int *a, int left, int right)
{
	if (left + 1 >= right)
		return ;
	int mid = (left + right) / 2;
	ft_mergesort(a, left, mid);
	ft_mergesort(a, mid, right);
	merge(a, left, mid, right);
}

void	merge_sort(int *a, int len)
{
	ft_mergesort(a, 0, len);
}