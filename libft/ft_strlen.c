/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 18:25:29 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 22:08:17 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!str[i + 1])
			return (i + 1);
		if (!str[i + 2])
			return (i + 2);
		if (!str[i + 3])
			return (i + 3);
		if (!str[i + 4])
			return (i + 4);
		if (!str[i + 5])
			return (i + 5);
		if (!str[i + 6])
			return (i + 6);
		if (!str[i + 7])
			return (i + 7);
		i += 8;
	}
	return (i);
}
