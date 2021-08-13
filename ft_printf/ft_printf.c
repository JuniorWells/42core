#include "ft_printf.h"

void	put_ptr(unsigned long num, int base_len, char *base)
{
	int	i;

	if (num / base_len != 0)
		put_ptr(num / base_len, base_len, base);
	i = num % base_len;
	write(1, &base[i], 1);
}

int	type_id(char c, va_list args)
{
	int	bytes;

	bytes = 0;
	if (c == 'c')
		bytes = if_char(args);
	else if (c == 's')
		bytes = if_str(args);
	else if (c == 'd' || c == 'i')
		bytes = if_int(args);
	else if (c == 'p')
		bytes = if_addr(args);
	else if (c == 'u')
		bytes = if_unsi(args);
	else if (c == 'x')
		bytes = if_hex(args);
	else if (c == 'X')
		bytes = if_hexU(args);
	else if (c == '%')
		bytes = if_per();
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		chars_pr;

	i = 0;
	chars_pr = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			++chars_pr;
		}
		else
		{
			++i;
			chars_pr += type_id(format[i], args);
		}
		++i;
	}
	va_end(args);
	return (chars_pr);
}

// int main(void)
// {
//     // char *str = "mykonos";
// 	int i;
// 	unsigned long l = 1928123;
//     // printf("%d\n", printf("mykonos"));
// 	i = ft_printf("%x\n", l);
// 	i = ft_printf("%x\n", l);
// 	ft_printf("%d\n", i);
// 	printf("%d\n", i);
//     return (0);
// }