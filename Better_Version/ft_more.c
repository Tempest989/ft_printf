#include "ft_printf.h"

int	ft_numconvert(unsigned int num, int track)
{
	char output[10];

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num != 0)
	{
		output[track] = '0' + (num % 10);
		track--;
		num /= 10;
	}
	write(1, &output[track + 1], 9 - track);
	return (10 - track - 1);
}

int	ft_intconvert(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		return (1 + ft_numconvert(num * -1, 9));
	}
	return (ft_numconvert(num, 9));
}
