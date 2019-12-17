/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strclen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 13:08:16 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 20:37:24 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		if (!str[i + 1] || str[i + 1] == c)
			return (i + 1);
		if (!str[i + 2] || str[i + 2] == c)
			return (i + 2);
		if (!str[i + 3] || str[i + 3] == c)
			return (i + 3);
		if (!str[i + 4] || str[i + 4] == c)
			return (i + 4);
		if (!str[i + 5] || str[i + 5] == c)
			return (i + 5);
		if (!str[i + 6] || str[i + 6] == c)
			return (i + 6);
		if (!str[i + 7] || str[i + 7] == c)
			return (i + 7);
		i += 8;
	}
	return (i);
}
