/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:33:43 by efischer          #+#    #+#             */
/*   Updated: 2019/09/20 11:58:14 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select(t_list *lst, t_machine *machine)
{
	static t_state_fct	*fct[NB_FCT] = { st_input, st_print, st_err, st_end };

	(fct[machine->state])(lst, machine);
}
