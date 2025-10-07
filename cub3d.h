/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:34 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/07 20:25:46 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<unistd.h>
# include<stdlib.h>
#include <stdint.h>
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
	int	nb_so_tex;
	int	nb_we_tex;
	int	nb_ea_tex;
	int	nb_flour;
	int	nb_ceiling;
	int	nb_players;
}				t_count;

typedef struct s_cub3d
{
	char	*no_tex;
	char	*so_tex;
	char	*ea_tex;
	char	*we_tex;
	int		*flour;
	int		*ceiling;
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
//char	**ft_split(char const *s, char c);
char	**ft_split(char	*s, char	*charset);
void	free_split(char	**str);
void	*ft_calloc(size_t	count, size_t	size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char	*s1);
char	*ft_strjoin(char const *s1, char const	*s2);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const	*s, unsigned int start, size_t	len);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char	*str, const char	*substr, size_t len);
int		ft_atoi(const char	*str);
int		ft_isdigit(int c);
int		parse_int(char	*s);
char	*get_next_line(int fd);
int		check_data_texture(t_cub3d	*data);
int		count_elment(char	**str);
int		parsing(int	argc, char	**argv, t_cub3d	*data);
int		check_extention(char	*str, char	*exten);
int		fill_texture(char	*line, char	**splits, t_cub3d	*data);
int		check_rgb(char	**split_colors, int	rgb[3]);
char	*find_identifier(char	*first_split);
void	free_cub3d(t_cub3d	*data);
#endif
