#include "so_long.h"

int	close_mlx()
{
	mlx_destroy_window(window()->mlx_ptr, window()->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char	**argv)
{
	t_window mainw;

	if(argc != 2)
		error("Wrong Args");
	map_read(argv[1]);
	(void)mainw;
	
	printf("\n\n\n%i\n\n\n", map()->sizex);
	new_window();
	putimg();
	map()->moves = 0;
	mlx_key_hook(window()->win_ptr, key_handle, &mainw);
	mlx_loop(window()->mlx_ptr);
}
/*
void cenas()
{
	int i;
	i = scanf("insere a merda de um numero");
	int	is_prime = 1;
	int reverse;
	int	counter = 1;
	while(i > 0)
	{
		reverse = counter / 2;
		while(reverse > 1)
		{
			if(counter % reverse == 0)
				is_prime = 0;
			reverse--;
		}
		printf("%i\n", counter);
		counter++;
		is_prime = 1;
	}
}*/