/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:46:21 by mleschev          #+#    #+#             */
/*   Updated: 2025/09/22 14:50:26 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_malloc(size_t size, int exit)
{
	static t_list	*list = NULL;
	void	*result;

	if (exit == 1)
	{
		delete_all(&list);
		return (NULL);
	}
	if (!list)
	{
		result = malloc(size);
		init_lst(&list, result);
		return (result);
	}
	result = malloc(size);
	make_malloc(result, &list);
	return (result);
}

void delete_all(t_list **head)
{
	t_list *aled;
	t_list	*current;
	t_list	*last;

	aled = *head;
	while (aled->next)
	{
		current = aled;
		while (current->next)
		{
			if (current->next->next == NULL)
			{
				last = current->next;
				current->next = NULL;
				break ;
			}
			current = current->next;
		}
		free(last->content);
		free(last);
	}
	free(aled->content);
	free(aled);
}
