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

#ifndef FT_ERROR_H
# define FT_ERROR_H

# define ERRTYPE_WARNING "\033[33;1m[warning] \033[0m"
# define ERRTYPE_ERROR "\033[31;1m[error] \033[0m"

# define ERRACT_NONE ""
# define ERRACT_ABORT "aborting process.\n"

# define MSG_MEMALLOC "memory allocation failed, "
# define MSG_MEMFREE "free memory not allocated by malloc.\n"
# define MSG_DARR "bad darr args, "

# define ERR_MEMALLOC_MSG ERRTYPE_ERROR MSG_MEMALLOC ERRACT_ABORT
# define ERR_MEMFREE_MSG ERRTYPE_WARNING MSG_MEMFREE
# define ERR_DARR_MSG ERRTYPE_ERROR MSG_DARR ERRACT_ABORT

void	ft_error_exit(const char *msg, int exit_code);
void	ft_error_free_exit(const char *msg, int exit_code);
void	ft_error_print(const char *msg);

#endif
