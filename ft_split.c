/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:26:42 by rbliss            #+#    #+#             */
/*   Updated: 2020/11/13 08:03:23 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_freearr(char **arr, int end)
{
	int i;

	i = 0;
	while (i < end)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static int		ft_countwords(const char *s, char c)
{
	int i;
	int count_word;

	i = 0;
	count_word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		count_word = s[i] ? count_word + 1 : count_word;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count_word);
}

static void		ft_toskip(const char *str, int *p_i, int *p_len_word, char c)
{
	int i;
	int len_word;

	i = *p_i;
	while (str[i] && str[i] == c)
		i++;
	len_word = 0;
	while (str[i + len_word] && str[i + len_word] != c)
		len_word++;
	*p_i = i;
	*p_len_word = len_word;
}

char			**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	int		len_word;
	char	**arr_str;
	int		count_word;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	count_word = ft_countwords(str, c);
	if (!(arr_str = malloc(sizeof(char *) * (count_word + 1))))
		return (NULL);
	while (str[i] && j < count_word)
	{
		ft_toskip(str, &i, &len_word, c);
		if (!str[i])
			break ;
		if (!(arr_str[j] = ft_substr(str, i, len_word)))
			return (ft_freearr(arr_str, j));
		i += len_word;
		j++;
	}
	arr_str[count_word] = 0;
	return (arr_str);
}
