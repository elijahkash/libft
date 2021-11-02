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

#ifndef FT_COMPILER_H
# define FT_COMPILER_H

/*
** https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
** used for micro-optimization
*/
# define LIKELY(x)   __builtin_expect((x), 1)
# define UNLIKELY(x) __builtin_expect((x), 0)

#endif
