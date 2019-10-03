#include "libft.h"
# include <prf_printf_spec.h>

void handle_comma_intpart(char *output, int sep, int pos)
{
	int i;

	while (pos > 0)
	{
		i = 0;
		while (i < sep - 1 && pos > 0)
		{
			i++;
			pos--;
		}
		if (pos != 0 && output[pos - 1] != '-')
		{
			ft_memmove(&(output[pos + 1]), &(output[pos]), 1 + ft_strlen(&(output[pos])));
			output[pos] = ' ';
			pos--;
		}
	}
}


void handle_comma_fractpart(char *output, int sep, int pos)
{
	int i;

	while (ft_isdigit(output[pos]))
	{
		i = 0;
		while (i < sep && ft_isdigit(output[pos]))
		{
			i++;
			pos++;
		}
		if (ft_isdigit(output[pos]))
		{
			ft_memmove(&(output[pos + 1]), &(output[pos]), 1 + ft_strlen(&(output[pos])));
			output[pos] = ' ';
			pos++;
		}
	}
}

void handle_comma(char *output, t_specifications_def spec)
{
	int sep;
	char *dot;

	if (spec.spec == 7 || spec.spec == 8 || spec.spec == 12 || spec.spec == 14 || spec.spec == 15 ||
		spec.spec == 5 || spec.spec == 6)
		sep = 3;
	else if (spec.spec == 9 || spec.spec == 10)
		sep = 2;
	else if (spec.spec == 11)
		sep = 4;
	dot = ft_strchr(output, '.');
	if (dot == NULL)
		handle_comma_intpart(output, sep, ft_strlen(output) - 1);
	else
	{
		handle_comma_fractpart(output, sep, dot - output + 1);
		handle_comma_intpart(output, sep, dot - output - 1);
	}

}