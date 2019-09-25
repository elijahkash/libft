/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:03:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/25 12:19:19 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <locale.h>

#define TXT "!%15.5s!\n"

int main()
{
	int ret;
//	char s1[21]= {"qwert"};
//	printf(TXT, s1);
//	printf("\n%lc", LC_NUMERIC);

//	ret = ft_printf("%p", &ret);
//	printf("\nret=%d\n", ret);
	ret = ft_printf("%llx", ((unsigned long long int)9223372036854775807));
	printf("\nret=%d\n", ret);

/*
	ret = ft_printf("This is a simple test.");
	printf("\nret=%d\n", ret);
	fflush(stdout);
	ret = ft_printf("This is a simple test.\nSecond sentence.\n");
	printf("\nret=%d\n", ret);
	fflush(stdout);
	ret = ft_printf("");
	printf("\nret=%d\n", ret);
	fflush(stdout);
	ret = ft_printf("\n");
	printf("\nret=%d\n", ret);
	fflush(stdout);
	*/
	return (0);
}
