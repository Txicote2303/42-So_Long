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
			printf("%c", map()->matrix[countery][counterx]);
			counterx++;
		}
		printf("\n");
		mapcp()->matrix[countery][counterx] = '\0';
		counterx = 0;
		countery++;
	}

	while(counterx < mapcp()->sizex)
	{
		printf("sizex: %i\n", map()->sizex);
		printf("counterx: %i\n", counterx);
		printf("sizey: %i\n", map()->sizey);
		printf("countery: %i\n", countery);
		mapcp()->matrix[countery][counterx++] = '\0';
	}
}