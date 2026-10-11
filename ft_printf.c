/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 23:21:43 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/10/11 14:45:27 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//ft_printf("Benim yasim %d", 24);
// argv -> "Benim yasim %d" (string),
//ft_printf("%d %s", 42, "buffer");argv
// |
// v
// "%d %s"

//arg_ptr(ilk argümandan sonrasını alır, tipi herhangi bir değişken olabilir)
// |
// v

// +------+--------+
// | 42   |"buffer"|
// +------+--------+Kullanımı:

// va_arg(arg_ptr, TIP)
//
//
// Örnek :
//
// int number;
//
// number = va_arg(arg_ptr, int);
//va_arg her çağrıldığında sıradaki argümana ilerler

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_conversion(char t, va_list *arg_ptr)
{
	int	count;

	count = 0;
	if (t == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	else if (t == 's')
		return (ft_putstr(va_arg(*arg_ptr, char *)));
	else if (t == 'c')
		return (ft_putchar(va_arg(*arg_ptr, int)));
	else if (t == 'p')
		return (ft_print_pointer(va_arg(*arg_ptr, void *), &count));
	else if (t == 'd' || t == 'i')
		return (ft_print_signed_num(va_arg(*arg_ptr, int), &count));
	else if (t == 'u' || t == 'x' || t == 'X')
		return (ft_print_num_base(va_arg(*arg_ptr, unsigned int), t, &count));
	else
		return (0);
}

int	ft_printf(const char *argv, ...)
{
	va_list	arg_ptr;
	int		result;

	result = 0;
	va_start(arg_ptr, argv);
	while (*argv)
	{
		if (*argv == '%')
		{
			argv++;
			result += ft_conversion(*argv, &arg_ptr);
		}
		else
		{
			write(1, &(*argv), 1);
			result++;
		}
		argv++;
	}
	va_end(arg_ptr);
	return (result);
}
