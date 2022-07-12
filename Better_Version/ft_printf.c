#include "ft_printf.h"

int	ft_strconvert(char *str, int track)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[track] != '\0')
		track++;
	write(1, str, track);
	return (track);
}

int	ft_hexivert(unsigned long num, char type, int track, int check)
{
	char output[16];

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num != 0)
	{
		check = num % 16;
		if (check < 10)
			output[track] = '0' + check;
		else
			output[track] = type + (check % 10);
		track--;
		num /= 16;
	}
	write(1, &output[track + 1], 15 - track);
	return (16 - track - 1);
}

int	ft_pointerconvert(unsigned long input)
{
	if (input == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + ft_hexivert(input, 'a', 15, 0));
}

int	ft_before(const char *str, int track, va_list input, char output)
{
	if (str[track] == 'd' || str[track] == 'i')
		return (ft_intconvert(va_arg(input, int)));
	else if (str[track] == 's')
		return (ft_strconvert(va_arg(input, char *), 0));
	if (str[track] == 'u')
		return (ft_numconvert(va_arg(input, unsigned int), 9));
	else if (str[track] == 'c')
	{
		output = va_arg(input, int);
		write(1, &output, 1);
		return (1);
	}
	else if (str[track] == 'x')
		return (ft_hexivert(va_arg(input, unsigned int), 'a', 15, 0));
	else if (str[track] == 'X')
		return (ft_hexivert(va_arg(input, unsigned int), 'A', 15, 0));
	else if (str[track] == '%')
		return (write(1, "%%", 1));
	else if (str[track] == 'p')
		return (ft_pointerconvert((unsigned long int)(va_arg(input, void *))));
	write(1, "%%", 1);
	write(1, &str[track], 1);
	return (2);
}

int	ft_printf(const char *str, ...)
{
	va_list	input;
	int		total;
	int		track;

	total = 0;
	track = -1;
	va_start(input, str);
	while (str[++track] != '\0')
	{
		if (str[track] != '%' && str[track] != '\0')
		{
			write(1, &str[track], 1);
			total++;
		}
		else if (str[track] == '%' && str[++track] != '\0')
			total += ft_before(str, track, input, ' ');
		else if (str[track - 1] == '%' && str[track] == '\0')
		{
			va_end(input);
			return (-1);
		}
	}
	va_end(input);
	return (total);
}
