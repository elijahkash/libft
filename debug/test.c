/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:03:18 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 13:33:36 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <locale.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

#define TXT "%2$d:%1$.*4$d:%4$.*3$d\n", 13, 51, 6, 45

#include <fcntl.h>
#include <unistd.h>
#include "prf_double.h"
#include <ft_sort.h>

int icmp(const void *p1, const void *p2)
{
	return (*((char *)p2) - *((char *)p1));
}


int main()
{
	char arr[10] = {"f15705ktp\0"};

	ft_qsort(arr, 9, 1, &icmp);

	printf("%s\n", arr);
	return (0);
}

/*

int	testfunc(int fd)
{
	char str[50];

	ft_printf("%ywho is here? wow\n", str);
	ft_printf("%s", str);

	if (fd > 0)
	{
		ft_printf("%wstr test3 from func in file", fd);
	}
	return (11111);
};

int testdollar()
{
	ft_printf("%2$c%1$c%2$c", 'x', '\n');
	return (555);
}
/*
int main()
{
	int ret = 0;
	//long double ld;
	union u_double ud;

	char output[25000];

	//ud.s_parts.e = 0x7FFE;
	//ud.s_parts.m = 0x7FFFFFFFFFFFFFFF;


#define TXT ": %#.20LE\n", ud.ld
	ud.ld = LDBL_MAX;
	ft_printf(TXT);
	printf(TXT);

	char str[50];
	char *teststr;

	//teststr = (char*)malloc(10);
	str[0] = '\0';

	int fd1;
	int fd2;

	fd1 = open("test1", O_RDWR);
	fd2 = open("test2", O_RDWR);

	ft_printf("%ystr in str:%.20LE %d odin odin ", str, ud.ld, testfunc(-1));

	ft_printf("%wstr to test1, test func %d, %wstr to test2\n", fd1, testfunc(fd1), fd2);
	ft_printf("%s - test", str);


	ft_printf("%1$ystr with $, %w2$str3 in test1, \n%2$wstr4intest1, %3$wstr5in test2\n,", str, fd1, fd2);
	ft_printf("%s", str);

	ft_printf("\n-------\n");
	ft_printf("1st:%1$d, 4th:%4$d 2nd:%2$d, 1st:%1$d, 3rd:%3$s\n", 111, 222, "-333-", testdollar());
	close(fd1);
	close(fd2);

	ud.ld = LDBL_MIN;
//	ft_printf("LDBL_MIN = %.100Lf\n", ud.ld);
//	ft_printf("LDBL_MINe = %1$.100Le\n", ud.ld);
//	ft_printf("LDBL_MIN_E = %1$.50LE, %1$.50Le\n", ud.ld);

	teststr = NULL;
	ft_printf("%s %p\n", teststr, teststr);
	ud.ld = LDBL_MAX;
//	ft_printf("ft_pr:LDBL_MAX = %.100Lf\n", ud.ld);
//	ft_printf("LDBL_MAXe = %1$.100Le\n", ud.ld);
//	ft_printf("LDBL_MAX_E = %1$.50LE, %1$.50Le\n", ud.ld);

	ud.ld = 0.0;
	ft_printf("ft_pr:LDBL_0.0 = %.100Lf\n", ud.ld);
	ft_printf("LDBL_0.0e = %1$.100Le\n", ud.ld);
	ft_printf("LDBL_0.0_E = %1$.50LE, %1$.50Le\n", ud.ld);

	ud.ld = -0.0;
	ft_printf("ft_pr:LDBL_-0.0 = %.100Lf\n", ud.ld);
	ft_printf("LDBL_-0.0e = %1$.100Le\n", ud.ld);
	ft_printf("LDBL_-0.0_E = %1$.50LE, %1$.50Le\n", ud.ld);

	ud.ld = INFINITY;
	ft_printf("ft_pr:LDBL_INFINITY = %.100Lf\n", ud.ld);
	ft_printf("LDBL_INFINITYe = %1$.100Le\n", ud.ld);
	ft_printf("LDBL_INFINITY_E = %1$.50LE, %1$.50Le\n", ud.ld);
	printf("%LE\n", ud.ld);

	ud.ld = -INFINITY;
	ft_printf("-inf");
	ft_printf("ft_pr:LDBL_ = %.100Lf\n", ud.ld);
	ft_printf("LDBL_e = %1$.100Le\n", ud.ld);
	ft_printf("LDBL_E = %1$.50LE, %1$.50Le\n", ud.ld);
	printf("%LE\n", ud.ld);

	ud.ld = NAN;
	ft_printf("nan\n");
	ft_printf("ft_pr:LDBL_ = %.100Lf\n", ud.ld);
	ft_printf("LDBL_e = %1$.100Le\n", ud.ld);
	ft_printf("LDBL_E = %1$.50LE, %1$.50Le\n", ud.ld);
	printf("%LE %Le %Lf\n", ud.ld, ud.ld, ud.ld);

	ud.ld =-ud.ld;
	ft_printf("-nan\n");
	ft_printf("ft_pr:LDBL_ = %.100Lf\n", ud.ld);
	ft_printf("LDBL_e = %1$.100Le\n", ud.ld);
	ft_printf("LDBL_E = %1$.50LE, %1$.50Le\n", ud.ld);
	printf("%LE %Le %Lf\n", ud.ld, ud.ld, ud.ld);

	ud.ld = 1231231312321.123123123;
	printf("%Lf\n", ud.ld);

#define TXT1 14423435532L
#define TXT2
long double test = LDBL_MIN;

	ft_printf("f=%'.30000Lf\n", test);
	//ft_printf("f=%.30Lf\n", test);
	ft_printf("d=%'lld\n", TXT1);
	ft_printf("i=%'lli\n", TXT1);
	ft_printf("d=%'lld\n", -TXT1);
	ft_printf("i=%'lli\n", -TXT1);
	ft_printf("u=%'llu\n", TXT1);
	ft_printf("b=%'064llb\n", TXT1);
	ft_printf("o=%'llo\n", TXT1);
	ft_printf("x=%'llx\n", TXT1);
	ft_printf("X=%'llX\n", TXT1);



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

//	ret = ft_printf("qwerty%cqwerty", 0);
//	printf("\nret=%d", ret);
//	fflush(stdout);
//	ret = printf("qwerty%cqwerty", 0);
//	printf("\nret=%d", ret);
//	fflush(stdout);
//	close(fd);


	return (0);
}*/


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

