/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:03:39 by asibille          #+#    #+#             */
/*   Updated: 2022/01/11 13:41:50 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*temp;

	ptr = NULL;
	if (f)
	{
		while (lst)
		{
			temp = ft_lstnew((*f)(lst->content));
			if (!temp)
			{
				ft_lstclear(&ptr, del);
				return (NULL);
			}
			ft_lstadd_back(&ptr, temp);
			lst = lst->next;
		}
	}
	return (ptr);
}
