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
