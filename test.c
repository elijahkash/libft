/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:03:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/05 19:22:23 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <ctype.h>

#include "libft.h"

int main()
{
/*
// ft_putchar
	printf("ft_putchar('T')=");
	fflush(stdout);
	ft_putchar('T');
	printf("\n");


// ft_putstr
	printf("ft_putstr(\"I LOVE YOU\")=");
	fflush(stdout);
	ft_putstr("I LOVE YOU");
	printf("\n");


// ft_putendl
	printf("ft_putendl(\"I LOVE YOU\")=");
	fflush(stdout);
	ft_putendl("I LOVE YOU");
	printf("\n");

// ft_putchar_fd		MISS
// ft_putstr_fd			MISS
// ft_putendl_fd		MISS

// ft_putendl
	printf("ft_strlen(\"\")=%zd, ft_strlen(\"1\")=%zd\n",
			ft_strlen(""), ft_strlen("1"));

// ft_isalpha
*/

	char str1[15] = {'a', '1', '2', '3', '4', '5', '6', '7',};
	//char str2[10] = {'7', '8', '9'};
	//strlcat(str1, "lorem", 2);
	printf("%zd    %s\n", strlcat(str1, "lorem", 2), str1);
	return (0);
}
