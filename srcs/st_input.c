/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:31:36 by efischer          #+#    #+#             */
/*   Updated: 2019/09/20 11:58:57 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	st_input(t_list *lst, t_machine *machine)
{
	static t_key_fct	*fct[NB_KEY] = { curs_up, curs_down, curs_right,
										curs_left, quit, select_elem, return_elem };
	static char			*key_tab[NB_KEY] = { K_UP, K_DOWN, K_RIGHT, K_LEFT,
											K_ESC, K_SPACE, K_RET };
	static t_list		*curs = NULL;
	char				buf[READ_SIZE];
	ssize_t				ret;
	int					i;

	i = 0;
	if (curs == NULL)
		curs = lst;
	if ((ret = read(0, buf, READ_SIZE)) >= 0)
		buf[ret] = '\0';
	x_y_elem(lst, machine);
	while (i < NB_KEY)
	{
		if (ft_strequ(buf, key_tab[i]) == TRUE)
			break ;
		i++;
	}
	if (i < NB_KEY)
	{
		machine->state = ST_PRINT;
		(fct[i])(lst, &curs, machine);
	}
	ft_select(lst, machine);
}
