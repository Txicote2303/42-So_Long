#include "so_long.h"

int	main(int argc, char	**argv)
{
	if(argc != 2)
		error();
	map_read(argv[1]);
}