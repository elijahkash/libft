/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_input_gnl.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:47:12 by mtrisha           #+#    #+#             */
/*   Updated: 2019/12/11 21:29:28 by mtrisha          ###   ########.fr       */
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
