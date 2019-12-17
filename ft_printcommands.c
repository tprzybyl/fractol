/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printcommands.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 19:35:12 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 22:07:15 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_printcommands_values(t_param *p)
{
	char *tmp;

	tmp = ft_ftoa(p->movey, 5);
	mlx_string_put(p->mlxpt, p->winpt, 1820,
			360, 0xFFCC00, tmp);
	ft_strdel(&tmp);
	tmp = ft_ftoa(p->movex, 5);
	mlx_string_put(p->mlxpt, p->winpt, 1820,
			335, 0xFFCC00, tmp);
	ft_strdel(&tmp);
	tmp = ft_ftoa(p->zoom, 5);
	mlx_string_put(p->mlxpt, p->winpt, 1820,
			310, 0xFFCC00, tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(p->it);
	mlx_string_put(p->mlxpt, p->winpt, 1880, 285, 0xFFCC00, tmp);
	mlx_string_put(p->mlxpt, p->winpt, 1740, 385,
			0xFFCCAA, "Color (NUM 1-6)");
	mlx_string_put(p->mlxpt, p->winpt, 1740, 410, 0xFFFFFF, p->sbio[p->c]);
	ft_strdel(&tmp);
}

void		ft_printcommands(t_param *p)
{
	mlx_string_put(p->mlxpt, p->winpt, 1756, 250,
			(p->f == 5) ? 0xFFFF00 : 0xFFFFFF, " Triplebrot");
	mlx_string_put(p->mlxpt, p->winpt, 1756, 195,
			(p->f == 4) ? 0xFFFF00 : 0xFFFFFF, "  Tricorn");
	mlx_string_put(p->mlxpt, p->winpt, 1756, 140,
			(p->f == 3) ? 0xFFFF00 : 0xFFFFFF, "Burning ship");
	mlx_string_put(p->mlxpt, p->winpt, 1756, 85,
			(p->f == 2) ? 0xFFFF00 : 0xFFFFFF, "   Julia");
	mlx_string_put(p->mlxpt, p->winpt, 1756, 30,
			(p->f == 1) ? 0xFFFF00 : 0xFFFFFF, " Mandelbrot");
	mlx_string_put(p->mlxpt, p->winpt, 1740, 360, 0xFFCCAA, "MoveY = ");
	mlx_string_put(p->mlxpt, p->winpt, 1740, 335, 0xFFCCAA, "MoveX = ");
	mlx_string_put(p->mlxpt, p->winpt, 1740, 310, 0xFFCCAA, "Zoom  =");
	mlx_string_put(p->mlxpt, p->winpt,
			1740, 285, 0xFFCCAA, "Iterations = ");
	ft_printcommands_values(p);
}
