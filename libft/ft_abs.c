/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_abs.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:32:45 by tprzybyl     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 10:53:15 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int x)
{
	return (x = (x >= 0) ? x : x * -1);
}
