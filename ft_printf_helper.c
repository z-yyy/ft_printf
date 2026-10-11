/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:00:03 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/10/11 14:53:15 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_strlen(const char *str)
{
	unsigned long	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_signed_num(int n, int *cnt)
{
	long	number;
	char	c;

	number = n;
	if (number < 0)
	{
		write(1, "-", 1);
		number *= -1;
		(*cnt)++;
	}
	if (number >= 10)
	{
		ft_print_signed_num(number / 10, cnt);
		ft_print_signed_num(number % 10, cnt);
	}
	else
	{
		c = number + '0';
		write(1, &c, 1);
		(*cnt)++;
	}
	return (*cnt);
}
//base = "0123456789";
//base = "0123456789abcdef";
//base = "0123456789ABCDEF";

int	ft_print_num_base(unsigned long n, const char type, int *cnt)
{
	unsigned long	base_len;
	char			*base;

	if (type == 'x')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	else if (type == 'u')
		base = "0123456789";
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_print_num_base(n / base_len, type, cnt);
		ft_print_num_base(n % base_len, type, cnt);
	}
	else
	{
		write(1, &base[n], 1);
		(*cnt)++;
	}
	return (*cnt);
}
//ptr = 0x1234; hexadecimal
//ptr_address = 4660; decimal
//gerekirse nullu ele al

int	ft_print_pointer(void *ptr, int *cnt)
{
	unsigned long	ptr_address;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ptr_address = (unsigned long) ptr;
	write(1, "0x", 2);
	(*cnt) += 2;
	return (ft_print_num_base(ptr_address, 'x', cnt));
}
