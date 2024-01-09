/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:53:19 by bberkrou          #+#    #+#             */
/*   Updated: 2024/01/09 15:59:22 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	print_nonformat_char(const char **format)
{
	ft_putchar(**format);
	(*format)++;
	return (1);
}

int	handle_format(const char **format, va_list *args, t_dec *charsets)
{
	int	char_count;

	(*format)++;
	if (!(**format))
		ft_putchar_fd('%', 1);
	if (**format == '%')
	{
		ft_putchar('%');
		(*format)++;
		return (1);
	}
	else if (ft_strchr("cspdiuxX", **format))
	{
		char_count = ft_put_va(args, charsets, **format);
		if (**format)
			(*format)++;
		return (char_count);
	}
	else
	{
		write(1, "%%", 1);
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_dec		*charsets;
	va_list		args;
	int			lenght;

	if (!format)
		return (-1);
	charsets = init_charset();
	if (!charsets)
		return (-1);
	lenght = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			handle_format(&format, &args, charsets);
		else
			lenght += write(1, format, 1);
	}
	va_end(args);
	return (lenght);
}
