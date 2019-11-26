/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_manager.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:04:45 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 20:52:40 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_MANAGER_H
# define FT_MEMORY_MANAGER_H

# include <string.h>

# define INIT_MM_SIZE 128
# define MM_DIFF_FOR_TRIM 64
# define MM_MAX_INCREMENT 1024

void	ft_memman_init(void);
void	*ft_malloc(size_t size);
void	*ft_memman_malloc(size_t size);
void	*ft_remalloc(void *ptr, size_t oldsize, size_t newsize);
void	*ft_memman_remalloc(void *ptr, size_t newsize);
void	ft_free(void *ptr);
void	ft_memman_free(void *ptr);
void	ft_memman_clean(void);

#endif
