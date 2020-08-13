/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coline <coline@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:40:38 by cfaure-g          #+#    #+#             */
/*   Updated: 2020/08/07 11:47:04 by coline           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 42

# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct	s_param
{
	char		data_type;
	int			is_minus;
	char		is_plus;
	int			s_nb;
	char		is_symbol;
	int			is_p;
	int			p_nb;
	int			nb_printed;
	int			is_hash;
}				t_param;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap
						(t_list *lst, void *(*f)(void *), void (*del)(void*));

/*
**GNL
*/

int					ft_find_endl(char *str);
char				*ft_cut(char **str, int len);
void				ft_free_safe(char **str);
int					ft_store_line(char **line, char **temp, char **str);
int					ft_process(char **buf, char **line, int read_ret);
int					get_next_line(int fd, char **line);

/*
** PRINTF
*/

int				ft_putchar_printf(char c, t_param *datas);
int				ft_process_integer(va_list *args, t_param *datas);
int				ft_print_int(t_param *datas, int *tab, long nb_long);
int				ft_print_int2(t_param *datas, int *tab, long nb_long);
int				ft_print_char(va_list *args, t_param *datas);
int				ft_process_str(va_list *args, t_param *datas);
int				ft_print_str(t_param *datas, char *s);
int				ft_is_data_type(char c);
int				ft_is_flag(char c);
void			ft_putchar_ptr(t_param *datas, long int nbr, int hexa_len);
int				ft_ptr_len(long long int nbr, t_param *datas);
int				ft_process_ptr(va_list *args, t_param *datas);
int				ft_process_ptr(va_list *args, t_param *datas);
void			ft_print_ptr(t_param *datas, long int nbr, int *tab);
size_t			ft_intlen(int n);
int				ft_putnbr_unsigned(unsigned int nb, t_param *datas);
int				ft_putnbr_base(long long int nbr, char *base, t_param *datas);
void			ft_print_unsigned(t_param *datas, int *tab);
int				ft_process_unsigned(va_list *args, t_param *datas);
int				ft_process_hexa(va_list *args, t_param *datas);
void			ft_print_hexa(t_param *datas, int *tab);
int				ft_hexa_len(long long int nbr, t_param *datas);
int				ft_process_n(va_list *args, t_param *datas);
int				ft_get_nb(const char *str, va_list *args, int *index,
t_param *datas);
void			ft_process_flags1(const char *str, int index, va_list *args,
t_param *datas);
void			ft_process_flags2(const char *str, int index, va_list *args,
t_param *datas);
int				ft_process_data(const char *str, int index, va_list *args,
t_param *datas);
t_param			ft_initialize(t_param *datas);
int				ft_printf(const char *str,
...) __attribute__((format(printf,1,2)));

#endif
