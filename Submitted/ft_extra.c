/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:09:28 by druth             #+#    #+#             */
/*   Updated: 2021/11/04 14:09:28 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strconvert(char *output)
{
	int		track;

	if (output == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (output[0] == '\0')
		return (0);
	track = 0;
	while (output[track] != '\0')
		track++;
	write(1, output, track);
	return (track);
}

int	ft_hexiprint(char *output, unsigned long input, int track, char flag)
{
	int	temp;

	while (track >= 0)
	{
		temp = input % 16;
		if (temp >= 0 && temp <= 9)
			output[track--] = temp + '0';
		else if (temp >= 10 && temp <= 15)
		{
			if (flag == 'x')
				output[track--] = temp + 'a' - 10;
			else if (flag == 'X')
				output[track--] = temp + 'A' - 10;
		}
		input /= 16;
	}
	return (ft_strconvert(output));
}

int	ft_hexivert(unsigned int input, char flag)
{
	char			*output;
	int				track;
	unsigned int	temp;

	if (input == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	track = 0;
	temp = input;
	while (temp != 0 && track >= 0)
	{
		temp /= 16;
		track++;
	}
	output = (char *)malloc(sizeof(char) * (track + 1));
	if (output == NULL)
		return (-1);
	output[track] = '\0';
	track = ft_hexiprint(output, input, track - 1, flag);
	free(output);
	return (track);
}

int	ft_intprinter(int *hand, int track)
{
	char	store;
	int		temp;

	temp = track + 1;
	while (track >= 0)
	{
		store = '0' + hand[track];
		write(1, &store, 1);
		track--;
	}
	return (temp);
}

int	ft_unintconvert(unsigned int num)
{
	int	hand[10];
	int	track;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	track = 0;
	while (track <= 9 && num != 0)
	{
		hand[track] = num % 10;
		num /= 10;
		track++;
	}
	return (ft_intprinter(hand, track - 1));
}
