/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:03:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/24 12:21:56 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <locale.h>

#define TXT "!%15.5s!\n"

int main()
{
	int ret;
	char s1[21]= {"qwert"};
//	printf(TXT, s1);
//	printf("\n%lc", LC_NUMERIC);
	ret = ft_printf("qq%szz\n", s1);
	printf("\nret=%d\n", ret);
	return (0);
}
