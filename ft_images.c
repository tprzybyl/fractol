/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_images.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 18:50:18 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 15:33:26 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void		assign_palletstrings(t_param *p)
{
	p->sbio[0] = ft_strdup("Default");
	p->sbio[1] = ft_strdup("Alternative");
	p->sbio[2] = ft_strdup("Radish-ish");
	p->sbio[3] = ft_strdup("Patriotic");
	p->sbio[4] = ft_strdup("Black/Green/White");
	p->sbio[5] = ft_strdup("Martin's");
}

static void		borderpixel(t_param *param, int i, int op)
{
	if (op)
	{
		param->sborder[i] = (char)200;
		param->sborder[i + 1] = (char)200;
		param->sborder[i + 2] = (char)200;
		param->sborder[i + 3] = (char)0;
	}
	else
	{
		param->sborder[i] = (char)25;
		param->sborder[i + 1] = (char)0;
		param->sborder[i + 2] = (char)215;
		param->sborder[i + 3] = (char)0;
	}
}

static void		ft_border(t_param *param)
{
	int i;

	i = 0;
	while (i < 864000)
	{
		if (i % 800 == 0)
			borderpixel(param, i, 1);
		else if ((i % 800 >= 100 && i % 800 < 700) &&
				((i / 800 >= 25 && i / 800 < 55) ||
				(i / 800 >= 245 && i / 800 < 275) ||
				(i / 800 >= 190 && i / 800 < 220) ||
				(i / 800 >= 80 && i / 800 < 110) ||
				(i / 800 >= 135 && i / 800 < 165)))
			borderpixel(param, i, 0);
		else
		{
			param->sborder[i] = (char)50;
			param->sborder[i + 1] = (char)50;
			param->sborder[i + 2] = (char)50;
			param->sborder[i + 3] = (char)0;
		}
		i += 4;
	}
}

void			ft_images(t_param *param)
{
	param->border = mlx_new_image(param->mlxpt, 200, 1080);
	param->sborder = mlx_get_data_addr(param->border, &param->bpp,
			&param->s_l, &param->endian);
	param->imgpt = mlx_new_image(param->mlxpt, 1720, 1080);
	param->simgpt = (int*)mlx_get_data_addr(param->imgpt, &param->bpp,
			&param->s_l, &param->endian);
	param->it = 100;
	param->lock = 0;
	param->conx = 0;
	param->cony = 0;
	param->movex = 0;
	param->movey = 0;
	param->zoom = .8;
	param->c = 0;
	assign_palletstrings(param);
	set_colors(param);
	ft_border(param);
}
