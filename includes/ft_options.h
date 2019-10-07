/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:58:10 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/07 17:55:17 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTIONS_H
# define FT_OPTIONS_H

typedef unsigned long long int	t_options;

char							ft_check_opt(char *line, char *base);
int								ft_is_validopt(char *line);
t_options						ft_get_options(const char *line);

#endif
