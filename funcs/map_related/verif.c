#include "so_long.h"

void	verification(char	*content, char	*extra)
{
	if(stringcmp(content, "ber") == 1)
		ver_ber(extra);
	else if(stringcmp(content, "clean") == 1)
		ver_clean();
	else if(stringcmp(content, "square") == 1)
		ver_square();
	else if(stringcmp(content, "size") == 1)
		ver_size();
	else if(stringcmp(content, "wall") == 1)
		ver_wall();
	else if(stringcmp(content, "stuff") == 1)
		ver_stuff();
	else if(stringcmp(content, "viable") == 1)
		ver_viable();
	else
		error("Non existent verification");
}

void	ver_ber(char	*path)
{
	int	counter;

	counter = 0;
	while(path[counter])
		counter++;
	if(path[--counter] != 'r')
		error("Wrong map file type");
	if(path[--counter] != 'e')
		error("Wrong map file type");
	if(path[--counter] != 'b')
		error("Wrong map file type");
	if(path[--counter] != '.')
		error("Wrong map file type");
}

void	ver_clean()
{
	int	counter;

	counter = 0;
	while(map()->mapline[counter++])
		if(map()->mapline[counter] != '1' && map()->mapline[counter] != '0' &&
			map()->mapline[counter] != 'C' && map()->mapline[counter] != 'P' &&
			map()->mapline[counter] != 'E' && map()->mapline[counter] != '\n' &&
			map()->mapline[counter] != '\0')
			error("Map with unsupported characters");
}

int	ver_col()
{
	int	counterx;
	int	countery;


	counterx = 0;
	countery = 0;
	while(countery < map()->sizey)
	{
		while(counterx < map()->sizex)
		{
			if(map()->matrix[countery][counterx] == 'C')
				return(0);
			counterx++;
		}
		countery++;
		counterx = 0;
	}
	return(1);
}

void ver_square()
{
	int	counter;
	int	temp;

	counter = 1;
	temp = string_size(map()->matrix[0]);
	//printf("%s\n", map()->matrix[0]);
	while (map()->matrix[counter])
	{
		//printf("%d\n", string_size(map()->matrix[counter]));
		//printf("%s\n", map()->matrix[counter]);
		if(temp != string_size(map()->matrix[counter]))
			error("Map is not rectangular");
		counter++;
	}
	map()->sizex = temp;
}
void	ver_size()
{
	if((map()->sizex < 3 && map()->sizey < 5) || (map()->sizex < 5 && map()->sizey < 3))
		error("Map is too small");
}

void	ver_wall()
{
	int	counterx;
	int	countery;

	counterx = -1;
	while(++counterx < map()->sizex)
		if(map()->matrix[0][counterx] != '1')
			error("Has no wall all arround");
	countery = -1;
	while(++countery < map() ->sizey)
		if(map()->matrix[countery][0] != '1')
			error("Has no wall all arround");
	counterx = -1;
	while(++counterx < map()->sizex)
		if(map()->matrix[map()->sizey - 1][counterx] != '1')
			error("Has no wall all arround");
	countery = -1;
	while(++countery < map()->sizey)
		if(map()->matrix[countery][map()->sizex - 1] != '1')
			error("Has no wall all arround");
}

void	ver_stuff()
{
	int	has_character;
	int	has_collectible;
	int	has_finish;
	int	counter;

	has_character = 0;
	has_collectible = 0;
	has_finish = 0;
	counter = -1;
	while(map()->mapline[++counter])
	{
		if(map()->mapline[counter] == 'P')
			has_character++;
		if(map()->mapline[counter] == 'C')
			has_collectible++;
		if(map()->mapline[counter] == 'E')
			has_finish++;
	}
	if(has_character != 1 || has_finish != 1 || has_collectible < 1)
		error("A  asset is present in unsupported quantity");
}

void	ver_viable()
{
	map_repro();
}