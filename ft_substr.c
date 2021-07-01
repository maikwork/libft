/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:54:38 by rbliss            #+#    #+#             */
/*   Updated: 2020/11/09 11:10:35 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	size_t			l;

	l = 0;
	if (!s)
		return (NULL);
	while (s[l])
		l++;
	if (start >= l)
		return (ft_calloc(1, sizeof(char)));
	if (!(s2 = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (len--)
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}
