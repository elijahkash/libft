/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:31:08 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:54:21 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TSTR_H
# define FT_TSTR_H

# include <string.h>

typedef struct	s_str
{
	char	*str;
	size_t	len;
}				t_str;

t_str			*ft_tstrdup(t_str s);
size_t			ft_findlwordlf(t_str s, int (*f)(char));
size_t			ft_cfwords(t_str s, int (*f)(char));
t_str			**ft_tstrsplit(t_str s, int (*f)(char));

#endif
