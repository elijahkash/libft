/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:04:10 by mtrisha           #+#    #+#             */
/*   Updated: 2020/03/17 14:20:06 by Kashnitskiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DIFF_UTILS_H
# define FT_DIFF_UTILS_H

# include <string.h>

# ifdef __linux__
#  include <stdint.h>
# endif

# define ABS(value) (((value) < 0) ? ((value) * (-1)) : (value))

void			ft_print_memory(const void *addr, size_t size);

void			ft_swap(void *p1, void *p2, size_t size);
void			*ft_memrev(void *mem, size_t size);

char			*ft_strdup(const char *s1);
void			ft_sfree(void *data, size_t size);
char			*ft_zerostr(void);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

size_t			ft_cwords(const char *str, int (*f)(int c));
size_t			ft_ccwords(const char *str, char c);
size_t			ft_findlwordlc(char const *s, char c);

void			ft_del_arr(void ***arr, size_t item_size);
int				ft_pow(int n, int pow);
void			ft_strset(char *str, char c, int len);
const char		*ft_skip_digits(const char *str);
char			*ft_skip_ws(const char *str);
int				check_base(char *base);
void			ft_getsnbr_base(long long int nbr, char *base, char *output);
void			ft_getunbr_base(unsigned long long int nbr, char *base,
									char *output);
void			ft_getunbr_goodbase(unsigned long long int nbr, char *base,
									__uint32_t baselen, char *output);

int				ft_write_unprint(int fd, char *str, size_t len);
int				ft_is_empty_str(char *str, size_t len);

int				ft_isdigit_ws(char *s);
char			*ft_skip_atoi(char *s);

void			ft_init_iarr(int ***arr, int row, int col);
void			ft_del_iarr(int **arr, int row);

#endif
