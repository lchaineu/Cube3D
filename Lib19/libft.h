#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdarg.h>

typedef struct        s_list
{
    void            *content;
    struct s_list    *next;
}                       t_list;

typedef struct    s_tab
{
    va_list        ap;
    
    char        *input;
    int            len;
    char        act_spec;
    int            width;
    int            precision;
    int            is_precision;
    int            minus;
    int            zero;
    int            negative;
    char        *answer;
    int            is_backslasho;
    int            is_width;
    
}                t_tab;

int	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const char *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char *ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
char *ft_strrchr(const char *s, int c);
int	ft_tolower(int c);
int	ft_toupper(int c);
void	*ft_calloc(size_t count, size_t size);
char *ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int     is_break(char *str);
int     read_line(int fd, char **line);
char    *before_break(char *line);
char    *after_break(char *line);
int     get_next_line(int fd, char **line);
char    *ft_strjoin_gnl(char *str1, char *str2);
int                ft_printf(const char *input, ...);
int                set(t_tab *tab, const char *input);
int                parsing(t_tab *tab);
int                find_spec(t_tab *tab, int i);
int                treat(t_tab *tab, int i);
int                which_spec(t_tab *tab);
void            width_finder(t_tab *tab, int i, int *maxrange);
void            precision_finder(t_tab *tab, int i, int *maxrange);
int                search_string(char c, char *str);
int                convert_c(t_tab *tab);
char            *ft_itoa_p(unsigned long long int nombre,
                           int base, char *charbase);
int                convert_u(t_tab *tab);
int                convert_x(t_tab *tab);
int                convert_big_x(t_tab *tab);
int                convert_d_i(t_tab *tab);
int                convert_p(t_tab *tab);
int                convert_s(t_tab *tab);
char            *strjoin_back(char *s1, char *s2);
char            *strjoin_front(char *s1, char *s2);
char            *addstrfront(t_tab *tab, char c, int len);
char            *addstrback(t_tab *tab, char c, int len);
void            stars_finder(t_tab *tab, int i, int maxrange);
int                set_again(t_tab *tab);
int                free_malloc_error(void *tofree, int toreturn);
char            *cut_str(char *str, int len);
int                convert_percent(t_tab *tab);
int                convert_u(t_tab *tab);
int                add_minus(t_tab *tab);
int                display_uxx(t_tab *tab);
int                d_width_no_minus(t_tab *tab);
int                display_d(t_tab *tab);
int                ft_strcmp(char *s1, char *s2);
char            *ft_strdup_printf(const char *str);
void            ft_pustr(char *str, t_tab *tab);
t_list                *ft_lstnew(void *content);
t_list                *ft_lstlast(t_list *lst);
t_list                *ft_lstmap(t_list *lst, void *(*f)(void *),
                                 void (*del)(void *));
void    ft_lstclear(t_list **lst, void (*del)(void*));
void    ft_lstadd_back(t_list **alst, t_list *new);

#endif
