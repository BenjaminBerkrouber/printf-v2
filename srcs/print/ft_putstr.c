/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <bberkrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:38:19 by bberkrou          #+#    #+#             */
/*   Updated: 2024/01/09 15:57:25 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (string && *string)
		*length += write(1, string++, 1);
}

size_t	ft_putstr_va(va_list *args, char charset)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
		return (ft_putstr("(null)"));
	(void)charset;
	ft_putstr(str);
	return (ft_strlen(str));
}

size_t	ft_putchar_va(va_list *args, char charset)
{
	char	c;

	(void)charset;
	c = (char)va_arg(*args, int);
	ft_putchar(c);
	return (1);
}
