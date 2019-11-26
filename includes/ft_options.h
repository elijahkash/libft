/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:58:10 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 19:54:44 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTIONS_H
# define FT_OPTIONS_H

typedef unsigned long long int	t_options;

int								ft_is_option(const char *line);
char							ft_check_opt(char *line, char *base);
t_options						ft_get_options(const char *line);
t_options						ft_get_opt_bit(const char c);

#endif
