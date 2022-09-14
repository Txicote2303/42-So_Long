#include "so_long.h"

void	verification(char	*content, char	*extra)
{
	if(stringcmp(content, "ber") == 1)
		ver_ber(extra);
	if(stringcmp(content, "clean") == 1)
		ver_clean();
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