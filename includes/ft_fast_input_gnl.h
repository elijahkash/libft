/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_input_gnl.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:47:12 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:54:42 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FAST_INPUT_GNL_H
# define FT_FAST_INPUT_GNL_H

# define FAST_INPUT_GNL_BUFF_SIZE 8192

typedef struct		s_buff_info
{
	char			*start;
	int				len;
}					t_buff_info;

int					ft_fast_input_gnl(char **line);

#endif
