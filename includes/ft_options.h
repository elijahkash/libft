/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:58:10 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/02 14:31:43 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

typedef unsigned long long int	t_options;

int								ft_is_option(const char *line);
int								ft_is_validopt(char *line);
t_options						ft_get_options(const char *line);

#endif
