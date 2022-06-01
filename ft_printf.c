/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:09:28 by druth             #+#    #+#             */
/*   Updated: 2021/11/04 14:09:28 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intconvert(int num)
{
	unsigned int	input;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		input = -1 * num;
		return (ft_unintconvert(input) + 1);
	}
	input = num;
	return (ft_unintconvert(input));
}

int	ft_pointerconvert(unsigned long input)
{
	char			*output;
	int				track;
	unsigned long	temp;

	if (input == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	track = 0;
	temp = input;
	while (temp != 0 && track++ >= 0)
		temp /= 16;
	output = (char *)malloc(sizeof(char) * (track + 1));
	if (output == NULL)
		return (-1);
	output[track--] = '\0';
	track = ft_hexiprint(output, input, track, 'x');
	free(output);
	return (track + 2);
}

int	ft_before(const char *str, int track, va_list input)
{
	char	output;

	if (str[track] == 'd' || str[track] == 'i')
		return (ft_intconvert(va_arg(input, int)));
	else if (str[track] == 's')
		return (ft_strconvert(va_arg(input, char *)));
	if (str[track] == 'u')
		return (ft_unintconvert(va_arg(input, unsigned int)));
	else if (str[track] == 'c')
	{
		output = va_arg(input, int);
		return (write(1, &output, 1));
	}
	else if (str[track] == 'x' || str[track] == 'X')
		return (ft_hexivert(va_arg(input, unsigned int), str[track]));
	else if (str[track] == '%')
		return (write(1, "%%", 1));
	else if (str[track] == 'p')
		return (ft_pointerconvert((unsigned long int)(va_arg(input, void *))));
	else if (str[track] != '\0')
		return (write(1, &str[track], 1));
	return (-10);
}

int	ft_driver(const char *str, va_list input, int total, int track)
{
	int	check;

	check = 0;
	while (str[track] != '\0')
	{
		if (str[track] == '%')
		{
			check = ft_before(str, track + 1, input);
			if (check == -1)
				return (-1);
			if (check >= 0)
			{
				track++;
				total += check;
			}
		}
		else
		{
			write(1, &str[track], 1);
			total++;
		}
		track++;
	}
	va_end(input);
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	input;
	int		total;
	int		track;

	total = 0;
	track = 0;
	va_start(input, str);
	return (ft_driver(str, input, total, track));
}
