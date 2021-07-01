/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:32:14 by rbliss            #+#    #+#             */
/*   Updated: 2020/11/06 16:33:01 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int			i;
	int			j;
	char		*str;
	int			len_str;

	if (!s1 || !s2)
		return (NULL);
	len_str = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(len_str + 1)))
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		str[i++] = s1[j];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}
