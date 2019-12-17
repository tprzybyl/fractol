/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gradient.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 20:04:03 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 20:30:11 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int				get_colorrange(t_param *p, int start, int end, int *i)
{
	double	perc;
	int		temp[2];
	int		r;
	int		g;
	int		b;

	temp[0] = p->colortab[i[0]][start];
	temp[1] = p->colortab[i[0]][(end != 100) ? end : 0];
	perc = percent(start, end, i[1]);
	b = get_light(temp[0] % 256, temp[1] % 256, perc);
	temp[0] /= 256;
	temp[1] /= 256;
	g = get_light(temp[0] % 256, temp[1] % 256, perc);
	temp[0] /= 256;
	temp[1] /= 256;
	r = get_light(temp[0], temp[1], perc);
	return ((r << 16) | (g << 8) | (b));
}
