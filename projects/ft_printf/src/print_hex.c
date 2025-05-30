/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhvosto <vkhvosto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:22:38 by vkhvosto          #+#    #+#             */
/*   Updated: 2024/11/29 09:22:39 by vkhvosto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, char spec)
{
	char	*base;
	char	*hex_str;
	int		count;

	if (spec == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	hex_str = number_to_hex(n, base);
	if (!hex_str)
		return (-1);
	count = ft_putstr(hex_str);
	free(hex_str);
	return (count);
}
