/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhvosto <vkhvosto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:22:40 by vkhvosto          #+#    #+#             */
/*   Updated: 2024/11/29 09:22:41 by vkhvosto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(int n)
{
	int	count;

	count = 0;
	return (ft_putnbr(n, &count));
}
