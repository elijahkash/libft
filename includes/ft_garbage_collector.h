/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:04:45 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/15 16:49:35 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GARBAGE_COLLECTOR_H
# define FT_GARBAGE_COLLECTOR_H

# include <string.h>

# define INIT_GC_SIZE 128

void	ft_gc_init(void);
void	*ft_malloc(size_t size);
void	*ft_gcremalloc(void *ptr, size_t newsize);
void	ft_free(void *ptr);
void	ft_gc_clean(void);

#endif
