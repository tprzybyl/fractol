/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strgetfrom.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 19:04:00 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 15:05:19 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strgetfrom(const int fd, char **str)
{
	char	tmp[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, tmp, BUFF_SIZE)))
	{
		if (ret < 0)
			return (0);
		tmp[ret] = '\0';
		*str = ft_strfjoin(*str, tmp);
	}
	return (1);
}
