/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:25:31 by druth             #+#    #+#             */
/*   Updated: 2021/11/06 12:25:31 by druth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_intconvert(int num);
int	ft_pointerconvert(unsigned long input);
int	ft_before(const char *str, int track, va_list input);
int	ft_driver(const char *str, va_list input, int total, int track);
int	ft_strconvert(char *output);
int	ft_hexiprint(char	*output, unsigned long input, int track, char flag);
int	ft_hexivert(unsigned int input, char flag);
int	ft_intprinter(int *hand, int track);
int	ft_unintconvert(unsigned int num);
int	ft_printf(const char *str, ...);

#endif
