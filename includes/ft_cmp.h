/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:40:51 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/21 18:10:17 by Kashnitskiy      ###   ########.fr       */
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
