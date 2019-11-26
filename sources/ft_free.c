/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:52:52 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 19:30:27 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory_manager.h>

#include <ft_libft_mod.h>

#include <stdlib.h>

#ifdef USE_MEM_MAN

inline void	ft_free(void *ptr)
{
	ft_memman_free(ptr);
}

#else

inline void	ft_free(void *ptr)
{
	free(ptr);
}

#endif
