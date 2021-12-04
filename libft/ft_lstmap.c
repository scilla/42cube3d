/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:16:45 by scilla            #+#    #+#             */
/*   Updated: 2021/01/23 20:25:44 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	void	*ptr;

	if (!lst)
		return (0);
	res = 0;
	while (lst)
	{
		if (!(ptr = (*f)(lst->content)))
		{
			ft_lstclear(&res, (*del));
			return (0);
		}
		if (!(tmp = ft_lstnew(ptr)))
		{
			ft_lstclear(&res, (*del));
			return (0);
		}
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}
