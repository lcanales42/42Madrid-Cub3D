NAME		= cub3D

CC			= gcc
WFLAGS		= -Werror -Wall -Wextra

INCLUDES	= -l mlx -I /usr/X11/include
FRAMEWORKS	= -framework Appkit -framework OpenGL

SRCS		= main.c \
			  

all:		$(NAME)
				./$(NAME) maps/map1basic.cub

#mlx:
#				$(CC) $(WFLAGS) $(INCLUDES) $(FRAMEWORKS) mlx_testing.c && ./a.out

#map:
#				$(CC) $(WFLAGS) $(INCLUDES) $(FRAMEWORKS) read_map.c && ./a.out

$(NAME): $(SRCS)
				$(CC) -g $(WFLAGS) $(INCLUDES) $(FRAMEWORKS) $(SRCS) -o $(NAME)

#map:
#				rm -rf map
#				$(CC) $(WFLAGS) read_map.c -o map
#				./map maps/map1basic.cub

#clean:

fclean:
				rm -rf $(NAME)

re: fclean all