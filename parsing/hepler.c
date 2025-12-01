/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hepler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:36:09 by slakhrou          #+#    #+#             */
/*   Updated: 2025/11/30 17:26:09 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_path(char	*line, char	*ident)
{
	char	*pos;
	char	*path;
	size_t	len;
	char	*new_path;

	pos = ft_strnstr(line, ident, ft_strlen(line));
	if (!pos)
		return (NULL);
	pos += ft_strlen(ident);
	while (*pos && (*pos == ' ' || *pos == '\t'))
		pos++;
	path = ft_strdup(pos);
	if (!path)
		return (NULL);
	len = ft_strlen(path);
	while (len > 0 && (path[len - 1] == ' '
			|| path[len - 1] == '\t' || path[len - 1] == '\n'))
		path[--len] = '\0';
	new_path = ft_substr(path, 0, len);
	free(path);
	if (is_empty(new_path))
		return (free(new_path),
			putstr_fd("Error\ninvalid path texture\n", 2), NULL);
	return (new_path);
}
