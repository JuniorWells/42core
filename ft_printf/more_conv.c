#include "ft_printf.h"

int	if_unsi(va_list args)
{
	unsigned int	num;
	int				ret;

	num = va_arg(args, unsigned int);
	ret = len_base(num, 10);
	put_ptr(num, 10, "0123456789");
	return (ret);
}

int	if_hex(va_list args)
{
	unsigned int	num;
	int				ret;

	num = va_arg(args, unsigned long);
	ret = len_base(num, 16);
	put_ptr((unsigned long)num, 16, "0123456789abcdef");
	return (ret);
}

int	if_hexU(va_list args)
{
	unsigned int	num;
	int				ret;

	num = va_arg(args, unsigned long);
	ret = len_base(num, 16);
	put_ptr((unsigned long)num, 16, "0123456789ABCDEF");
	return (ret);
}

int	int_length(long int num)
{
	int	len;

	len = 1;
	if (num < 0)
	{
		++len;
		num = -num;
	}
	while (num / 10)
	{
		++len;
		num = num / 10;
	}
	return (len);
}

int	len_base(unsigned long num, int length)
{
	int	len;

	len = 1;
	while (num / length)
	{
		++len;
		num = num / length;
	}
	return (len);
}
