/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:55:06 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/06 15:38:04 by slakhrou         ###   ########.fr       */
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
		return (malloc(1));
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
	while (i < ft_strlen(s1))
	{
		if ((unsigned char ) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char ) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
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
