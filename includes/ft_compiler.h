/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compiler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:41:11 by Kashnitskiy       #+#    #+#             */
/*   Updated: 2020/01/23 15:41:44 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPILER_H
# define FT_COMPILER_H

/*
** https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
** used for micro-optimization
*/
# define LIKELY(x)   __builtin_expect((x), 1)
# define UNLIKELY(x) __builtin_expect((x), 0)

#endif
