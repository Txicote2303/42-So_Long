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

	counter = -1;
	if(!str1 || !str2)
		error();
	while (str1[++counter])
	{
		if(str1[counter] != str2[counter])
			return(0);
	}
	if(str2[counter])
		return(0);
	return(1);
}

int	string_size(char	*string)
{
	int	counter;
	
	counter = 0;
	while(string[counter])
		counter++;
	return (counter);
}

char	*nl_rmv(char	*string)
{
	int	counter;
	char	*temp;
	counter = 0;
	temp = my_dup(string);
	if(!string)
		return(string);
	while(temp[counter])
	{
		if(temp[counter] == '\n')
			temp[counter] = '\0';
		counter++;
	}
	return(temp);
}

char	*my_dup(char	*string)
{
	char	*returner;
	int		counter;

	counter = 0;
	if (!string)
		returner = malloc(sizeof(char));
	else
	{
		returner = malloc(sizeof(char) * (my_len(string) + 1));
		while (string[counter])
		{
			returner[counter] = string[counter];
			counter++;
		}
	}
	returner[counter] = '\0';
	return (returner);
}
int	my_len(char	*string)
{
	int	counter;

	counter = 0;
	while (string[counter])
		counter++;
	return (counter);
}
