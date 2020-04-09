#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define FLAGS "-+ #*.0123456789hlLz"
# define BUFF_SIZE 1

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putchar(char c);
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t c);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_memdel(void **app);
void				ft_strdel(char **app);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t n);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c, int *num);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
int					ft_isspace(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
int					ft_digits(int n);
char				*ft_itoa(int n);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_ultoa(unsigned long n, int base);
char				*ft_ltoa(long n, int base);
void				ft_strupper(char *str);
void				ft_strlower(char *str);
char				*ft_ftoa(long double ld);
// char				*unsigned_itoa_base(uint32_t n, int base);
int					get_next_line(const int fd, char **line);

typedef struct		s_flag
{
	int			minus;
	int			plus;
	int			neg;
	int			sp;
	int			hash;
	int			zero;
	int			prec;
	int			width;
	int			dr;
	int			pos;
}					t_flag;

typedef enum		e_len_mod
{
	pf_mod = 0,
	pf_h,
	pf_hh,
	pf_l,
	pf_ll,
	pf_z,
	pf_L
}					t_len_mod;

typedef struct		s_list
{
	va_list		ap;
	char		*out;
	t_len_mod	mod;
	t_flag		flag;
	int			fd;
	int			i;
	int			ret;
}					t_list;

int					ft_printf(const char *format, ...);

void				ft_extra(const char *format, t_list *env);
void				ft_extra_color(const char *format, t_list *env);

void				ft_convert_width(t_list *env);
void				ft_convert_prec(const char *f, t_list *env);
void				ft_convert_flag(const char *f, t_list *env);
void				ft_convert_spec(const char *f, t_list *env);
void				ft_convert(const char *f, t_list *env);

void				ft_flag_init(t_flag *f);
void				ft_flag_len_mod(const char *f, t_list *env);
void				ft_flag_perc(t_list *env);

void				ft_check_int(t_list *env);
void				ft_check_unsint(t_list *env);
void				ft_check_char(t_list *env, char t);
void				ft_check_lchar(t_list *env, char t);
void				ft_check_ptr(t_list *env);

void				ft_check_numb(t_list *env, char t);
void				ft_check_double(t_list *env, char t);

void				ft_print_nonprnt(t_list *env);

void				ft_print_null_s(t_list *env);
void				ft_print_null_c(t_list *env);
void				ft_print_c(t_list *env, char c);
void				ft_print_s(t_list *env);

void				ft_print_ptr(t_list *env);

void				ft_print_numb(t_list *env, char t, long int num);

void				ft_print_digits(t_list *env);
void				ft_print_digits_neg(t_list *env);

void				ft_print_f(t_list *env, long double ld);
long				ft_print_f_num(t_list *env, long double ld, int p);
void				ft_print_f_prec(t_list *env, long double ld);
void				ft_print_feg_width(t_list *env);

void				ft_print_e(t_list *env, long double ld, char t);
long				ft_print_e_num(long double ld, int p);
void				ft_print_e_exp(long double ld, char t, char **let);
char				*ft_print_efg_str(char *str1, int pnt, int end, int hash);
void				ft_print_e_prec(t_list *env, long double ld, char t);

void				ft_print_g(t_list *env, long double ld, char t);
void				ft_print_g_check(t_list *env, long double ld, char t);
void				ft_print_g_f(t_list *env, long double ld, int end);
void				ft_print_g_e(t_list *env, long double ld, char t, int p);
void				ft_print_g_del(char *tmp);

#endif