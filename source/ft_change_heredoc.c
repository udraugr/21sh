/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:33:50 by draynor           #+#    #+#             */
/*   Updated: 2019/07/19 22:16:16 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

int					ft_is_delim(char c, char d)
{
	if (c == ';' || c == '|' || (c == '<' && d == '<') || c == '>')
		return (1);
	return (0);
}

static void			ft_change_heredoc_2(t_mygv *mygv)
{
	char			*iter;
	char			*tmp;
	char			*tmp2;

	tmp = ft_strjoin("\n", mygv->target);
	tmp2 = ft_strjoin(tmp, "\n");
	iter = ft_strstr(mygv->g_str, tmp2);
	if (!iter)
		iter = ft_strstr(mygv->g_str, tmp);
	if (!iter)
		iter = ft_strstr(mygv->g_str, mygv->target);
	if (iter && *iter == '\n')
		mygv->g_kos++;
	while (iter && *iter == '\n')
		ft_memmove(iter, iter + 1, ft_strlen(iter) + 1);
	if (iter)
		*iter = '"';
	++iter;
	if (iter)
		ft_memmove(iter, iter + (int)ft_strlen(mygv->target) - 1,
				ft_strlen(iter) + 1);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	ft_strdel(&mygv->target);
}

void				ft_change_heredoc(t_mygv *mygv)
{
	char			*iter;

	iter = ft_strstr(&mygv->g_str[mygv->cur_her], "<<");
	if (iter)
		iter += 2;
	while (iter && *iter && *iter == ' ')
		++iter;
	if (iter)
		ft_memmove(iter, iter + (int)ft_strlen(mygv->target),
				ft_strlen(mygv->g_str) + 1);
	while (iter && *iter == ' ')
		ft_memmove(iter, iter + 1, ft_strlen(iter) + 1);
	if (iter && *iter == '\n')
		++mygv->g_kos;
	if (iter)
		*iter = '"';
	++iter;
	ft_change_heredoc_2(mygv);
}
