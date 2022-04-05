/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:09:20 by asibille          #+#    #+#             */
/*   Updated: 2022/01/10 14:43:31 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *lst;
	if (lst != NULL && del != NULL)
	{
		while (ptr != NULL)
		{
			temp = ptr->next;
			ft_lstdelone(ptr, del);
			ptr = temp;
		}
		*lst = NULL;
	}
}
