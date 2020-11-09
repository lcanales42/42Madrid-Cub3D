/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otro.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:18:57 by lcanales          #+#    #+#             */
/*   Updated: 2020/11/09 23:36:32 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main(void)
{
	void *mlx;
	void *window;
	
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Title");

	mlx_loop(mlx);
	return (0);
}
