/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:48:44 by asibille          #+#    #+#             */
/*   Updated: 2022/01/10 15:32:52 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (new != NULL && alst != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			ptr = ft_lstlast(*alst);
			ptr->next = new;
		}		
	}
}
