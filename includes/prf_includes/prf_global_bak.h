/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_global_bak.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:24:55 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:55:16 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRF_GLOBAL_BAK_H
# define PRF_GLOBAL_BAK_H

typedef struct	s_global_bak
{
	int		fd;
	int		arg_mode;
	char	*outstr;
}				t_global_bak;

t_global_bak	global_init(void);
int				global_restore(t_global_bak bak);

#endif
