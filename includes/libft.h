/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:15:30 by mtrisha           #+#    #+#             */
/*   Updated: 2019/11/09 19:38:04 by mtrisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define TURBO_MOD

# define FD_STDERR 2
# define FD_STDOUT 1
# define FD_STDIN 0

# include <string.h>

# include <ft_dyn_arr.h>
# include <ft_garbage_collector.h>
# include <ft_error.h>
# include <ft_sort.h>
# include <ft_outbuff.h>
# include <ft_outbuff_dst.h>
# include <ft_printf.h>
# include <ft_options.h>
# include <ft_eval.h>

# define ABS(value) (((value) < 0) ? ((value) * (-1)) : (value))
# define ABSINT(x) (((x) ^ ((x) >> 31)) - ((x) >> 31))
# define SWAP(a, b) ({(a) ^= (b); (b) ^= (a); (a) ^= (b);})
# define MAXINT(a, b) (b & ((a - b) >> 31) | a & (~(a - b) >> 31))
# define MININT(a, b) (a & ((a - b) >> 31) | b & (~(a - b) >> 31))
# define SAMESIGN(a, b) ((x ^ y) >= 0)
# define CHANGESIGN(i) ({i = ~i + 1; i = (i ^ -1) + 1})

int				ft_isws(int c);
size_t			ft_cwords(const char *str, int (*f)(int c));
size_t			ft_ccwords(const char *str, char c);
size_t			ft_findlwordlc(char const *s, char c);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

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

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list			*ft_lstfind(t_list *head, void *search_d,
							int (*f)(void *, void *));
void			ft_lstdelnode(t_list **alst, t_list **node,
							void (*del)(void*, size_t));

void			*ft_remalloc(void *ptr, size_t oldsize, size_t newsize);
void			ft_sfree(void *data, size_t size);

int				ft_get_next_line(const int fd, char **line);
void			ft_del_arr(void ***arr, size_t item_size);
int				ft_pow(int n, int pow);
void			ft_strset(char *str, char c, int len);
char			*ft_zerostr(void);
const char		*ft_skip_digits(const char *str);
void			ft_getsnbr_base(long long int nbr, char *base, char *output);
void			ft_getunbr_base(unsigned long long int nbr,
								char *base, char *output);
void			ft_print_memory(const void *addr, size_t size);

void			ft_swap(void *p1, void *p2, size_t size);

int				ft_icmp(const void *p1, const void *p2);
int				ft_ccmp(const void *p1, const void *p2);
int				ft_scmp(const void *p1, const void *p2);
int				ft_zcmp(const void *p1, const void *p2);

int				ft_write_unprint(int fd, char *str, size_t len);
int				ft_is_empty_str(char *str, size_t len);

typedef struct	s_str
{
	char	*str;
	size_t	len;
}				t_str;

t_str			*ft_tstrdup(t_str s);
size_t			ft_findlwordlf(t_str s, int (*f)(char));
size_t			ft_cfwords(t_str s, int (*f)(char));
t_str			**ft_tstrsplit(t_str s, int (*f)(char));
size_t			ft_strcmp_l(const char *s1, const char *s2);

long long int	ft_atoi_l(const char *str);
int				ft_isdigit_ws(char *s);
char			*ft_skip_atoi(char *s);

void			ft_init_iarr(int ***arr, int row, int col);
void			ft_del_iarr(int **arr, int row);

#endif
