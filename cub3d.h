/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:34 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/04 21:29:47 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	25
# endif

typedef struct s_count
{
	int	nb_no_tex;
	int	nb_su_tex;
	int	nb_we_tex;
	int	nb_ea_tex;
	int	nb_flour;
	int	nb_ceiling;
	int	nb_players;
}				t_count;

typedef struct s_cub3d
{
	char	*no_tex;
	char	*su_tex;
	char	*ea_tex;
	char	*ws_tex;
	char	flour[3];
	char	ceiling[3];
	t_count	counters;
	char	**map;
	int		map_lenth;
	int		map_width;
	int		player_x;
	int		player_y;
	char	player_view;
}				t_cub3d;

void	ft_putstr_fd(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
//void	ft_putendl_fd(char	*s, int fd);
char	**ft_split(char const *s, char c);
void	free_split(char	**str);
void	*ft_calloc(size_t	count, size_t	size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char	*s1);
char	*ft_strjoin(char const *s1, char const	*s2);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const	*s, unsigned int start, size_t	len);
int		ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
int		parsing(int	argc, char	**argv, t_cub3d	*data);
int		check_extention(char	*str, char	*exten);
#endif
