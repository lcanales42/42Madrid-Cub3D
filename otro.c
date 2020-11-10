/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otro.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:18:57 by lcanales          #+#    #+#             */
/*   Updated: 2020/11/10 19:39:33 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main(void)
{
	void *mlx;
	void *window;
	void *window2;	
	
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Title");
	window2 = mlx_new_window(mlx, 500, 500, "Hola Mundo");
//	mlx_destroy_window(mlx, window);
	mlx_clear_window(mlx, window);
	//window = mlx_new_window(mlx, 100, 100, "Esto");
	mlx_pixel_put(mlx, window, 500, 500, 125|012|122|255);
	mlx_pixel_put(mlx, window, 501, 500, 125|012|122|255);
	mlx_pixel_put(mlx, window, 502, 500, 125|012|122|255);
	mlx_pixel_put(mlx, window, 503, 500, 125|012|122|255);
	mlx_pixel_put(mlx, window, 504, 500, 125|012|122|255);
	mlx_pixel_put(mlx, window, 505, 500, 125|012|122|255);
	mlx_pixel_put(mlx, window, 506, 500, 125|012|122|255);
	mlx_pixel_put(mlx, window, 507, 500, 125|012|122|255);
	mlx_string_put(mlx,window2, 250, 250, 125|012|122|255, "hola");	


	mlx_loop(mlx);
	return (0);
}
