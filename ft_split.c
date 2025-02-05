/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:46:22 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/10 19:10:28 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	count_w(const char *s, char c)
{
	int	i;
	int	count;
	int	in_w;

	i = 0;
	count = 0;
	in_w = 0;
	while (s[i])
	{
		if (s[i] != c && in_w == 0)
		{
			count++;
			in_w = 1;
		}
		else if (s[i] == c)
			in_w = 0;
		i++;
	}
	return (count);
}

char	*ft_malloc_w(char *s, char c)
{
	char	*arr;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	arr = ft_substr(s, 0, i);
	if (!arr)
		return (NULL);
	return (arr);
}

void	ft_free_arr(char **arr, int i)
{
	while (i > 0)
		free(arr[i--]);
	free(arr[i]);
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char **)malloc((count_w(s, c) + 1) * sizeof(char *));
	if (!arr || !s)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		arr[i] = ft_malloc_w((char *)s, c);
		if (!arr[i])
		{
			ft_free_arr(arr, i);
			return (NULL);
		}
		i++;
		while (*s && *s != c)
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
