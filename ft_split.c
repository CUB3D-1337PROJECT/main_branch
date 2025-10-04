/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:56:42 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/04 19:58:18 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static char	**free_allocation(char **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	if (!s)
		return (0);
	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static char	*copy_word(const char *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**split_words(char **new, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			new[j] = copy_word(s + i, c);
			if (!new[j])
				return (free_allocation(new, j));
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	new[j] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;

	if (!s)
		return (NULL);
	new = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	return (split_words(new, s, c));
}
