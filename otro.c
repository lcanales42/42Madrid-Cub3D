/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otro.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcanales <lcanales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 23:18:57 by lcanales          #+#    #+#             */
/*   Updated: 2020/11/09 23:20:17 by lcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

nclude <mlx.h>

int main(void)
{
	void *mlx;
	void *window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Title");

	mlx_loop(mlx);
	return (0);
}
