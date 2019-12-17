/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sget_next_line.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 17:53:48 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 10:54:30 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			sget_next_line(char **str, char **line)
{
	int k;
	int j;

	k = ft_strclen(*str, '\n');
	j = ft_strlen(*str);
	if (!(*str))
	{
		*line = NULL;
		return (0);
	}
	if (!*str[0])
	{
		return (0);
	}
	*line = ft_strsub(*str, 0, k);
	if (((k + 1) == j) ||
			(k == j))
	{
		*str[0] = '\0';
	}
	else
		*str = ft_strfsub(*str, (1 + k), j);
	return (1);
}
