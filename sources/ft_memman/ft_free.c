/* ************************************************************************** */
/*                                                                            */
/*   Copyright (C) 2021 Ilya Kashnitskiy.                                     */
/*   Contact: elijahkash.code@gmail.com                                       */
/*                                                                            */
/*   This file is part of the LIBFT project                                   */
/*   https://github.com/elijahkash/libft                                      */
/*                                                                            */
/*   MIT License Usage                                                        */
/*   This file may be used under the terms of the MIT License.                */
/*   Check LICENSE included in the packaging of this file.                    */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory_manager.h"

#include "ft_libft_mod.h"

#include <stdlib.h>

#ifdef USE_MEM_MAN

inline void	ft_free(void *ptr)
{
	ft_memman_free(ptr);
}

#else

inline void	ft_free(void *ptr)
{
	free(ptr);
}

#endif
