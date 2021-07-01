/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:29:29 by rbliss            #+#    #+#             */
/*   Updated: 2020/11/09 09:36:59 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *lst_tmp;

	if (!*lst)
		*lst = new;
	else
	{
		lst_tmp = *lst;
		while (lst_tmp->next)
			lst_tmp = lst_tmp->next;
		lst_tmp->next = new;
	}
}
