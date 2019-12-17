/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mandelbrot.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 16:03:02 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 16:14:31 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_mandassign(t_pos *pix, t_dpos *new, t_dpos *cur, t_param *p)
{
	pix->k = 0;
	cur->x = 1.5 * (pix->x - 1720 / 2) / (0.5 * p->zoom * 1720) + p->movex;
	cur->y = (pix->y - 1080 / 2) / (0.5 * p->zoom * 1080) + p->movey;
	new->y = 0;
	new->x = 0;
	new->z = new->x * new->x;
	new->k = new->y * new->y;
}

static int		ft_mand_pix(t_pos *pix, t_dpos *new, t_dpos *cur, t_param *p)
{
	double			testx;
	double			testy;

	testx = new->x;
	testy = new->y;
	new->y = new->x * new->y;
	new->y = new->y + new->y + cur->y;
	new->x = new->z - new->k + cur->x;
	if (new->x == testx && new->y == testy)
	{
		pix->k = p->it;
		return (1);
	}
	new->z = new->x * new->x;
	new->k = new->y * new->y;
	pix->k++;
	return (0);
}

static void		ft_mandpart(t_param *p, int t)
{
	t_pos			pix;
	t_dpos			cur;
	t_dpos			new;

	pix.y = t;
	pix.z = pix.y * 1720;
	pix.x = 0;
	while (pix.x < 1720)
	{
		ft_mandassign(&pix, &new, &cur, p);
		while (new.z + new.k <= 4 && pix.k < p->it)
		{
			if (ft_mand_pix(&pix, &new, &cur, p))
				break ;
		}
		if (pix.k < p->it)
			p->simgpt[pix.z++] = p->colortab[p->c][pix.k % 100];
		else
			p->simgpt[pix.z++] = 0x00000000;
		pix.x++;
	}
}

static void		*mstart(t_param *p)
{
	int t;

	t = p->ymin++;
	ft_mandpart(p, t);
	pthread_exit(NULL);
}

void			ft_mandelbrot(t_param *p)
{
	int			i;
	pthread_t	id[1080];

	p->ymin = 0;
	i = 0;
	while (i < 1079)
	{
		if (pthread_create(&id[i++],
					NULL, (void*(*)(void*))mstart, (void*)p))
			error_func(1);
	}
	i = 0;
	while (i < 1079)
	{
		if (pthread_join(id[i++], NULL))
			error_func(2);
	}
}
