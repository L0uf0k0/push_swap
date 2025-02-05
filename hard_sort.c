/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:22:28 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/15 22:49:02 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_l **lst1)
{
	int	temp1;
	int	temp2;
	int	temp3;

	temp1 = (*lst1)->data;
	temp2 = (*lst1)->next->data;
	temp3 = (*lst1)->next->next->data;
	if (temp1 < temp2 && temp2 < temp3)
		return ;
	if (temp1 < temp2 && temp1 < temp3)
	{
		ft_swap(lst1, 'a');
		ft_rotate(lst1, 'a');
	}
	else if (temp1 > temp2 && temp1 < temp3)
		ft_swap(lst1, 'a');
	else if (temp1 < temp2 && temp1 > temp3)
		ft_rev_rotate(lst1, 'a');
	else if (temp1 > temp2 && temp2 < temp3)
		ft_rotate(lst1, 'a');
	else if (temp1 > temp2 && temp2 > temp3)
	{
		ft_swap(lst1, 'a');
		ft_rev_rotate(lst1, 'a');
	}
}

void	sort5(t_l **lst1, t_l **lst2, int size)
{
	if (checker(lst1, lst2, size))
		return ;
	ft_push(lst1, lst2, 'b');
	ft_push(lst1, lst2, 'b');
	sort3(lst1);
	push_back(lst1, lst2, 5);
}

void	sort4(t_l **lst1, t_l **lst2, int size)
{
	if (checker(lst1, lst2, size))
		return ;
	ft_push(lst1, lst2, 'b');
	sort3(lst1);
	push_back(lst1, lst2, 4);
}
