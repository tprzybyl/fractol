/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_burningship.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 21:01:31 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 16:15:12 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_burn_pixel(t_param *p, t_pos *pix)
{
	t_dpos			new;
	t_dpos			old;
	t_dpos			cur;

	pix->k = 0;
	cur.x = 1.5 * (pix->x - 1720 / 2) / (0.5 * p->zoom * 1720) + p->movex;
	cur.y = (pix->y - 1080 / 2) / (0.5 * p->zoom * 1080) + p->movey;
	new.y = 0;
	new.x = 0;
	while (pix->k < p->it)
	{
		old.y = new.y;
		old.x = new.x;
		old.z = (new.x * new.y < 0) ? (new.x * new.y * -1) : (new.x * new.y);
		new.x = old.x * old.x - old.y * old.y + cur.x;
		new.y = old.z + old.z + cur.y;
		if ((new.x * new.x + new.y * new.y) > 4)
			break ;
		pix->k++;
	}
	if (pix->k < p->it)
		p->simgpt[pix->z++] = p->colortab[p->c][pix->k % 100];
	else
		p->simgpt[pix->z++] = 0x00000000;
	pix->x++;
}

static void	ft_burnpart(t_param *p, int t)
{
	t_pos			pix;

	pix.y = t;
	pix.z = pix.y * 1720;
	pix.x = 0;
	while (pix.x < 1720)
	{
		ft_burn_pixel(p, &pix);
	}
}

static void	*bsstart(t_param *p)
{
	int t;

	t = p->ymin++;
	ft_burnpart(p, t);
	pthread_exit(NULL);
}

void		ft_burningship(t_param *p)
{
	int				i;
	pthread_t		id[1080];

	p->ymin = 0;
	i = 0;
	while (i < 1079)
	{
		if (pthread_create(&id[i++],
					NULL, (void*(*)(void*))bsstart, (void*)p))
			error_func(1);
	}
	i = 0;
	while (i < 1079)
	{
		if (pthread_join(id[i++], NULL))
			error_func(2);
	}
}
