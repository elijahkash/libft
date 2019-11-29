/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:08:54 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/29 12:10:21 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQ_H
# define FT_DEQ_H

# include <string.h>

typedef struct	s_deq
{
	void	*mem;
	size_t	front;
	size_t	back;
	size_t	item_size;
	size_t	curlen;
	size_t	max_len;
}				t_deq;

#endif
