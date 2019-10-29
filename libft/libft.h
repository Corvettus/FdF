/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:01:51 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 23:12:40 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void				*ft_memset(void *dst, int n, size_t len);
void				ft_bzero(void *b, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *arr1, const void *arr2, size_t n);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(long long int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(long long int n, int fd);
size_t				ft_strlen(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t num);
char				*ft_strncat(char *dst, const char *ptr, size_t num);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strchr(const char *str, int symbol);
char				*ft_strcat(char *dst, const char *ptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(unsigned long long int n);
int					ft_count_num(long n);
int					ft_get_word_len(char const *str, char c);
int					ft_countwords(char const *str, char c);
char				*ft_strrev(char *str);
char				*ft_capitalize(char *s);
size_t				ft_strclen(const char *s, int c);
char				*ft_strdel1join(char *s1, char *s2);
void				ft_putnbr_hex(unsigned int n);
void				ft_putnbr_uns(unsigned int n);
void				ft_putnbr_big(unsigned long long n);
int					ft_count_num_big(long n);
void				ft_putnbr_8(unsigned int n);
void				ft_putnbr_hex_upper(long n);
int					ft_10_to_8(long n);
int					ft_10_to_16(unsigned int n);
int					ft_10_to_8_long(unsigned long long n);
int					ft_10_to_16_long(unsigned long long n);
int					ft_count_num_long_long(unsigned long long n);
int					ft_count_num_long(long long n);
int					ft_count_num_16(unsigned int n);
void				ft_putnbr_hex_long(unsigned long long n);
void				ft_putnbr_hex_long_upper(unsigned long long n);
int					ft_count_num_8(unsigned int n);
void				ft_putnbr_8_long(unsigned long long int n);
int					ft_power(int a);
int					ft_isnumber(char *str);
int					ft_abs(int i);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
