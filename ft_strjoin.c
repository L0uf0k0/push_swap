/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:31:16 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/03 00:15:03 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		size;
	int		i;

	i = 0;
	if (s1)
		size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	else
		size = ft_strlen((char *)s2) + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (0);
	while (s1 && *s1)
	{
		ptr[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		ptr[i++] = *s2;
		s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}
