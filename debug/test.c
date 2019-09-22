/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:03:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/22 17:25:01 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <locale.h>

#define TXT "!%0 5%!\n"

int main()
{
	int ret;
//	char s1[21]= {"\0"};
//	printf(TXT);
//	printf("\n%lc", LC_NUMERIC);
	ret = ft_printf("aa%*%bb\n", -5);
	printf("\nret=%d\n", ret);
	return (0);
}
