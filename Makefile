# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/21 16:02:27 by frcarval          #+#    #+#              #
#    Updated: 2022/09/27 11:27:07 by frcarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES		=	so_long.c						\
				funcs/eof_funcs.c				\
				funcs/structures.c				\
				funcs/map_related/construction.c\
				funcs/map_related/verif.c		\
				funcs/mlx_related/window.c		\
				funcs/mlx_related/img.c			\
				funcs/mlx_related/hooks.c		\
				gnl/get_next_line.c				\
				gnl/get_whole_line.c			\
				gnl/get_next_line_utils.c		\

NAME 	=	so_long
GCCW	=	@gcc -Wall -Wextra -Werror -I/usr/local/include -I./

all:		$(NAME)

$(NAME): 	$(SOURCES)
			$(GCCW) $^ -o $@ -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
			@clear && echo "\033[1;32m  ___  __   _  _  ____  __  __    ____  ____ \n / __)/  \ ( \/ )(  _ \(  )(  )  (  __)(    \ \n( (__(  O )/ \/ \ ) __/ )( / (_/\ ) _)  ) D (\n \___)\__/ \_)(_/(__)  (__)\____/(____)(____/"
clean:		
			@clear && echo "\033[1;33m  ___  __    ____   __   __ _  ____  ____ \n / __)(  )  (  __) / _\ (  ( \(  __)(    \ \n( (__ / (_/\ ) _) /    \/    / ) _)  ) D (\n \___)\____/(____)\_/\_/\_)__)(____)(____/"
			@rm -f $(OBJECTS)

fclean:		
			@clear && echo "\033[1;31m ____  ___  __    ____   __   __ _  ____  ____ \n(  __)/ __)(  )  (  __) / _\ (  ( \(  __)(    \ \n ) _)( (__ / (_/\ ) _) /    \/    / ) _)  ) D (\n(__)  \___)\____/(____)\_/\_/\_)__)(____)(____/"
			@rm -f $(OBJECTS)
			@rm -f $(NAME)

re:			fclean $(NAME)
			@clear && echo "\033[1;31m ____  ___  __    ____   __   __ _  ____  ____ \n(  __)/ __)(  )  (  __) / _\ (  ( \(  __)(    \ \n ) _)( (__ / (_/\ ) _) /    \/    / ) _)  ) D (\n(__)  \___)\____/(____)\_/\_/\_)__)(____)(____/\n\n\n\033[1;32m  ___  __   _  _  ____  __  __    ____  ____ \n / __)/  \ ( \/ )(  _ \(  )(  )  (  __)(    \ \n( (__(  O )/ \/ \ ) __/ )( / (_/\ ) _)  ) D (\n \___)\__/ \_)(_/(__)  (__)\____/(____)(____/"

.PHONY:	all clean fclean re
