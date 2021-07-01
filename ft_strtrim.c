/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 08:49:08 by rbliss            #+#    #+#             */
/*   Updated: 2020/11/09 13:13:28 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_chr(const char c, const char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

static int		ft_check_first_word(const char *s1, const char *set)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (s1[i])
	{
		check = !ft_check_chr(s1[i], set);
		if (check)
			break ;
		i++;
	}
	return (i);
}

static int		ft_check_last_word(const char *s1, const char *set)
{
	int l1;
	int check;

	check = 0;
	l1 = ft_strlen(s1) - 1;
	while (l1)
	{
		check = !ft_check_chr(s1[l1], set);
		if (check)
			break ;
		l1--;
	}
	return (l1);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	int			i;
	int			l;
	int			end;
	char		*str;

	if (!s1 || !set)
		return (NULL);
	end = ft_check_last_word(s1, set);
	l = ft_check_first_word(s1, set);
	if (end == 0)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * (end - l + 2))))
		return (NULL);
	i = 0;
	while (l <= end)
		str[i++] = s1[l++];
	str[i] = '\0';
	return (str);
}
