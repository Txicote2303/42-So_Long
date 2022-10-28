/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:03:33 by frcarval          #+#    #+#             */
/*   Updated: 2022/10/27 16:31:58 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53
# define ENTER 36
# define WKEY 13
# define AKEY 0
# define SKEY 1
# define DKEY 2

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_slave
{
	char	*temp;
	int		counter;
	int		another_counter;
	int		indx;
}	t_slave;

typedef struct s_img
{
	//t_window	*win;
	void		*img_ptr;
	char		*path;
	int			height;
	int			width;
}		t_img;

typedef struct s_gnl
{
	char	*line;
	int		counter;
	int		size;
}	t_gnl;

typedef	struct s_map {
	int		sizex;
	int		sizey;
	int		moves;
	char	*mapline;
	char	**matrix;
}				t_map;

typedef	struct s_mapcp {
	int		sizex;
	int		sizey;
	int		moves;
	int		px;
	int		py;
	int		initialx;
	int		initialy;
	char	**matrix;
}				t_mapcp;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_window;

//general functions
void	error(char	*string);
int	stringcmp(char	*str1, char	*str2);
int	string_size(char	*string);
char	*my_dup(char	*string);
char	*nl_rmv(char	*string);
//map functions
t_map	*map(void);
t_mapcp	*mapcp(void);
void	map_repro(void);
void	map_findp(void);
int		map_check();
void	ver_fill(int x, int y);
void	map_read(char	*path);
void	verification(char	*content, char	*extra);
void	ver_ber(char	*path);
void	ver_clean();
void 	ver_square();
void	ver_size();
void	ver_wall();
void	ver_stuff();
void	ver_viable();
int	ver_col();
void	putstr(char *string);
void	map_creator(char	*path);
void	matrix_filler(char	*path);
//MLX functions
t_window	*window(void);
t_img	*img(void);
void	putimg(void);
void	new_window();
int		close_mlx();
int	move_up();
int		key_handle(int key, t_window	*mainw);
//GNL functions
char	*get_next_line(int fd);
char	*get_whole_line(int fd);
char	*ft_slave(char *line, char *master, int line_size);
int		ft_finder(char *str, char chr, int selector);

#endif
/*

Needed Stuff
- win_ptr
- mlx_ptr

- map Verifications
	- is_ber 			V
	- has_path			
	- size				v
	- has_wall			v
	- has_character		V
	- has_collectable	V
	- has_finish		V
	- is square			V
	- is_clean			V

- map stats
	- images
	- sizeX/Y
	- map_matrix

- player Stuff
	
*/