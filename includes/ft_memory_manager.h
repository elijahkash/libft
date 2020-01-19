/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_manager.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:04:45 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/19 16:36:27 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_MANAGER_H
# define FT_MEMORY_MANAGER_H

# include <string.h>

# define INIT_MM_SIZE 128
# define MM_DIFF_FOR_TRIM 64
# define MM_MAX_INCREMENT 1024

# ifndef MEMERR_CODE
#  define MEMERR_CODE 0
# endif

void	ft_memman_init(void);
void	*ft_malloc(size_t size);
void	*ft_memman_malloc(size_t size);
void	*ft_remalloc(void *ptr, size_t oldsize, size_t newsize);
void	*ft_nomm_remalloc(void *ptr, size_t oldsize, size_t newsize);
void	*ft_memman_remalloc(void *ptr, size_t newsize);
void	ft_free(void *ptr);
void	ft_memman_free(void *ptr);
void	ft_memman_clean(void);

#endif
