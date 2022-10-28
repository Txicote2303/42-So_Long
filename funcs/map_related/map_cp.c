#include "so_long.h"

void	map_repro(void)
{
	int	counterx;
	int	countery;

	counterx = 0;
	countery = 0;
	mapcp()->sizex = map()->sizex;
	mapcp()->sizey = map()->sizey;
	mapcp()->matrix = malloc(sizeof(char	*) * map()->sizey + 1);
	while(countery < mapcp()->sizey)
	{
		mapcp()->matrix[countery] = malloc(sizeof(char) * map()->sizex + 1);
		while(counterx < mapcp()->sizex)
		{
			mapcp()->matrix[countery][counterx] = map()->matrix[countery][counterx];
			counterx++;
		}
		mapcp()->matrix[countery][counterx] = '\0';
		counterx = 0;
		countery++;
	}
}

void	map_findp(void)
{
	int	counterx;
	int	countery;
	
	counterx = 0;
	countery = 0;
	while(countery < map()->sizey)
	{
		while(mapcp()->matrix[countery][counterx])
		{
			if(mapcp()->matrix[countery][counterx] == 'P')
			{
				mapcp()->px = counterx;
				mapcp()->py = countery;
			}
			counterx++;
		}
		counterx = 0;
		countery++;
	}
	printf("%i\n", counterx);
}

int map_check()
{
	int	counterx;
	int	countery;

	countery = 1;
	while (countery < map()->sizey)
	{
		counterx = 1;
		while (mapcp()->matrix[countery][counterx])
		{
			if (mapcp()->matrix[countery][counterx] == 'E')
				return (1);
			else if (mapcp()->matrix[countery][counterx] == 'C')
				return (1);
			counterx++;
		}
		countery++;
	}
	return (0);
}

void	ver_fill(int x, int y)
{
	mapcp()->matrix[y][x] = 'V';
	if (mapcp()->matrix[y][x + 1] != '1' && mapcp()->matrix[y][x + 1] != 'V')
		ver_fill(x+1, y);
	if (mapcp()->matrix[y][x-1] != '1' && mapcp()->matrix[y][x - 1] != 'V')
		ver_fill(x-1, y);
	if (mapcp()->matrix[y+1][x] != '1' && mapcp()->matrix[y +1 ][x] != 'V')
		ver_fill(x, y + 1);
	if (mapcp()->matrix[y - 1][x] != '1' && mapcp()->matrix[y - 1][x] != 'V')
		ver_fill(x, y -1);
}