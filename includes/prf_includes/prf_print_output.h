/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_output.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:05:16 by mtrisha           #+#    #+#             */
/*   Updated: 2020/01/16 13:55:00 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRF_PRINT_OUTPUT_H
# define PRF_PRINT_OUTPUT_H

# include <prf_printf_spec.h>

void	prepare_spec(t_specifications_def *spec);
int		print_output(t_specifications_def spec, char **output);

#endif
