/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:56:42 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/16 15:02:42 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *s, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], charset))
			i++;
		if (s[i])
			count++;
		while (s[i] && !is_sep(s[i], charset))
			i++;
	}
	return (count);
}

static char	*copy_word(char *s, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (s[len] && !is_sep(s[len], charset))
		len++;
	word = malloc(len + 1);
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

static char	**split_words(char **split, char *s, char *charset)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], charset))
			i++;
		if (s[i])
		{
			split[j] = copy_word(s + i, charset);
			if (!split[j])
				return (free_allocation(split, j), NULL);
			j++;
		}
		while (s[i] && !is_sep(s[i], charset))
			i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char	*s, char	*charset)
{
	char	**split;

	if (!s || !charset)
		return (NULL);
	split = malloc((count_words(s, charset) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (split_words(split, s, charset));
}
