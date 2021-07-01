/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:27:42 by rbliss            #+#    #+#             */
/*   Updated: 2020/11/11 13:14:19 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*delete_all(void *content, t_list **lst, void (*del)(void *))
{
	if (content)
		del(content);
	ft_lstclear(lst, del);
	return (0);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*curr_lst;
	t_list	*final_lst;
	void	*content;

	if (!lst || !f)
		return (0);
	new_lst = 0;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			return (delete_all(content, &new_lst, del));
		final_lst = ft_lstnew(content);
		if (!final_lst)
			return (delete_all(content, &new_lst, del));
		if (!new_lst)
			new_lst = final_lst;
		else
			curr_lst->next = final_lst;
		curr_lst = final_lst;
		lst = lst->next;
	}
	return (new_lst);
}
