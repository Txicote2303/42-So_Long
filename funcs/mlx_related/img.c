#include "so_long.h"

void	putimg(void)
{
	int	counterx;
	int	countery;

	counterx = 0;
	countery = 0;
	while (counterx < map()->sizex)
	{
		while(countery < map()->sizey)
		{
			if(map()->matrix[countery][counterx] == '1')
				img()->img_ptr = mlx_xpm_file_to_image(window()->mlx_ptr
				, "./assets/bricks.xpm", &img()->width, &img()->height);
			else if(map()->matrix[countery][counterx] == '0')
				img()->img_ptr = mlx_xpm_file_to_image(window()->mlx_ptr,
					"./assets/floor.xpm", &img()->width, &img()->height);
			else if(map()->matrix[countery][counterx] == 'C')
			{
				img()->img_ptr = mlx_xpm_file_to_image(window()->mlx_ptr,
					"./assets/floor.xpm", &img()->width, &img()->height);
				mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, img()->img_ptr, counterx * 16, countery * 16);
				img()->img_ptr = mlx_xpm_file_to_image(window()->mlx_ptr,
					"./assets/collectible.xpm", &img()->width, &img()->height);
			}
			else if(map()->matrix[countery][counterx] == 'P')
				{
				img()->img_ptr = mlx_xpm_file_to_image(window()->mlx_ptr,
					"./assets/floor.xpm", &img()->width, &img()->height);
				mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, img()->img_ptr, counterx * 16, countery * 16);
				img()->img_ptr = mlx_xpm_file_to_image(window()->mlx_ptr,
					"./assets/char.xpm", &img()->width, &img()->height);	
				}
			else if(map()->matrix[countery][counterx] == 'E')
			{
				img()->img_ptr = mlx_xpm_file_to_image(window()->mlx_ptr,
					"./assets/floor.xpm", &img()->width, &img()->height);
				mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, img()->img_ptr, counterx * 16, countery * 16);
				img()->img_ptr = mlx_xpm_file_to_image(window()->mlx_ptr,
					"./assets/exit.xpm", &img()->width, &img()->height);
			}
			else
				error("No supported char (put_img)");
			if(!img()->img_ptr)
				error("Could not read asset");
			printf("%c\n", map()->matrix[countery][counterx]);
			mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, img()->img_ptr, counterx * 16, countery * 16);
			countery++;
		}
		countery = 0;
		counterx++;
	}	
}