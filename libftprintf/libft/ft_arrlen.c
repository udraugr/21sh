/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:33:35 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/01 17:02:45 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_arrlen(char **arr)
{
	int		i;

	i = 0;
	if (!arr || !(*arr))
		return (i);
	while (arr[i])
		++i;
	return (i);
}
