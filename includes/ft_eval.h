/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:57:19 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/21 18:09:05 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVAL_H
# define FT_EVAL_H

# include <string.h>

/*
** Write for t_vect, t_deq ...
** turns value to pointer to that value!
*/

void		*ft_i(int i);
void		*ft_z(size_t i);
void		*ft_lli(long long int i);
void		*ft_c(char i);
void		*ft_p(void *p);

#endif
