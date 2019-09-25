/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:05:16 by mtrisha           #+#    #+#             */
/*   Updated: 2019/09/25 13:33:50 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_OUTPUT_H
# define PRINT_OUTPUT_H

# include <ft_printf_spec.h>

void	prepare_spec(t_specifications_def *spec);
void	handle_comma_flag(char **output);
int		print_output(t_specifications_def spec, char **output);

#endif
