/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ftoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 19:14:24 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 21:53:06 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ftoa(double val, int precision)
{
	char		*str;
	char		*str2;
	int			i;
	int			int_part;
	int			decimal_part;

	int_part = val;
	i = 0;
	val = val - int_part;
	while (i < precision)
	{
		val = val * 10;
		i++;
	}
	decimal_part = val * 0.1 * 10;
	if (decimal_part < 0)
		decimal_part = -1 * decimal_part;
	str = ft_itoa(int_part);
	str = ft_strfjoin(str, ".");
	str2 = ft_itoa(decimal_part);
	str = ft_strfjoin(str, str2);
	ft_strdel(&str2);
	return (str);
}
