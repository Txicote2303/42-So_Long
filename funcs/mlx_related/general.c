#include "so_long.h"

int	close_mlx()
{
	mlx_destroy_window(window()->mlx_ptr, window()->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
