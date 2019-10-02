/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_global_bak.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:24:55 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 20:06:36 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_BAK_H
# define GLOBAL_BAK_H

typedef struct	s_global_bak
{
	int		fd;
	int		arg_mode;
	char	*outstr;
}				t_global_bak;

t_global_bak	global_init(void);
void			global_restore(t_global_bak);

#endif
