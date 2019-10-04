/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:04:45 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 20:00:54 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GARBAGE_COLLECTOR_H
# define FT_GARBAGE_COLLECTOR_H

# include <string.h>

# define INIT_GC_SIZE 1024
# define MEMALLOC_ERR_MSG \
	"[error] memory allocation failed, aborting process.\n"
# define MEMALLOC_ERR_MSG_LEN (ft_strlen(MEMALLOC_ERR_MSG))
# define MEMFREE_ERR_MSG \
	"[error] free memory not allocated by malloc.\n"
# define MEMFREE_ERR_MSG_LEN (ft_strlen(MEMFREE_ERR_MSG))

void	ft_gc_init(void);
void	*ft_malloc(size_t size);
void	ft_free(void *ptr);
void	ft_gc_clean(void);

#endif
