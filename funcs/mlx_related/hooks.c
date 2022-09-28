#include "so_long.h"

int	move_up()
{
	int	counterx = 0;
	int	countery = 0;
	while(countery < map()->sizey)
	{
		while(counterx < map()->sizex)
		{
			if(map()->matrix[countery][counterx] == 'P')
			{
				//printf("\n\n\n%c\n\n\n", map()->matrix[countery][counterx]);
				if(map()->matrix[countery - 1][counterx] == '1' || (map()->matrix[countery - 1][counterx] == 'E' && ver_col() == 0))
					return(0);
				if(map()->matrix[countery - 1][counterx] == 'E' && ver_col() == 1)
				{
					close_mlx(window());
					return(0);
				}
				map()->matrix[countery][counterx] = '0';
				map()->matrix[countery - 1][counterx] = 'P';
			}
			//printf("%c\n", map()->matrix[countery][counterx]);
			counterx++;
		}
		//printf("\n\n\n");
		countery++;
		counterx = 0;
	}return(0);
}

int	move_down()
{
	int	counterx = 0;
	int	countery = 0;
	while(countery < map()->sizey)
	{
		while(counterx < map()->sizex)
		{
			if(map()->matrix[countery][counterx] == 'P')
			{
				//printf("\n\n\n%c\n\n\n", map()->matrix[countery][counterx]);
				if(map()->matrix[countery + 1][counterx] == '1' || (map()->matrix[countery + 1][counterx] == 'E' && ver_col() == 0))
					return(0);
				if(map()->matrix[countery + 1][counterx] == 'E' && ver_col() == 1)
				{
					close_mlx(window());
					return(0);
				}
				map()->matrix[countery][counterx] = '0';
				map()->matrix[countery + 1][counterx] = 'P';
			}
			//printf("%c\n", map()->matrix[countery][counterx]);
			counterx++;
		}
		//printf("\n\n\n");
		countery++;
		counterx = 0;
	}return(0);
}

int	move_left()
{
	int	counterx = 0;
	int	countery = 0;
	while(countery < map()->sizey)
	{
		while(counterx < map()->sizex)
		{
			if(map()->matrix[countery][counterx] == 'P')
			{
				//printf("\n\n\n%c\n\n\n", map()->matrix[countery][counterx]);
				if(map()->matrix[countery][counterx - 1] == '1' || (map()->matrix[countery][counterx - 1] == 'E' && ver_col() == 0))
					return(0);
				if(map()->matrix[countery][counterx - 1] == 'E' && ver_col() == 1)
				{
					close_mlx(window());
					return(0);
				}
				map()->matrix[countery][counterx] = '0';
				map()->matrix[countery][counterx - 1] = 'P';
			}
			//printf("%c\n", map()->matrix[countery][counterx]);
			counterx++;
		}
		//printf("\n\n\n");
		countery++;
		counterx = 0;
	}return(0);
}

int	move_right()
{
	int	counterx = 0;
	int	countery = 0;
	while(countery < map()->sizey)
	{
		while(counterx < map()->sizex)
		{
			if(map()->matrix[countery][counterx] == 'P')
			{
				//printf("\n\n\n%c\n\n\n", map()->matrix[countery][counterx]);
				if(map()->matrix[countery][counterx + 1] == '1' || (map()->matrix[countery][counterx + 1] == 'E' && ver_col() == 0))
					return(0);
				if(map()->matrix[countery][counterx + 1] == 'E' && ver_col() == 1)
				{
					close_mlx(window());
					return(0);
				}
				map()->matrix[countery][counterx] = '0';
				map()->matrix[countery][counterx + 1] = 'P';
			}
			//printf("%c\n", map()->matrix[countery][counterx]);
			counterx++;
		}
		//printf("\n\n\n");
		countery++;
		counterx = 0;
	}return(0);
}

int	key_handle(int key, t_window	*mainw)
{
	//int	counter = 0;
	(void)mainw;
	if (key == ESC)
		close_mlx(window());
	if (key == WKEY)
		move_up();
	if (key == AKEY)
		move_left();
	if (key == SKEY)
		move_down();
	if (key == DKEY)
		move_right();
	
	// while (map()->matrix[counter])
	// {
	// 	printf("%s\n", map()->matrix[counter]);
	// 	counter++;
	// }
	// printf("\n");
	putimg();
	return(0);
}