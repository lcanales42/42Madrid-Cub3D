/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejemplo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:10:13 by lcanales          #+#    #+#             */
/*   Updated: 2020/11/10 08:46:12 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>

/*void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	mlx_pixel_put(mlx, window, )
	return(0);

}*/

int main(void)
{
	void *mlx;
	void *window;
	//void *wind;
	int i;
	int j;
	//void *soldier;

	i = 0;
	//soldier = soldier.xpm;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 600, "Mi ventana");
	//mlx_key_hook(mlx, 'a', )
	mlx_put_image_to_window(mlx, window, soldier.xpm, 32, 30);
	//wind = mlx_xpm_file_to_image(mlx, "soldier.xpm", 40, 40);
	//wind = mlx_new_imagen(mlx, 400, 300);
	while(i <= 100)
	{
		j = 0;
		while(j<=600)
		{
			mlx_pixel_put(mlx, window, i, j, 0|25|84|0);
			j++;
		}
		i++;
	}
	while(i <= 200)
	{
		j = 0;
		while(j<=600)
		{
			mlx_pixel_put(mlx, window, i, j, 0x214578);
			j++;
		}
		i++;
	}
	while(i <= 300)
	{
		j = 0;
		while(j<=600)
		{
			mlx_pixel_put(mlx, window, i, j, 125|012|122|255);
			j++;
		}
		i++;
	}
	while(i <= 400)
	{
		j = 0;
		while(j<=600)
		{
			mlx_pixel_put(mlx, window, i, j, 0xfedcba);
			j++;
		}
		i++;
	}
	while(i <= 500)
	{
		j = 0;
		while(j<=600)
		{
			mlx_pixel_put(mlx, window, i, j, 0x874595);
			j++;
		}
		i++;
	}
	while(i <= 600)
	{
		j = 0;
		while(j<=600)
		{
			mlx_pixel_put(mlx, window, i, j, 0x214578);
			j++;
		}
		i++;
	}
	while(i <= 700)
	{
		j = 0;
		while(j<=600)
		{
			mlx_pixel_put(mlx, window, i, j, 0xabcdef);
			j++;
		}
		i++;
	}
	//mlx_put_image_to_window(mlx, window, wind, 100, 100);
	mlx_pixel_put(mlx, window, 210, 151, 0xFFFFFF);
	mlx_pixel_put(mlx, window, 210, 152, 0xFFFFFF);
	mlx_pixel_put(mlx, window, 210, 153, 0xFFFFFF);
	mlx_pixel_put(mlx, window, 210, 154, 0xFFFFFF);
	mlx_string_put(mlx, window, 210, 155, 0x12234fc, "hola que tal");
	//mlx_key_hook(window, deal_key, (void *)0);
	//mlx_clear_window(mlx, window);
	mlx_loop(mlx);
	//mlx_destroy_window(mlx, window);
	return(0);
}
/*	Para compilar con la libreria minilibx local:
	gcc -I /usr/local/include/ ejemplo.c -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit
	gcc -Wall -Wextra -Werror -I /usr/local/lib -lmlx -framework OpenGL -framework AppKit main.c
	Para compilar com la libreria minilibx descargada, popnerla en a carpeta donde tengas los archivos hacer make y despues:
	gcc ejemplo.c -framework OpenGl -framework AppKit minilibx(es nombre de la carpeta de la libreria)/limlx.a(el make de la libreria) 
	gcc -I /usr/local/include/ -o ejemplo (com -o pones el nombre del ejecutable) ejemplo.c -L /usr/local/lib/ -lmlx -lXext -lX11 todo esto 
	lo puedes sustutuir por gcc -o ejmplo ejemplo.c -lmlx -lXext -lX11 
	seguimos de prueba*/
