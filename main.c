/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 20:30:29 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 15:30:51 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	checkarg(char *arg, t_param *param)
{
	if (!ft_strcmp(arg, "-mandelbrot"))
		param->f = 1;
	else if (!ft_strcmp(arg, "-julia"))
		param->f = 2;
	else if (!ft_strcmp(arg, "-burningship"))
		param->f = 3;
	else if (!ft_strcmp(arg, "-tricorn"))
		param->f = 4;
	else if (!ft_strcmp(arg, "-triplebrot"))
		param->f = 5;
	else
		error_func(0);
}

static int	exit_event(t_param *param)
{
	exit(EXIT_SUCCESS);
}

static int	expose_event(t_param *param)
{
	ft_render(param);
	return (0);
}

int			main(int ac, char **av)
{
	t_param			*param;

	if (ac != 2)
		error_func(0);
	if (!(param = malloc(sizeof(t_param))))
		error_func(-1);
	if (ac == 2)
		checkarg(av[1], param);
	if (!(param->mlxpt = mlx_init()))
		error_func(5);
	if (!(param->winpt = mlx_new_window(param->mlxpt, 1920, 1080,
			"tprzybyl's fract'ol")))
		error_func(5);
	ft_images(param);
	ft_render(param);
	mlx_hook(param->winpt, 6, 0, mouse_move, param);
	mlx_hook(param->winpt, 4, 0, mouse_press, param);
	mlx_hook(param->winpt, 2, 0, key_press, param);
	mlx_hook(param->winpt, 12, 0, expose_event, param);
	mlx_hook(param->winpt, 17, 0, exit_event, param);
	mlx_loop(param->mlxpt);
	return (0);
}
