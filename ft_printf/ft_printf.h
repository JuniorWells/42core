#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		type_id(char c, va_list args);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
int		if_char(va_list args);
int		if_str(va_list args);
int		if_per(void);
int		if_int(va_list args);
int		if_addr(va_list args);
int		if_unsi(va_list args);
int		if_hex(va_list args);
int		if_hexU(va_list args);
int		int_length(long int num);
void	put_ptr(unsigned long num, int base_len, char *base);
int		len_base(unsigned long num, int length);

#endif
