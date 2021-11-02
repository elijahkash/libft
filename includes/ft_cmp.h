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

#ifndef FT_CMP_H
# define FT_CMP_H

/*
** Funcs for compare diff types.
** Used in funcs like ft_qsort()
*/

int		ft_icmp(const void *p1, const void *p2);
int		ft_ccmp(const void *p1, const void *p2);
int		ft_scmp(const void *p1, const void *p2);
int		ft_zcmp(const void *p1, const void *p2);
int		ft_pcmp(const void *p1, const void *p2);

#endif
