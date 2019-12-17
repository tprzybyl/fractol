/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hooks.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 21:43:56 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 22:09:00 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	bigredbuttons(t_param *param, int x, int y)
{
	if (x <= 1895 && x > 1745 && y <= 220 && y > 190)
		param->f = 4;
	if (x <= 1895 && x > 1745 && y <= 275 && y > 245)
		param->f = 5;
	if (x <= 1895 && x > 1745 && y <= 55 && y > 25)
		param->f = 1;
	if (x <= 1895 && x > 1745 && y <= 110 && y > 80)
		param->f = 2;
	if (x <= 1895 && x > 1745 && y <= 165 && y > 135)
		param->f = 3;
}

int			mouse_press(int button, int x, int y, t_param *param)
{
	if (button == 1)
		bigredbuttons(param, x, y);
	else if (button == 2 && param->f == 2)
	{
		if (param->lock)
		{
			param->ansx = x;
			param->ansy = y;
		}
		param->lock = (param->lock) ? 0 : 1;
	}
	else if (button == 4)
	{
		param->zoom *= 1.3;
		param->movey += (y - 540) * 0.00053 / param->zoom;
		param->movex += (x - 860) * 0.00053 / param->zoom;
	}
	else if (button == 5)
	{
		param->movey -= (y - 540) * 0.00053 / param->zoom;
		param->movex -= (x - 860) * 0.00053 / param->zoom;
		param->zoom /= 1.3;
	}
	ft_render(param);
	return (0);
}

int			mouse_move(int x, int y, t_param *param)
{
	static int		first;

	if (param->f == 2 && !param->lock)
	{
		if (!first)
		{
			first = 1;
			param->ansx = x;
			param->ansy = y;
		}
		param->cony += 0.0027777 * (param->ansx - x);
		param->conx += 0.0017441 * (param->ansy - y);
		param->ansx = x;
		param->ansy = y;
		ft_render(param);
	}
	return (0);
}

int			key_press(int keycode, t_param *param)
{
	if (keycode >= 83 && keycode <= 88)
		param->c = keycode - 83;
	else if (keycode == 78)
		param->it -= 20;
	else if (keycode == 69)
		param->it += 20;
	else if (keycode == 12)
		param->zoom -= 1 * param->zoom / 5.0;
	else if (keycode == 14)
		param->zoom += 1 * param->zoom / 5.0;
	else if (keycode == 0 || keycode == 123)
		param->movex -= .25 / param->zoom;
	else if (keycode == 2 || keycode == 124)
		param->movex += .25 / param->zoom;
	else if (keycode == 1 || keycode == 125)
		param->movey += .25 / param->zoom;
	else if (keycode == 13 || keycode == 126)
		param->movey -= .25 / param->zoom;
	else if (keycode == 36)
		reset_values(param);
	else if (keycode == 53 && param)
		exit(EXIT_SUCCESS);
	ft_render(param);
	return (0);
}
