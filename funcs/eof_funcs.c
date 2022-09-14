#include "so_long.h"

void error()
{
	//eliminate printf()
	printf("ERROR\n");
	exit(EXIT_FAILURE);
}

int	stringcmp(char	*str1, char	*str2)
{
	int	counter;

	counter = 0;
	if(!str1 || !str2)
		error();
	while (str1[counter++])
	{
		if(str1[counter] != str2[counter])
			return(0);
	}
	if(str2[counter])
		return(0);
	return(1);
}