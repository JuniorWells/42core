#include "ft_printf.h"

int	if_int(va_list args)
{
	int		ret;
	long	num;

	num = va_arg(args, int);
	ret = int_length(num);
	ft_putnbr_fd(num, 1);
	return (ret);
}

int	if_char(va_list args)
{
	char	c;
	int		ret;

	c = va_arg(args, int);
	ret = 1;
	write(1, &c, 1);
	return (ret);
}

int	if_str(va_list args)
{
	char	*str;
	int		ret;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		ret = 6;
		return (ret);
	}
	ret = ft_strlen(str);
	write(1, str, ret);
	return (ret);
}

int	if_per(void)
{
	int		ret;
	char	c;

	c = '%';
	ret = 1;
	write(1, &c, ret);
	return (ret);
}

int	if_addr(va_list args)
{
	void	*p;
	int		ret;

	p = va_arg(args, void *);
	if (!p)
	{
		write(1, "0x0", 3);
		ret = 3;
		return (ret);
	}
	else
	{
		ret = len_base((unsigned long)p, 16) + 2;
		write(1, "0x", 2);
		put_ptr((unsigned long)p, 16, "0123456789abcdef");
		return (ret);
	}
}
