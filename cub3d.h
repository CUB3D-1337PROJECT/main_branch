/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:34 by slakhrou          #+#    #+#             */
/*   Updated: 2025/11/21 13:55:12 by slakhrou         ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
// # include "/home/slakhrou/Desktop/MLX42/include/MLX42/MLX42.h"
#include <math.h>
//# include "MLX42/include/MLX42/MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	25
# endif
#define HEIGHT 720
#define WIDTH 1040
#define BLOCK_SIZE 64
#define XMIN 0

typedef struct s_playerinfo
{

  mlx_image_t *player_img;
  char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_y;
	double	plane_x;
} t_playerinfo;

typedef struct  s_rayinfo
{
    double	dir_x;
	double	dir_y;
    double  raystart_x;
    double  raystart_y;
	double	camera_x;
	double	camera_y;
	double	dest_x;
	double	dest_y;
	double	step_x;
	double	step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	wall_dest;
	double	wall_x;
    double  tex_step;
    double  tex_pos;
	int 	map_x;
	int 	map_y;
	int	    line_h;
	int	    start_draw;
	int	    draw_end;
	int	    side;
    int     tex_x;
    int     tex_y;
    mlx_image_t *playerv_img;
} t_rayinfo;

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}				t_list;

typedef struct s_count
{
	int	nb_no_tex;
	int	nb_so_tex;
	int	nb_we_tex;
	int	nb_ea_tex;
	int	nb_flour;
	int	nb_ceiling;
	int	nb_players;
}			t_count;

typedef struct s_textures
{
	mlx_texture_t	*text_no;
	mlx_texture_t	*text_so;
	mlx_texture_t	*text_ea;
	mlx_texture_t	*text_we;
}				t_textures;

typedef struct s_texture_colors
{
    uint32_t	*pix_buff;
    uint32_t	color;
    uint32_t	offset;
    uint8_t     r;   
    uint8_t     g;   
    uint8_t     b;   
    uint8_t     a;   
}   t_texture_colors;

typedef struct s_cub3d
{
    mlx_t			*mlx;
    mlx_image_t		*img;
	t_playerinfo	player;
	t_rayinfo		ray;
	char			*no_tex;
	char			*so_tex;
	char			*ea_tex;
	char			*we_tex;
	int				*flour;
	uint32_t		rgb_color_flour;
	int				*ceiling;
	uint32_t		rgb_color_ceiling;
	t_count			counters;
	char			**map;
	t_textures		*texts;
	mlx_texture_t	*curr_texture;
    int              tex_width;
    int              tex_height;
	int				map_length;
	int				map_width;
	int				player_x;
	int				player_y;
	char			player_view;
}				t_cub3d;

int     is_empty(char	*line);
void    free_allocation(char **arr, int j);
int	    is_not_map(char	*s);
void    putstr_fd(char	*s, int fd);
void    ft_putchar_fd(char c, int fd);
char    *ft_copy(char	*s1);
char    **ft_split(char	*s, char	*charset);
void    free_allocation(char **arr, int j);
void    free_split(char	**str);
void    *ft_calloc(size_t	count, size_t	size);
size_t  ft_strlen(const char *str);
char    *ft_strdup(const char	*s1);
char    *ft_strjoin(char const *s1, char const	*s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const	*s, unsigned int start, size_t	len);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char	*str, const char	*substr, size_t len);
int		ft_atoi(const char	*str);
int		ft_isdigit(int c);
int		parse_int(char	*s);
char	*get_next_line(int fd, char f);
int		check_data_texture(t_cub3d	*data, char	*line);
int		count_elment(char	**str);
int		parsing(int argc, char	**argv, t_cub3d	*data);
int		check_extention(char	*str, char	*exten);
int		fill_texture(char	*line, char	**splits, t_cub3d	*data);
int		check_rgb(char	**split_colors, int rgb[3], char	*color);
int		check_two_commas(char	*color);
char	*find_identifier(char	*first_split);
int		parse_map(char	*line, int fd, t_cub3d	*data);
int		get_max_width(t_list	*lst);
int		is_space_neighbour(char	**map, int i, int j);
int		is_valid_content(char c);
int		validate_map(t_cub3d	*data, int columns);
void	free_list(t_list	**lst);
void	free_cub3d(t_cub3d	*data);
int		load_textures(t_cub3d	*data);
void	delete_textures(t_textures	*textures);
void	delete_textures(t_textures	*textures);
void	ft_append(t_list	**lst, char	*line);
int		is_only_spaces(char	*line);
int			check_img_extention(char *str, char *exten);
uint32_t	create_trgb(int r, int g, int b,int a);
int		parse_rgb_values(char	*color, int	**rgb);
void	assign_floor_color(int	*rgb, t_cub3d	*data);
void	assign_ceiling_color(int	*rgb, t_cub3d	*data);
void  	cub_handel_events(t_cub3d *data);
void  	move_right(t_cub3d *data);
void  	move_left(t_cub3d *data);
void  	move_forward(t_cub3d *data);
void  	move_backward(t_cub3d *data);
void  	rotate_right(t_cub3d *data);
void  	rotate_left(t_cub3d *data);
void  	ft_clean(t_cub3d *data, char *err_type, char *err_msg, int err_exit);
void  	raycasting(t_playerinfo *player, t_cub3d *data);
void	set_dda(t_cub3d *data);

#endif
