/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:47:39 by rbliss            #+#    #+#             */
/*   Updated: 2020/11/09 13:21:37 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *lst_tmp;
	t_list *lst_del;

	if (!lst || !del)
		return ;
	lst_tmp = *lst;
	while (lst_tmp)
	{
		lst_del = lst_tmp;
		lst_tmp = lst_tmp->next;
		ft_lstdelone(lst_del, del);
	}
	*lst = 0;
}
