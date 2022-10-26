#include "so_long.h"

void	map_read(char	*path)
{
	int		fd;
	char	*temp;

	verification("ber", path);
	fd = open(path, O_RDONLY);
	temp = get_whole_line(fd);
	map()->mapline = temp;
	verification("clean", "");
	//test
	//printf("%s\n", map()->mapline);
	map_creator(path);
}

void	map_creator(char	*path)
{
	int	counter;

	counter = 0;
	map()->sizey = 1;
	while(map()->mapline[counter])
	{
		if(map()->mapline[counter] == '\n')
			map()->sizey++;
		counter++;
	}
	map()->matrix = malloc(sizeof(char	*) * map()->sizey + 1);
	matrix_filler(path);
}

void	matrix_filler(char	*path)
{
	int		fd;
	char	*temp;
	int	countery;
	int	counterx;

	counterx = 0;
	countery = 0;
	fd = open(path, O_RDONLY);
	while(countery < (map()->sizey + 1))
	{
		temp = nl_rmv(get_next_line(fd));
		map()->matrix[countery] = malloc ((sizeof(char) * my_len(temp) + 1));
		while(temp[counterx])
		{
			map()->matrix[countery][counterx] = temp[counterx];
			counterx++;
		}
		map()->matrix[countery][counterx] = '\0';
		free(temp);
		countery++;
	}
	verification("square", "");
	verification("size", "");
	verification("wall", "");
	verification("stuff", "");
	verification("viable", "");
}
/*
void	matrix_filler()
{
	int	counter;
	int	counterx;
	int	countery;
	
	counter = 0;
	counterx = 0;
	countery = 0;
	while(map()->mapline[counter])
	{
		if(map()->mapline[counter] == '\n')
		{
			map()->matrix[counterx][countery] = '\0';
			counterx = -1;
			countery++;
		}
		else
			map()->matrix[counterx][countery] = map()->mapline[counter];
		counterx++;
		counter++;
	}
	map()->matrix[counterx][countery] = '\0';
	printf("\n\n\n");
	counterx = 0;
	countery = 0;
	while(map()->matrix[counterx][countery])
	{
		while(map()->matrix[counterx][countery])
		{
			printf("%c\n", map()->matrix[counterx][countery]);
			counterx = 0;
		}
		counterx++;
		countery = 0;
	}*/
