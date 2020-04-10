/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo.canales.sanchezgmail.com <loren    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:38:12 by lorenzo.can       #+#    #+#             */
/*   Updated: 2020/04/10 10:52:20 by lorenzo.can      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}   			t_color;

#define mapWidth 24 
#define mapHeight 24 
#define screenWidth 640 
#define screenHeight 480 

  int worldMap [mapWidth] [mapHeight] = 
  { 
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1}, 
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1}, 
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1}, 
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} 
  };

int main(int argc, char ** argv) 
{ 
	double posX = 22, posY = 12;  // posición de inicio x e y 
    double dirX = -1, dirY = 0;  // vector de dirección inicial 
    double planeX = 0, planeY = 0.66;  // la versión 2d raycaster del plano de la cámara 
    double time = 0;  // hora del marco actual 
    double oldTime = 0;  // tiempo del fotograma anterior 
	void *pantalla;
	void *mlx;
	double cameraX;
	double raydirX; //direccion de rayo x
	double raydirY; //direccion de rayo y
	int x = 0;
	int w = 0;
	// para la posicion inicial del rayo
	int mapX; 
	int mapY; 
	// longitud del rayo desde la posición actual al siguiente lado x o y 
	double sidedistX;
	double sidedistY;
	// Para la siguiente posicion del rayo
	double deltadistX; 
	double deltadistY;
	double longraydist; // Para calcular la longitud del rayo
	// para saber en que dirección pisar en dirección x o y (ya sea +1 o -1) 
	int stepX;
	int stepY;
	int hit = 0;  // ¿hubo un golpe en la pared? 
    int side;  // ¿se golpeó un muro NS o EW?


	mlx = mlx_init;
	pantalla = mlx_new_window(mlx, screenWidth, screenHeight, "Raycaster"); 
  
  	while (x < w)
  	{
     	// calcular la posición y dirección del rayo 
        cameraX = 2 * x / (double)w - 1;  // coordenada x en el espacio de la cámara 
       	raydirX = dirX + planeX * cameraX; 
        raydirY = dirY + planeY * cameraX;
		// en qué cuadro del mapa estamos (esta el rayo)
		mapX = (int)posX;
		mapY = (int)posY;
		// longitud del rayo desde un lado x o y hasta el siguiente lado x o y 
		deltadistX = sqrt (1 + (raydirX * raydirX) / (raydirY * raydirY));
		deltadistY = sqrt (1 + (raydirX * raydirX) / (raydirY * raydirY));
		// calcular paso y sideDist inicial 
		if (raydirX < 0)
		{
			stepX = -1;
			sidedistX = (posX - mapX) * deltadistX;
		}
		else
		{
			stepX = 1;
			sidedistX = (mapX + 1.0 - posX) * deltadistX;
		}
		if (raydirY < 0)
		{
			stepY = -1;
			sidedistY = (posY - mapY) * deltadistY;
		}
		else
		{
			stepY = 1;
			sidedistY = (mapY + 1.0 - posY) * deltadistY;
		}

				

		x++;
	}
  
  
  }


