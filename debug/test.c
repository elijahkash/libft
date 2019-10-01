/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:03:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/01 22:51:31 by semenbegunov     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <locale.h>
#include <math.h>
#include <float.h>

#define TXT "%2$d:%1$.*4$d:%4$.*3$d\n", 13, 51, 6, 45

#include <fcntl.h>
#include <unistd.h>
#include "double.h"


int main()
{
	int ret = 0;
	//long double ld;
	union u_double ud;

	char output[20000];

	//ud.s_parts.e = 0x7FFE;
	//ud.s_parts.m = 0x7FFFFFFFFFFFFFFF;


	ud.ld = LDBL_MAX;
	prf_dblcalc(ud.ld, 19000, output);
//	ft_printf("%s\n", output);



	//ud.ld = NAN;
//	ft_printf("%b %b %b\n", ud.s_parts.s, ud.s_parts.e, ud.s_parts.m);

//	ud.ld = 0.0;
//	ft_printf("%Lf\n", ud.ld);
//	ud.ld = -0.0;
//	ft_printf("%Lf\n", ud.ld);
//	ud.ld = 0.0000000001;
//	ft_printf("%Lf\n", ud.ld);
//	ud.ld = -0.0000000001;
//	ft_printf("%Lf\n", ud.ld);
//	ud.ld = 0.0;
//	ft_printf("%Lf\n", ud.ld);
//	ud.ld = 0.0;
//	ft_printf("%Lf\n", ud.ld);
//	//ft_printf("%Lf\n", ud.ld);
	//printf("%.20000Lf\n", ud.ld);	fflush(stdout);

//	int fd;

//	fd = open("1.test", O_WRONLY);

//	printf("%.20000Lf\n", LDBL_MIN);

	// ret = ft_printf("%f\n", 0.5625);
	// ft_printf("%d\n", ret);

	// ret = ft_printf("%d:%.*d:%.*d\n", 13, 51, 6, 45, 16);
	// printf("\nret=%d\n", ret);
	// ret = ft_printf("%2$d:%1$.*4$d:%4$.*3$d\n", 13, 51, 6, 45);
	// printf("\nret=%d\n", ret);

	ret = ft_printf("qwerty%cqwerty", 0);
	printf("\nret=%d", ret);
	fflush(stdout);
	ret = printf("qwerty%cqwerty", 0);
	printf("\nret=%d", ret);
	fflush(stdout);
//	close(fd);


	return (0);
}


/*
int main()
{
	int ret;
//	char s1[21]= {"qwert"};
//	printf(TXT, s1);
//	printf("\n%lc", LC_NUMERIC);

//	ret = ft_printf("% f", -5);
//	printf("\nret=%d\n", ret);

	long double aaa;
	aaa = 0.00000011;
	aaa = aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa;

	//  * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa * aaa;

//	double bbb = 0.0029166;
//	double bbb = 3.3264563657643576435764387567634265873465873465764376438756286457615872645872346586324;

	ret = printf("%.4000Lf", ((long double)(aaa)));
	printf("\nret=%d\n", ret);

//	ret = printf("%lf", ((double)(bbb)));
//	printf("\nret=%d\n", ret);

	// ret = printf("%.100le", bbb);
	// printf("\nret=%d\n", ret);

	// ret = printf("%.100lf", bbb);
	// printf("\nret=%d\n", ret);



//	fflush(stdout);

	return (0);
}*/


//int				main(void)
//{
//  ft_printf("\\n");
//  ft_printf("%%\\n");
//  ft_printf("%d\\n", 42);
//  ft_printf("%d%d\\n", 42, 41);
//  ft_printf("%d%d%d\\n", 42, 43, 44);
//  ft_printf("%ld\\n", 2147483647);
//  ft_printf("%lld\\n", 9223372036854775807);
//  ft_printf("%x\\n", 505);
//  ft_printf("%X\\n", 505);
//  ft_printf("%p\\n", &ft_printf);
//  ft_printf("%20.15d\\n", 54321);
//  ft_printf("%-10d\\n", 3);
//  ft_printf("% *.*d\\n", 5, 3, 3);
//  ft_printf("%+d\\n", 3);
//  ft_printf("%010d\\n", 1);
//  ft_printf("%hhd\\n", 0);
//  ft_printf("%jd\\n", 9223372036854775807);
//  ft_printf("%zd\\n", 4294967295);
//  ft_printf("%\\n");
//  ft_printf("%U\\n", 4294967295);
//  ft_printf("%u\\n", 4294967295);
//  ft_printf("%o\\n", 40);
//  ft_printf("%%#08x\\n", 42);
//  ft_printf("%x\\n", 1000);
//  ft_printf("%#X\\n", 1000);
//  ft_printf("%s\\n", NULL);
//  ft_printf("%S\\n", L"ݗݜशব");
//  ft_printf("%s%s\\n", "test", "test");
//  ft_printf("%s%s%s\\n", "test", "test", "test");
//  ft_printf("%f\\n", 0.45362456334563456);
//  ft_printf("%Lf", 4356.456345);
//  ft_printf("%lf", 4364564567546754.4536);
//  ft_printf("%C\\n", 15000);
//
//  return (0);
//}

