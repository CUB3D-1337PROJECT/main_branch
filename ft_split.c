/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:56:42 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/07 15:48:43 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// static char	**free_allocation(char **str, int j)
// {
// 	int	i;

// 	i = 0;
// 	while (i < j)
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// 	return (NULL);
// }

// static int	count_words(char const *s, char c)
// {
// 	int	i;
// 	int	words;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	words = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		if (s[i] != '\0')
// 			words++;
// 		while (s[i] && s[i] != c)
// 			i++;
// 	}
// 	return (words);
// }

// static char	*copy_word(const char *s, char c)
// {
// 	int		len;
// 	int		i;
// 	char	*word;

// 	len = 0;
// 	while (s[len] && s[len] != c)
// 		len++;
// 	word = (char *)malloc((len + 1) * sizeof(char));
// 	if (!word)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		word[i] = s[i];
// 		i++;
// 	}
// 	word[i] = '\0';
// 	return (word);
// }

// static char	**split_words(char **new, const char *s, char c)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		if (s[i] != '\0')
// 		{
// 			new[j] = copy_word(s + i, c);
// 			if (!new[j])
// 				return (free_allocation(new, j));
// 			j++;
// 		}
// 		while (s[i] && s[i] != c)
// 			i++;
// 	}
// 	new[j] = NULL;
// 	return (new);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**new;

// 	if (!s)
// 		return (NULL);
// 	new = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
// 	if (!new)
// 		return (NULL);
// 	return (split_words(new, s, c));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:12:42 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/07 17:12:42 by slakhrou         ###   ########.fr       */
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

static void	free_allocation(char **arr, int j)
{
	while (j-- > 0)
		free(arr[j]);
	free(arr);
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

char	**ft_split(char	*s, char	*charset)
{
	char	**split;
	int		i;
	int		j;

	if (!s || !charset)
		return (NULL);
	split = malloc((count_words(s, charset) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
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
	return (split[j] = NULL, split);
}
