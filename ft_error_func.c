/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error_func.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 17:34:51 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 14:25:06 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	error_func(int code)
{
	char *us;

	us = "usage: ./fractol [-mandelbrot | -julia | -burningship | -tricorn";
	if (code == -4)
		perror("Close error");
	else if (code == -3)
		perror("Read error");
	else if (code == -2)
		perror("Open error");
	else if (code == -1)
		perror("Memory allocation error");
	else if (code == 0)
	{
		ft_putstr_fd(us, 2);
		ft_putendl_fd(" | -triplebrot]", 2);
	}
	else if (code == 1)
		perror("Thread creation failed");
	else if (code == 2)
		perror("Thread join failed");
	else if (code == 5)
		perror("MLX Init failed");
	exit(EXIT_FAILURE);
}
