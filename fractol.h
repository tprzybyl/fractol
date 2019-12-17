/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 16:46:42 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 21:53:26 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <pthread.h>
# include <math.h>

typedef struct	s_dpos
{
	double			x;
	double			z;
	double			y;
	double			k;
}				t_dpos;

typedef struct	s_pos
{
	int			x;
	int			z;
	int			y;
	int			k;
}				t_pos;

typedef struct	s_param
{
	void		*mlxpt;
	void		*winpt;
	void		*border;
	char		*sborder;
	void		*imgpt;
	int			*simgpt;
	int			bpp;
	int			s_l;
	int			endian;
	int			it;
	int			ymin;
	int			ymax;
	int			f;
	int			lock;
	int			ansx;
	int			ansy;
	int			colortab[6][100];
	char		*sbio[6];
	int			c;
	double		conx;
	double		cony;
	double		movex;
	double		movey;
	double		zoom;
	double		anchorx;
	double		anchory;
}				t_param;

int				mouse_move(int x, int y, t_param *param);
int				mouse_press(int button, int x, int y, t_param *param);
int				key_press(int keycode, t_param *param);
int				get_colorrange(t_param *p, int start, int end, int *i);
void			reset_values(t_param *param);
void			set_colors(t_param *p);
void			ft_tricorn(t_param *p);
void			ft_triplebrot(t_param *p);
void			ft_julia(t_param *p);
void			ft_burningship(t_param *p);
void			ft_mandelbrot(t_param *p);
void			ft_printcommands(t_param *param);
void			resetvalues(t_param *param);
void			ft_render(t_param *param);
void			ft_images(t_param *param);
void			error_func(int code);

#endif
