/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:07:56 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/03 22:52:49 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DYN_ARR_H
# define FT_DYN_ARR_H

# include <string.h>

# define DARRINIT_ERR_MSG \
	"[error] bad darr_init (developer's fail) args, aborting process."
# define DARRINIT_ERR_MSG_LEN (ft_strlen(DARRINIT_ERR_MSG))

typedef struct	s_darr
{
	void	*arr; //TODO: 1 || 2 * и подумать как все организовать
	size_t	item_size;
	size_t	curlen;
	size_t	max_len;
}				t_darr;

void			darr_init(t_darr *arr, size_t item_size, size_t init_len);
void			darr_del(t_darr *arr);

void			*darr(t_darr arr, size_t i);
size_t			darr_i(t_darr arr, void *item);
void			*darr_eq(t_darr arr, void *data, size_t i);
void			*darr_add(t_darr arr, void *data);
void			*darr_add_i(t_darr arr, void *data, size_t i);
void			*darr_pop(t_darr arr);
void			*darr_pop_i(t_darr arr, size_t i);
void			*darr_pop_p(t_darr arr, void *item);
//TODO: тут нужна функция сравнения? крч надо думать. и не забыть про gc
void			*darr_find(t_darr arr, void *data);
void			darr_sort(t_darr arr, int(*cmp)(const void *, const void *),
							void (*sort)(void *, size_t, size_t,
									int (*cmp)(const void *, const void *)));

/*
** void			*darr_cut(t_darr arr, size_t i);
*/

#endif
