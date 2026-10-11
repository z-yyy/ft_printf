/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 18:43:23 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/10/11 14:50:55 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *argv, ...);
int				ft_conversion(char type, va_list *arg_ptr);
int				ft_putstr(const char *str);
unsigned long	ft_strlen(const char *str);
int				ft_putchar(char c);
int				ft_print_signed_num(int n, int *cnt);
int				ft_print_num_base(unsigned long n, const char type, int *cnt);
int				ft_print_pointer(void *ptr, int *cnt);

#endif
