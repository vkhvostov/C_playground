/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhvosto <vkhvosto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:22:47 by vkhvosto          #+#    #+#             */
/*   Updated: 2024/11/29 09:22:48 by vkhvosto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int number)
{
	char	*str;
	int		count;

	str = utoa(number);
	if (!str)
		return (-1);
	count = write(1, str, ft_strlen(str));
	free(str);
	return (count);
}
