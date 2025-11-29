/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:55:06 by slakhrou          #+#    #+#             */
/*   Updated: 2025/11/28 20:49:33 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*p;
	size_t	i;
	char	*s;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	if (count == 0 || size == 0)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	i = 0;
	s = (char *) p;
	while (i < count * size)
	{
		s[i] = 0;
		i++;
	}
	return (p);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	free_split(char	**str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*ft_strnstr(const char	*str, const char	*substr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*substr == '\0')
		return ((char *)str);
	while (i < len && str[i])
	{
		if (str[i] == substr[0])
		{
			j = 0;
			while (substr[j] && (i + j) < len && str[i + j] == substr[j])
				j++;
			if (substr[j] == '\0')
				return ((char *) &str[i]);
		}
		i++;
	}
	return (NULL);
}
