/* ************************************************************************** */
/*                                                                            */
/*   Copyright (C) 2021 Ilya Kashnitskiy.                                     */
/*   Contact: elijahkash.code@gmail.com                                       */
/*                                                                            */
/*   This file is part of the LIBFT project                                   */
/*   https://github.com/elijahkash/libft                                      */
/*                                                                            */
/*   MIT License Usage                                                        */
/*   This file may be used under the terms of the MIT License.                */
/*   Check LICENSE included in the packaging of this file.                    */
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
