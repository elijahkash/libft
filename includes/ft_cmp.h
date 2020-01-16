/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:40:51 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:54:48 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CMP_H
# define FT_CMP_H

int		ft_icmp(const void *p1, const void *p2);
int		ft_ccmp(const void *p1, const void *p2);
int		ft_scmp(const void *p1, const void *p2);
int		ft_zcmp(const void *p1, const void *p2);
int		ft_pcmp(const void *p1, const void *p2);

#endif
