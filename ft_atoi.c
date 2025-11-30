/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:51:56 by slakhrou          #+#    #+#             */
/*   Updated: 2025/11/29 20:55:32 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	parse_int(char	*s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] && s[j] != '0')
		j++;
	if (j > 3)
		return (1);
	if (!s || s[0] == '\0')
		return (1);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i] != '\0')
		return (1);
	return (0);
}

static	int	over_long(long number, char c, int sign)
{
	if (number >= (LONG_MAX - (c - '0')) / 10)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char	*str)
{
	int		i;
	int		sign;
	long	number;
	int		over_check;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		over_check = over_long(number, str[i], sign);
		if (over_check != 1)
			return (over_check);
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}
