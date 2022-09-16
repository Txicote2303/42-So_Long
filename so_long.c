#include "so_long.h"

int	main(int argc, char	**argv)
{
	if(argc != 2)
		error("Wrong Args");
	map_read(argv[1]);
	new_window();
	while(1);
}