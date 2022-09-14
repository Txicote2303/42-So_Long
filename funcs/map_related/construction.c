#include "so_long.h"

void	map_read(char	*path)
{
	int		fd;
	char	*temp;

	verification("ber", path);
	fd = open(path, O_RDONLY);
	temp = get_next_line(fd);
	map()->mapline = temp;
	verification("clean", "");
	printf("%s", map()->mapline);
	map_creator();
}

void	map_creator()
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
	map()->matrix = malloc(sizeof(char	*) * map()->sizey);
}

void	matrix_filler()
{

}