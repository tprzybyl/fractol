/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_julia.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 18:54:57 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 16:14:34 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static char		ft_julia_pix(t_param *p, t_pos *pix, t_dpos *new)
{
	new->y = new->x * new->y;
	new->y = new->y + new->y + p->cony;
	new->x = new->z - new->k + p->conx;
	new->z = new->x * new->x;
	new->k = new->y * new->y;
	if ((new->z + new->k) > 4)
		return (0);
	else if (pix->k >= p->it)
		return (0);
	pix->k++;
	return (1);
}

static void		ft_julipart(t_param *p, int t)
{
	t_pos			pix;
	t_dpos			new;

	pix.y = t;
	pix.z = 1720 * pix.y;
	pix.x = 0;
	while (pix.x < 1720)
	{
		pix.k = 0;
		new.x = 1.5 * (pix.x - 1720 / 2) / (0.5 * p->zoom * 1720) + p->movex;
		new.y = (pix.y - 1080 / 2) / (0.5 * p->zoom * 1080) + p->movey;
		new.z = new.x * new.x;
		new.k = new.y * new.y;
		while (ft_julia_pix(p, &pix, &new))
			;
		if (pix.k < p->it)
			p->simgpt[pix.z++] = p->colortab[p->c][pix.k % 100];
		else
			p->simgpt[pix.z++] = 0x000000;
		pix.x++;
	}
}

static void		*jstart(t_param *p)
{
	int t;

	t = p->ymin++;
	ft_julipart(p, t);
	pthread_exit(NULL);
}

void			ft_julia(t_param *p)
{
	int				i;
	pthread_t		id[1080];

	p->ymin = 0;
	i = 0;
	while (i < 1079)
	{
		if (pthread_create(&id[i++],
					NULL, (void*(*)(void*))jstart, (void*)p))
			error_func(1);
	}
	i = 0;
	while (i < 1079)
	{
		if (pthread_join(id[i++], NULL))
			error_func(2);
	}
}
