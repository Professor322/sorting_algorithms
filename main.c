/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:28:50 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/17 15:28:50 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "checker.h"

int	main(void)
{
	int a[10] = {17, 7, 3, 2 , 10, 9 , 6 , 8 , 4, -1};

	for (int i = 0; i < 10; i++)
		ft_printf("%d ", a[i]);
	//bubble_sort(a, 10);
	//shaker_sort(a, 10);
	//comb_sort(a, 10);
	//insert_sort(a, 10);
	//shell_sort(a, 10);
	//gnome_sort(a, 10);
	//selection_sort(a, 10);
	//heap_sort(a, 10);
	//quick_sort(a, 10);
	merge_sort(a, 10);
	ft_printf("\n");
	for (int i = 0; i < 10; i++)
		ft_printf("%d ", a[i]);


	return (0);
}