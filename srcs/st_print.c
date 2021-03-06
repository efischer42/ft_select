/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:43:44 by efischer          #+#    #+#             */
/*   Updated: 2019/10/08 11:20:41 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	*apply_flag(t_select *elem)
{
	static t_termcap	termcap;
	char				*str;
	char				*tmp;

	get_termcap(&termcap);
	str = ft_strdup(elem->arg);
	if ((elem->flag & F_SO) == F_SO)
	{
		tmp = str;
		str = ft_asprintf("%s%s%s", termcap.so, tmp, termcap.me);
		ft_strdel(&tmp);
	}
	if ((elem->flag & F_US) == F_US)
	{
		tmp = str;
		str = ft_asprintf("%s%s%s", termcap.us, tmp, termcap.me);
		ft_strdel(&tmp);
	}
	return (str);
}

void	column_display(t_list *lst)
{
	char	*str;

	cl_screen();
	while (lst != NULL)
	{
		str = apply_flag(lst->content);
		ft_putendl(str);
		lst = lst->next;
	}
}

void	st_print(t_list *lst, t_machine *machine)
{
	column_display(lst);
	machine->state = ST_INPUT;
	ft_select(lst, machine);
}
