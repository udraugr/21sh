/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:22:50 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 15:23:02 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

t_stack			*ft_new_stack(char *s)
{
	t_stack		*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->data = ft_strdup(s);
	new->next = NULL;
	return (new);
}

void			ft_push_stack(t_stack **head, t_stack *tail)
{
	t_stack		*tmp;

	tmp = *head;
	if (!tmp)
		*head = tail;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tail;
	}
}

t_stack			*ft_imap_stack(t_stack *head, int n)
{
	int			i;

	i = 1;
	while (i < n && head && head->next)
	{
		head = head->next;
		++i;
	}
	if (i == n)
		return (head);
	if (head->next == NULL)
		return (head);
	return (NULL);
}

int				ft_len_stack(t_stack *head)
{
	int			len;

	len = 0;
	while (head)
	{
		head = head->next;
		++len;
	}
	return (len);
}

void			ft_del_stack(t_stack **head)
{
	t_stack		*tmp;

	if (!head || !(*head))
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		ft_strdel(&tmp->data);
		free(tmp);
	}
}
