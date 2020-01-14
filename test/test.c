/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:03:18 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/14 19:29:44 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <float.h>
#include <ctype.h>

void	test(void)
{
	t_deq	deq[1];
	deq_init(deq, sizeof(int), 32);

	deq_push_front(deq, ft_i(9));
	deq_push_front(deq, ft_i(5));
	deq_push_front(deq, ft_i(0));
	deq_push_back(deq, ft_i(10));
	deq_align_front(deq);
	deq_push_back(deq, ft_i(15));


	deq_align_front(deq);

	ft_printf("%d\n", *(int *)deq_pop_back(deq));
	ft_printf("%d\n", *(int *)deq_pop_front(deq));
	ft_printf("%d\n", *(int *)deq_pop_front(deq));
	ft_printf("%d\n", *(int *)deq_pop_front(deq));
	ft_printf("%d\n", *(int *)deq_pop_front(deq));

	deq_del(deq);
	return ;
}

int		main(void)
{
	ft_memman_init();
	test();
	ft_force_buff();
	ft_memman_clean();
	return (0);
}
