/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleschev <mleschev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:49:45 by mleschev          #+#    #+#             */
/*   Updated: 2025/09/22 14:50:16 by mleschev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	init_lst(t_list **head, void *ptr)
{
	t_list	*current;
	current = malloc(sizeof(t_list));
	current->next = NULL;
	current->content = ptr;
	*head = current;
}

void ft_lst_malloc(t_list **head, t_list *new)
{
	t_list *current;

	current = *head;
	if (!head)
		return ;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	make_malloc(void *ptr, t_list **head)
{
	t_list	*new;
	t_list	*last;

	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->content = ptr;
	new->next = NULL;
	last = lst_last(head);
	last->next = new;
}

void *lst_last(t_list **head)
{
	t_list *current;

	current = *head;
	while (current->next)
		current = current->next;
	return (current);
}
