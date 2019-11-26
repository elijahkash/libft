/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_macro.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:12:36 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/26 19:50:01 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIT_MACRO_H
# define FT_BIT_MACRO_H

# define ABS(value) (((value) < 0) ? ((value) * (-1)) : (value))
# define ABSINT(x) (((x) ^ ((x) >> 31)) - ((x) >> 31))
# define ABS_LLU(x) (((x) ^ ((x) >> 63)) - ((x) >> 63))
# define SWAP(a, b) ({(a) ^= (b); (b) ^= (a); (a) ^= (b);})
# define MAXINT(a, b) ((b) & (((a) - (b)) >> 31) | (a) & (~((a) - (b)) >> 31))
# define MININT(a, b) ((a) & (((a) - (b)) >> 31) | (b) & (~((a) - (b)) >> 31))
# define SAMESIGN(a, b) (((x) ^ (y)) >= 0)
# define GETBIT(n, m) (((n) >> (m)) & 1)
# define SETBIT(n, m) ((n) | (1 << (m)))
# define RESETBIT(n, m) ((n) & ~(1 << (m)))
# define GETBIT_LLU(n, m) (((n) >> (m)) & 1LLU)
# define SETBIT_LLU(n, m) ((n) | (1LLU << (m)))
# define RESETBIT_LLU(n, m) ((n) & ~(1LLU << (m)))
# define BSR_ASM(n) asm("bsfq\t%0, %0" : "+rm" (n))

#endif
