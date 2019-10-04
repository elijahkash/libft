/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:01:52 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/04 14:19:16 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include <string.h>

void	ft_qsort(void *base, size_t nel, size_t width,
				int (*compar)(const void *, const void *));

void	ft_bublsort(void *base, size_t nel, size_t width,
				int (*cmp)(const void *, const void *));

#endif
