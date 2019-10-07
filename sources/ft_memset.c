/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:01:59 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/07 12:32:28 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#ifdef TURBO_MOD

void	*ft_memset(void *b, int c, size_t len)
{
	return (memset(b, c, len));
}

#else

void	*ft_memset(void *b, int c, size_t len)
{
	while (len)
		((char *)b)[--len] = (unsigned int)c;
	return (b);
}

#endif
