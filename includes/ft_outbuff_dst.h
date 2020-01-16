/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff_dst.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:41:12 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:54:25 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTBUFF_DST_H
# define FT_OUTBUFF_DST_H

void			ft_set_g_outstr(char *ptr);
void			ft_set_g_outfd(int value);

int				ft_get_g_outfd(void);
char			*ft_get_g_outstr(void);

#endif
