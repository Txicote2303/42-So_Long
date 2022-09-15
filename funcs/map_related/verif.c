#include "so_long.h"

void	verification(char	*content, char	*extra)
{
	if(stringcmp(content, "ber") == 1)
		ver_ber(extra);
	if(stringcmp(content, "clean") == 1)
		ver_clean();
	if(stringcmp(content, "square") == 1)
		ver_square();
	if(stringcmp(content, "size") == 1)
		ver_size();
}

void	ver_ber(char	*path)
{
	int	counter;

	counter = 0;
	while(path[counter])
		counter++;
	if(path[--counter] != 'r')
		error();
	if(path[--counter] != 'e')
		error();
	if(path[--counter] != 'b')
		error();
	if(path[--counter] != '.')
		error();
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
			error();
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
			error();
		counter++;
	}
	map()->sizex = temp;
}
void	ver_size()
{
	if((map()->sizex < 3 && map()->sizey < 5) || (map()->sizex < 5 && map()->sizey < 3))
		error();
}