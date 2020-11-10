/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otro.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:18:57 by lcanales          #+#    #+#             */
/*   Updated: 2020/11/10 09:30:43 by lcanales         ###   ########.fr       */
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
	window = mlx_new_window(mlx, 100, 100, "Esto");

	mlx_loop(mlx);
	return (0);
}
