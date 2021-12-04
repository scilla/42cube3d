/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:00:26 by scilla            #+#    #+#             */
/*   Updated: 2021/01/23 19:45:58 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	p;

	if (c == 0)
		return (1);
	i = 0;
	p = 0;
	while (1)
	{
		while (c != 0 && s[i] == c)
			i++;
		if (!s[i])
			break ;
		p++;
		while (s[i] != c && s[i])
			i++;
	}
	return (p);
}

char	*fill_word(unsigned int *i, const char *s, char c)
{
	unsigned int	w_len;
	unsigned int	n;
	char			*res;

	w_len = 0;
	n = 0;
	while (*(s + w_len + *i) && *(s + w_len + *i) != c)
		w_len++;
	res = malloc(sizeof(char) * (w_len + 1));
	if (!res)
		return (0);
	while (n < w_len)
	{
		res[n] = s[*i];
		(*i)++;
		n++;
	}
	res[n] = 0;
	return (res);
}

int		check(char **res, unsigned int p)
{
	if (!res[p])
	{
		while (p > 0)
		{
			p--;
			free(res[p]);
		}
		free(res);
		return (0);
	}
	return (1);
}

char	**fill_arr(char const *s, char c, char **res)
{
	unsigned int	i;
	unsigned int	p;

	i = 0;
	p = 0;
	while (1)
	{
		while (*(s + i) == c)
			i++;
		if (!(*(s + i)))
			break ;
		res[p] = fill_word(&i, s, c);
		if (!check(res, p))
			return (0);
		p++;
		if (!c)
			break ;
	}
	res[p] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s || !(*s))
	{
		res = malloc(sizeof(char*));
		*res = 0;
		return (res);
	}
	if (!(res = malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (0);
	res = fill_arr(s, c, res);
	if (!res)
		return (0);
	return (res);
}
