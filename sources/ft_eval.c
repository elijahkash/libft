/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:58:15 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/22 20:59:22 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_eval.h>

#include <libft.h>

static char	g_eval_mem[64];

void		*ft_i(int i)
{
	ft_memcpy(g_eval_mem, &i, sizeof(int));
	return (g_eval_mem);
}

void		*ft_z(size_t i)
{
	ft_memcpy(g_eval_mem, &i, sizeof(size_t));
	return (g_eval_mem);
}

void		*ft_li(long long int i)
{
	ft_memcpy(g_eval_mem, &i, sizeof(long long int));
	return (g_eval_mem);
}

void		*ft_c(char i)
{
	ft_memcpy(g_eval_mem, &i, sizeof(char));
	return (g_eval_mem);
}

void		*ft_p(void *p)
{
	if (p || !p)
		ft_bzero(g_eval_mem, sizeof(void *));
	return (g_eval_mem);
}
