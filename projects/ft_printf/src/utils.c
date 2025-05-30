/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhvosto <vkhvosto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:22:54 by vkhvosto          #+#    #+#             */
/*   Updated: 2024/11/29 09:22:55 by vkhvosto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*utoa(unsigned int n)
{
	char			*str;
	unsigned int	num;
	int				len;

	num = n;
	len = 1;
	while (num / 10 > 0)
	{
		num /= 10;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*number_to_hex(uintptr_t num, const char *base)
{
	char		*result;
	int			length;
	uintptr_t	temp;

	if (num == 0)
		return (ft_strdup("0"));
	length = 0;
	temp = num;
	while (temp > 0)
	{
		temp /= 16;
		length++;
	}
	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[length] = '\0';
	while (length > 0)
	{
		result[--length] = base[num % 16];
		num /= 16;
	}
	return (result);
}
