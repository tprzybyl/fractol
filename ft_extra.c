/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_extra.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 19:08:54 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 15:40:56 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void			reset_values(t_param *param)
{
	param->it = 100;
	param->conx = 0;
	param->cony = 0;
	param->movex = 0;
	param->movey = 0;
	param->zoom = .8;
	param->c = 0;
}

void			ft_render(t_param *param)
{
	if (param->f == 1)
		ft_mandelbrot(param);
	else if (param->f == 4)
		ft_tricorn(param);
	else if (param->f == 2)
		ft_julia(param);
	else if (param->f == 3)
		ft_burningship(param);
	else if (param->f == 5)
		ft_triplebrot(param);
	mlx_put_image_to_window(param, param->winpt, param->border, 1720, 0);
	ft_printcommands(param);
	mlx_put_image_to_window(param, param->winpt, param->imgpt, 0, 0);
}

static void		get_allcolor(t_param *p)
{
	int		i[2];

	i[0] = 0;
	while (i[0] < 6)
	{
		i[1] = 0;
		while (++i[1] < 19)
			p->colortab[i[0]][i[1]] = get_colorrange(p, 0, 19, i);
		while (++i[1] < 39)
			p->colortab[i[0]][i[1]] = get_colorrange(p, 19, 39, i);
		while (++i[1] < 59)
			p->colortab[i[0]][i[1]] = get_colorrange(p, 39, 59, i);
		while (++i[1] < 79)
			p->colortab[i[0]][i[1]] = get_colorrange(p, 59, 79, i);
		while (++i[1] < 100)
			p->colortab[i[0]][i[1]] = get_colorrange(p, 79, 100, i);
		i[0]++;
	}
}

static void		set_colors_ext(t_param *p)
{
	p->colortab[3][0] = 0x0000FF;
	p->colortab[3][19] = 0x7F7FFF;
	p->colortab[3][39] = 0xFFFFFF;
	p->colortab[3][59] = 0xFF7F7F;
	p->colortab[3][79] = 0xFF0000;
	p->colortab[4][0] = 0xFFFFFF;
	p->colortab[4][19] = 0x000000;
	p->colortab[4][39] = 0xFFFFFF;
	p->colortab[4][59] = 0x000000;
	p->colortab[4][79] = 0x00FF00;
	p->colortab[5][0] = 0x66FF33;
	p->colortab[5][19] = 0x66FFFF;
	p->colortab[5][39] = 0xFF00FF;
	p->colortab[5][59] = 0x663300;
	p->colortab[5][79] = 0x118218;
	get_allcolor(p);
}

void			set_colors(t_param *p)
{
	p->colortab[0][0] = 0x8825F2;
	p->colortab[0][19] = 0x0000FF;
	p->colortab[0][39] = 0x83F94D;
	p->colortab[0][59] = 0xF8F351;
	p->colortab[0][79] = 0xCD2B1E;
	p->colortab[1][0] = 0x0000FF;
	p->colortab[1][19] = 0x00FF00;
	p->colortab[1][39] = 0xFF0000;
	p->colortab[1][59] = 0xFF00FF;
	p->colortab[1][79] = 0xff99ff;
	p->colortab[2][0] = 0xFF00FF;
	p->colortab[2][19] = 0xFFFFFF;
	p->colortab[2][39] = 0x00FF00;
	p->colortab[2][59] = 0xFFFFFF;
	p->colortab[2][79] = 0xFF00FF;
	p->colortab[3][0] = 0xFF0000;
	p->colortab[3][19] = 0x0000FF;
	p->colortab[3][39] = 0xFF0000;
	p->colortab[3][59] = 0x0000FF;
	p->colortab[3][79] = 0xFF0000;
	set_colors_ext(p);
}
