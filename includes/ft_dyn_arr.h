/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:07:56 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/03 16:23:33 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DYN_ARR_H
# define FT_DYN_ARR_H

# include <string.h>

typedef struct	s_darr
{
	void	**arr;
	size_t	item_size;
	size_t	curlen;
	size_t	mem_size;
}				t_darr;

t_darr			darr_new(size_t item_size, size_t init_len);
void			darr_del(t_darr *arr);

void			*darr(t_darr arr, size_t i);
void			*darr_eq(t_darr arr, void *item, size_t i);
void			*darr_add(t_darr arr, void *item);
void			*darr_add_i(t_darr arr, void *item, size_t i);
void			*darr_pop(t_darr arr);
void			*darr_pop_i(t_darr arr, size_t i);
void			*darr_cut(t_darr arr, size_t i);
size_t			darr_find(t_darr arr, void *item);
void			darr_sort(t_darr arr, int(*f)(void *, void *));

#endif
