/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff_dst.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:41:12 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/07 12:19:40 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTBUFF_DST_H
# define FT_OUTBUFF_DST_H

# define FD_STDERR 2
# define FD_STDOUT 1
# define FD_STDIN 0

void			ft_set_g_outstr(char *ptr);
void			ft_set_g_outfd(int value);

int				ft_get_g_outfd(void);
char			*ft_get_g_outstr(void);

#endif
