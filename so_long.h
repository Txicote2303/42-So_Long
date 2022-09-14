/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:03:33 by frcarval          #+#    #+#             */
/*   Updated: 2022/09/08 01:57:26 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef	struct s_map {
	int		sizex;
	int		sizey;
	char	*mapline;
	char	**matrix;
}				t_map;

//general functions
void	error();
int	stringcmp(char	*str1, char	*str2);
//map functions
t_map	*map(void);
void	map_read(char	*path);
void	verification(char	*content, char	*extra);
void	ver_ber(char	*path);
void	ver_clean();
//GNL functions
char	*le_separateur(char **holy_one);
char	*get_next_line(int fd);
int		ft_strlen(char *wanna_be_counted);
char	*ft_substr(char *wanna_be_subed, int start, int len);
char	*ft_strdup(char *wanna_be_copied);
int		ft_strchr(char *wanna_be_analyzed, char treasure);
char	*ft_strjoin(char *goku, char *vegeta);

#endif
/*

Needed Stuff
- win_ptr
- mlx_ptr

- map Verifications
	- is_ber 			V
	- has_path
	- size
	- has_wall
	- has_character
	- has_collectable
	- has_finish
	- is_clean			V

- map stats
	- images
	- sizeX/Y
	- map_matrix

- player Stuff
	
*/