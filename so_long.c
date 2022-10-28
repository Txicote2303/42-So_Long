#include "so_long.h"

int	main(int argc, char	**argv)
{
	t_window mainw;

	if(argc != 2)
		error("Wrong Args");
	map_read(argv[1]);
	//(void)mainw;
	
	// printf("\n\n\n%i\n\n\n", map()->sizex);
	new_window();
	putimg();
	map()->moves = 0;
	mlx_key_hook(window()->win_ptr, key_handle, &mainw);
	mlx_loop(window()->mlx_ptr);
}
