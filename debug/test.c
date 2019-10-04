/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:03:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 20:12:50 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <math.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int icmp(const void *p1, const void *p2)
{
	return (*((char *)p2) - *((char *)p1));
}

int main()
{
	ft_gc_init();
	int i;
	t_darr	test;

	darr_init(&test, sizeof(int), 2);

	i = 5;
	darr_add(test, &i);

	i = 15;
	darr_add(test, ft_i(15));

	i = 25;
	darr_add(test, &i);

	i = 35;
	darr_add(test, &i);

	ft_printf("%d\n", *(int *)darr_pop(test));

	i = -5;
	darr_add_i(test, &i, 0);

	ft_printf("%d\n", *(int *)darr_pop_i(test, 0));

	i = 45;
	darr_add(test, &i);

	i = 55;
	darr_add(test, &i);

	i = 65;
	darr_add(test, &i);

	i = -1;
	darr_eq(test, 3, &i);

	darr_sort(test, icmp, qsort);

	while (darr_l(test))
		ft_printf("%d\n", *(int *)darr_pop_i(test, 0));

	darr_del(&test);

	ft_gc_clean();
	return (0);
}
